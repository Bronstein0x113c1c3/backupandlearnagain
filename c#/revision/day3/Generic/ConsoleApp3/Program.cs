using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
namespace ConsoleApp3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"test.txt");
            List<string> list = new List<string>();
            while (!sr.EndOfStream)
            {
                foreach (string phrase in sr.ReadLine().Split(' ')) 
                {
                    list.Add(phrase);
                }
            }
            sr.Close();
            List<string>.Enumerator em = list.GetEnumerator();
            while (em.MoveNext())
            {
                Console.Write(em.Current.ToString()+" ");
            }
        }
    }
}
