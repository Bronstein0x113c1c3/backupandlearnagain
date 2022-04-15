using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Server
{
    internal class Program
    {
        static void Main(string[] args)
        {
            byte[] recv = new byte[1024];
            int bytereceived = 0;

            Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPHostEntry iphost = Dns.GetHostEntry(Dns.GetHostName());
            server.Bind(new IPEndPoint(iphost.AddressList[iphost.AddressList.Length - 1], 8080));
            server.Listen(20);
            using var clientsocket = server.Accept();
            if (clientsocket.Connected)
            {
                while (true)
                {
                    bytereceived = clientsocket.Receive(recv);
                    Console.Write(Encoding.ASCII.GetString(recv, 0, bytereceived));
                }
            }
            
        }
    }
}
