using System;
using System.IO;
using System.Text;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            FileStream fs = new FileStream(@"B:\immortalthings\immortaltutorialsandprojects\c#\revision\day2\streamprojectseries\Project1\ConsoleApp1\TextFile\work.txt", FileMode.Create);
            string b = "Hello";
            byte[] buffer = Encoding.ASCII.GetBytes(b);
            try
            {
                fs.Write(buffer,0,buffer.Length);
            }
            catch 
            {
                Console.WriteLine("error!");
            }
            finally
            {
                fs.Close();
            }
        }
    }
}
