using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Google.Assistant.Embedded.V1Alpha2;
using Google.Apis.Auth.OAuth2;
using Google.Apis.Auth.OAuth2.Flows;
using Google.Apis.Auth.OAuth2.Responses;
using Grpc.Core;
using Grpc.Auth;
using Google.Protobuf;
using System.Threading;
using ConsoleApp1.AuthenticationForAssistant;
using System.IO;

namespace ConsoleApp1.Main
{
    internal class Assistant
    {
        private List<byte> currentAudioResponse = new List<byte>();
        private Channel channel;
        private EmbeddedAssistant.EmbeddedAssistantClient embeddedAssistant;
        IClientStreamWriter<AssistRequest> requestStream;
        IAsyncStreamReader<AssistResponse> responseStream;
        private ByteString currentConversationState = ByteString.Empty;
        private string currentTextResponse;
        public Assistant(UserCredential credential)
        {
            channel = new Channel("embeddedassistant.googleapis.com", 443, credential.ToChannelCredentials());
            embeddedAssistant = new EmbeddedAssistant.EmbeddedAssistantClient(channel);
            if (embeddedAssistant == null)
            {
                Console.WriteLine("failed");
            }
            else
            {
                Console.WriteLine("Success");
            }

        }
        public async Task TextRequestAssistant(string request)
        {
            AsyncDuplexStreamingCall<AssistRequest, AssistResponse> assist = embeddedAssistant.Assist();
            requestStream = assist.RequestStream;
            responseStream = assist.ResponseStream;
            currentAudioResponse.Clear();
            currentTextResponse = "";
            await requestStream.WriteAsync(GetConfigRequest(request));
            await requestStream.CompleteAsync();
            await WaitForResponse();
        }
        private async Task WaitForResponse()
        {
            var response = await responseStream.MoveNext();
            if (response)
            {
                AssistResponse currentResp = responseStream.Current;
                OnNext(currentResp);
                await WaitForResponse();
            }
        }
        private void OnNext(AssistResponse value)
        {
            if (value.AudioOut != null)
            {
                
                using (MemoryStream stream = new MemoryStream())
                {
                    using (BinaryWriter writer = new BinaryWriter(stream))
                    {
                        writer.Write(value.AudioOut.AudioData.ToByteArray());
                    }
                    currentAudioResponse.AddRange(stream.ToArray());
                }
            }
            if (value.DialogStateOut != null)
            {
                currentConversationState = value.DialogStateOut.ConversationState;
                if (!string.IsNullOrEmpty(value.DialogStateOut.SupplementalDisplayText))
                {
                    currentTextResponse = value.DialogStateOut.SupplementalDisplayText;
                }
            }
            if (value.ScreenOut != null)
            {
                Console.WriteLine(value.SpeechResults);
            }
        }
        public string GetTextResp()
        {
            return currentTextResponse;
        }
        public byte[] GetAudioResponse()
        {
            return currentAudioResponse.ToArray();
        }
        public AssistRequest GetConfigRequest(string query)
        {
            var audioInConfig = new AudioInConfig()
            {
                SampleRateHertz = 16000,
                Encoding = AudioInConfig.Types.Encoding.Linear16
            };
            var audioOutConfig = new AudioOutConfig()
            {
                SampleRateHertz = 16000,
                Encoding = AudioOutConfig.Types.Encoding.Linear16,
                VolumePercentage = 100
            };
            var dialogStateInConfig = new DialogStateIn()
            {
                LanguageCode = "en-US",
                ConversationState = currentConversationState
            };
            var deviceConfig = new DeviceConfig()
            {
                DeviceModelId = "Inspiron7610",
                DeviceId = "mynewlaptop"
            };
            var assistConfig = new AssistConfig()
            {
                AudioInConfig = audioInConfig,
                AudioOutConfig = audioOutConfig,
                DeviceConfig = deviceConfig,
                DialogStateIn = dialogStateInConfig,
                TextQuery = query
            };
            return new AssistRequest()
            {
                Config = assistConfig
            };

        }

    }
}
