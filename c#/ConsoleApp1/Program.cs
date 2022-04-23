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
            await Initialzing();
            Assistant assistant = new Assistant(credentialforlateruse);
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
