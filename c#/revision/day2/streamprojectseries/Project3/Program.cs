using System;
using System.IO;
using System.Net.Sockets;
namespace project3{
    class Program{
        public static void Main(string []args){
            StreamWriter sw = new StreamWriter(@"work.txt");
            sw.WriteLine("Hello bro!");
            sw.Close();
        }
    }
}