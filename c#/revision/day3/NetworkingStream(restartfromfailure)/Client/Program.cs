using System;
using System.Text;
using System.Net.Sockets;
using System.Net;
namespace Client
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Socket client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            client.Connect(new IPEndPoint(IPAddress.Parse("192.168.100.17"), 8080));
            while (true)
            {
                string s = Console.ReadLine();
                client.Send(Encoding.ASCII.GetBytes(s));
            }
        }
    }
}
