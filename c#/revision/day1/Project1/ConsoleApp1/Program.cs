using System;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start my revision");
            // variable initialization:
            int a = 1;
            Console.WriteLine(a);
            string b = "Bronstein";
            Console.WriteLine(b);
            //loop iteration:
            for (int i = 0; i <= 10; i++)
            {
                Console.WriteLine(i);
            }
            //control flow:
            a++;
            if (a == 1)
            {
                Console.WriteLine("a is equivalent to 1");
            }
            else
            {
                Console.WriteLine("nothing!");
            }
            //array:
            int []m = new int[10]; // m is an array containing up to 10 int-typed elements
                                   //index of an array starts from 0 to (the length of elements-1)
            m[0] = 0;
            m[1] = 1;
            m[9] = 10;
            Console.WriteLine(m);
            // m is an array, so if we want to write all elements of the array, we need to iterate through index:>>
            Console.WriteLine(m[3]);
        }
    }
}
