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
