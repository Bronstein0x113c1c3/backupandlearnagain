using System;
using System.Collections.Generic;
namespace ConsoleApp2
{
    internal class Program
    {
        
        static void Main(string[] args)
        {
            LinkedList<int> linkedlist = new LinkedList<int>();
            linkedlist.AddLast(1);
            linkedlist.AddLast(2);
            linkedlist.AddLast(3);

            LinkedList<int>.Enumerator em = linkedlist.GetEnumerator();
            while (em.MoveNext())
            {
                
                Console.WriteLine(em.Current);
            }
            
        }
    }
}
