using System;
using System.IO;
namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                StreamWriter sw = new StreamWriter(@"work.txt");
                sw.WriteLine("Hello bro!");
                sw.Close();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
           
        }
    }
}
