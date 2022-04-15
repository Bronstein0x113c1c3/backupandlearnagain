using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    internal class Program
    {   
        enum Option
        {
            Hello,
            Goodbye
        }
        static void Main(string[] args)
        {
            int a = Convert.ToInt32(Console.ReadLine());
            if ((Option)a == Option.Hello)
            {
                Console.WriteLine("Hello");
            }
            else
            {
                if ((Option)a == Option.Goodbye)
                {
                    Console.WriteLine("Goodbye");
                }
                else Console.WriteLine("Nothing!");
                        
            }
        }
    }
}
