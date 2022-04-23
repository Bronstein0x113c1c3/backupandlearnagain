# Google Assistant - hành trình của gRPC
Bài viết này dựa trên rất nhiều project khác nhau và đây là 1 số nguồn uy tín:
- [ac87/GoogleAssistantWindows](https://github.com/ac87/GoogleAssistantWindows)
- [wolfviking0/google-assistant-csharp-demo](https://github.com/wolfviking0/google-assistant-csharp-demo)
- [Samples của Google](https://github.com/googlesamples)
- [Google Assistant Unofficial Desktop Client](https://github.com/Melvin-Abraham/Google-Assistant-Unofficial-Desktop-Client)
## **1. Ý tưởng đằng sau**
Từ một bài viết nọ trên [Tinh Tế](https://tinhte.vn/thread/huong-dan-cai-google-assistant-tren-windows-10-don-gian.2963158/page-5) của Thangvip9x, khi đó tôi bắt đầu được khai sáng về chị trợ lý ảo đặc biệt này. Toàn bộ chúng đều được viết bằng Python và cách setup cũng khá đơn giản khi chỉ cần nhập lệnh rồi cứ thế làm theo. Vâng, với những người không hiểu bản chất thì việc làm máy móc như vậy cũng khá nhanh và đơn giản. Nhưng, phải đến khi gặp lỗi liên tục mới thấm đòn, rằng cứ đọc báo như này không nghiên cứu thì chết, cuối cùng tôi tự mò trên trang của [Google](https://developers.google.com/assistant/sdk/overview) nói về API này. Từ đó, tôi bắt đầu tiếp cận cái API giống như một đề tài mà mình cần phải viết. Cũng nên nhớ rằng vào ngày 6 tháng 5 năm 2019 thì Google mới ra mắt chính thức Google Assitant này, cho nên toàn bộ công nghệ của nó đều chưa bao giờ lỗi thời. Để tìm hiểu sâu hơn, tôi có tham khảo một loạt các project khác ngoài bài viết siêu đơn giản của Tinh Tế, bao gồm hai projects viết bằng C#, NodeJS (ElectronJS), Python, C++,...Thời điểm năm 2020 thì tôi đã tích trữ kha khá project liên quan đến API và tất cả đều khởi nguồn từ Assistant nàỳ. Tuy vậy, làm cái này cũng gây không ít những sự khó chịu, một trong số đó là hiện tượng thiếu RAM và lỗi xác thực liên tục đã khiến tôi gần như muốn bỏ cuộc. Và khi tôi bắt đầu học đại học và muốn kiếm điều gì đó để học lại code từ đầu, lấy lại khả năng làm việc, thì tôi chọn project này như là một cách để sửa chữa mình và khám phá thêm điều mới. Và, đó là toàn bộ ý tưởng.
## **2. Phân tích**
Quá trình thiết lập của nó gồm 3 giải đoạn chính: \
**1**. Xác thực, lấy token để có cửa vào API (sử dụng OAuth và Bearer Token) \
**2**. Kiểm tra và đăng kí thiết bị (Sử dụng Request thường và hai đoạn JSON: Device Instance và Device Model) \
**3**. Sử dụng Assistant và kiểm tra lại token.

Giữa mỗi bước đều có file chương trình chính liên kết các bước lại với nhau, khiến cho các bước trở nên mạch lạc với nhau hơn, nhưng trên thực tế là tôi lược bỏ vài bước vì do máy làm bị thiếu RAM và chính việc thêm thắt toàn bộ chức năng kia sẽ khiến chương trình bị dài ra và rối.
Đây là cấu trúc của toàn bộ project
***
- ConsoleApp1
    - bin (thư mục chứa các file debug)
    - obj
    - google(thư mục chứa API gRPC của Google)
        - assistant
            - EmbeddedAssistant.cs
            - EmbeddedAssistantGrpc.cs
        - googleapis
            - Annotations.cs
            - Http.cs
            - Latlng.cs
            - Status.cs
    - **Assistant.cs** (giai đoạn 2 và 3)
    - **Authentication.cs** (giai đoạn 1)
    - ConsoleApp1.csproj 
    - ConsoleApp1.sln
    - **Program.cs** (chương trình chính)
***
#### **1. Giai đoạn 1: Xác thực**
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using Google.Apis.Auth.OAuth2;
using Google.Apis.Auth.OAuth2.Flows;
using Google.Apis.Auth.OAuth2.Responses;

using Google.Apis.Util.Store;

namespace ConsoleApp1.AuthenticationForAssistant
{
    internal class Authentication
    {
        public GoogleAuthorizationCodeFlow authorization_flow;
        public UserCredential UserCredential { get; set; }
        public string clientID { get; set; }
        public string clientSecret { get; set; }
        public Authentication(string clientID, string clientSecret)
        {
            this.clientID = clientID;
            this.clientSecret = clientSecret;
        }
        public async Task<UserCredential> GetTokenInfo()
        {
           var UserCredential = await GoogleWebAuthorizationBroker.AuthorizeAsync(
                new ClientSecrets
                {
                    ClientId = clientID,
                    ClientSecret = clientSecret
                },
                new string[] {"https://www.googleapis.com/auth/assistant-sdk-prototype"},
                "user",
                CancellationToken.None,
                null
            );
            authorization_flow = new GoogleAuthorizationCodeFlow(new GoogleAuthorizationCodeFlow.Initializer()
            {
                ClientSecrets = new ClientSecrets()
                {
                    ClientId = clientID,
                    ClientSecret = clientSecret
                }
            });
            return UserCredential;
        }
        public TokenResponse tokenresponse(UserCredential credentialinfo)
        {
            return new TokenResponse()
            {
                AccessToken = credentialinfo.Token.AccessToken,
                ExpiresInSeconds = credentialinfo.Token.ExpiresInSeconds,
                RefreshToken = credentialinfo.Token.RefreshToken,
                Scope = "https://www.googleapis.com/auth/assistant-sdk-prototype",
                TokenType = credentialinfo.Token.TokenType
            };
        }
        public UserCredential credential(GoogleAuthorizationCodeFlow flow, string user, TokenResponse tokenresponse)
        {
            return new UserCredential(flow, "", tokenresponse);
        }
    }
}
```
**1**. Khi bắt đầu quá trình xác thực, cần phải tạo ra một lớp trong đó có hai giá trị khởi đầu là **clientID** và **clientSecret**, cả hai đều có trong project khi chúng ta thiết lập tại [Google Cloud Console](console.cloud.google.com).\
**2**. Chúng ta sẽ phải tìm cách lấy Token để access vào API hoặc là xác thực lại token khi quá hạn. Ở đây ta sử dụng OAuth2 API riêng của Google, trong đó có hai giá trị mà chúng ta có ở B1, một cái scope nhằm xác thực, user identifier và cuối cùng là một CancellationToken để hủy (thực ra không thể hủy được vì nếu vậy làm sao lấy được Token). Thông tin được trả về là thông tin **xác thực** bao gồm các Token như AccessToken, RefreshToken,...
#### **2. Sử dụng Assistant (lược bỏ bước đăng kí thiết bị)**
```
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
```
**1**. Tại bước "tạo ra" một chị trợ lý ảo  và "cấp phép" cho chị ấy hoạt động, ta cần có thông tin của người chủ sử dụng thì khi đấy, chúng ta phải tạo ra một kênh kết nối với "bố" của chị ấy, tức là bác Sundar Pichai :). Tức là khi có thông tin xác thực, ta sẽ tạo ra một **Channel** gRPC để kết nối với API Endpoint chuyên xử lý các request gRPC từ phía client. Ta đặt endpoint là (embeddedassistant.googleapis.com), cổng 443 và thông tin được xác thực phải về dạng ChannelCredential (thư viện Grpc.Auth lo hết :) ). Khi tạo xong một kênh thì sử dụng kênh đó để trao đổi thông tin bằng việc tạo ra "cô chị xinh đẹp" của chúng ta, tức là tạo class **Assistant** và trao đổi thông qua channel đó. Tại đây thì tôi đã đặt kiểm tra xem có thành công hay không, nếu không thành công thì toàn bộ quá trình xác thực bị lỗi và khiến cho chương trình không thể chạy được.\
**2**. Khi quá trình này thành công, thì các thông tin sẽ đi qua, bao gồm có hai dạng là thoại và nhập liệu. Riêng cái nhập liệu thì mặc dầu dễ làm nhưng mà có khá nhiều hạn chế do không thể biểu đạt được bằng dạng string bình thường và ở dạng thoại thì còn khó gấp bội. Cả hai đều được gói lại bằng byte và được trao đổi trong một gói tin là **AssistConfig**, nó bao gồm các thiết lập thông tin về thiết bị, cách chúng ta truy vấn và output.\
**3**. Cuối cùng là điều chế lại thông tin trả về tại void **OnNext**. Tại đó chúng ta sẽ kiểm tra các thuộc tính như voice(**AudioOut**), text(**DialogStateOut.SupplementalDisplayText**). Trong trường hợp test thiết bị IoT thì có thêm cả  **DebugInfo** và **DeviceAction**. \
Các bước được liên kết tới nhau ở file **Program.cs**
```
using System;
using ConsoleApp1.AuthenticationForAssistant;
using ConsoleApp1.Main;
using System.Threading;
using System.Threading.Tasks;
using Google.Apis.Auth.OAuth2;
using Google.Apis.Auth.OAuth2.Flows;
using Google.Apis.Auth.OAuth2.Responses;
using NAudio.Wave;
using System.IO;
namespace ConsoleApp1
{
    internal class Program
    {
        private static UserCredential credentialforlateruse;
        static async Task Initialzing()
        {
            string clientId = "193057948258-jua32cqvrvue9ntc63vj8kvg4jmjmsmc.apps.googleusercontent.com";
            string clientSecret = "C6D1gn9Jt2AXGFzhCKHSRBfB";
            Authentication authentication = new Authentication(clientId, clientSecret);
            var TokenInfo = await authentication.GetTokenInfo();
            var TokenResponse = authentication.tokenresponse(TokenInfo);
            var usercredential = authentication.credential(authentication.authorization_flow, "", TokenResponse);
            credentialforlateruse = usercredential;
        }
        static async Task Main(string[] args)
        {
            await Initialzing(); //-> B1: Tạo ra một UserCredential 
            Assistant assistant = new Assistant(credentialforlateruse); // Mì ăn liên mode, bỏ qua bước đăng kí thiết bị
            string query = "";
            while (query != "quit")
            {
                Console.Write("Query: ");
                query = Console.ReadLine();
                assistant.TextRequestAssistant(query).Wait();
                if (assistant.GetTextResp() != null)
                {
                    Console.Write("Answer: ");
                    Console.WriteLine(assistant.GetTextResp());
                }
                else
                {
                    Console.WriteLine("No answer or answer can't be described");
                }
                
            }
        }
    }
}
```
## **3. Trả lời các thắc mắc**
1. Tại sao không có bước 2 mà chơi mì ăn liền mode? \
    **Lý do cực kì đơn giản**: Đăng kí thiết bị khiến code dài ra và tốn sức sửa chữa, trong khi đó mình có hai thiết bị đăng kí rồi, trong nhiều trường hợp, nếu muốn tự động hóa cái này thì có thể xem tại trang SDK mà mình để ở phần 1. Khi đó ở C# thì chúng ta phải biến tấu file đó thành file JSON rồi đăng kí với thư viện Newtonsoft.JSON. Cái khiến mình không thực sự muốn làm vậy là mình liên tục gặp lỗi khi chạy thử, dẫn đến mình tự đăng kí chay luôn, mấy bố thích thì tự code một cái cũng được, có tham khảo đàng hoàng luôn.
    
2.  Ý tưởng có rồi, vậy câu chuyện mà anh muốn kể là gì? \
    **Trả lời**: Mình có viết riêng một chuyên mục về gRPC mà mới chỉ ở bước đầu là phân tích RESTful API và mới chỉ sơ qua cái gRPC như nào, sau lần này thì mình sẽ viết nhiều hơn.
    
3.  Mất bao nhiêu thời gian để làm cái này? \
    **Trả lời**: 2 ngày để nghiên cứu và viết lược đồ, thêm cả tham khảo các projects khác của những tiền bối đi trước.
    
4. Trải nghiệm nó như nào khi anh viết xong? \
    **Trả lời**: Đỡ chán nản hơn trong khoảng thời gian kiểm tra dồn này, ít nhất là lấy lại niềm tin đã mất. Thêm nữa là mình còn phải thi IELTS và học thật tập trung nên cái trải nghiệm này dạy mình tính kiên nhẫn, nỗ lực và tối ưu thời gian.
    
5. Anh có định phát triển tiếp không? \
    **Trả lời**: Yeb! \
    
6.Anh có tính mời mọi người đọc cái này không? \
    **Trả lời**: Dĩ nhiên thằng bạn mình sẽ xem cái này đầu tiên, leader và cả anh em ở BTDev nữa. Đã từng hé lộ trên Facebook rồi nhưng không ai để ý, nên là mình cũng sẽ không sử dụng nó cho các bài viết chuyên sâu. Dù sao thì, người quan tâm thì đọc nó, còn người khác thì chả quan tâm làm gì, mình đang học đúng chuyên ngành của mình cơ mà :)).

**Và đó là toàn bộ dự án đầu tiên của mình sau 2 ngày mò mẫm** \
**Written by BronsteinofTROYCS20**
