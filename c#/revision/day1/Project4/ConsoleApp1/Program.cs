using System;
using System.Text.RegularExpressions;
namespace ConsoleApp1
{
    internal class Program
    {
        
        static void Main(string[] args)
        {
            Regex test = new Regex(@"\d+.\d+.\d+.\d+");
            foreach( Match item in test.Matches(@"192.168.1.1"))
            {
                Console.WriteLine(item.ToString());
            };
           
        }
    }
}
