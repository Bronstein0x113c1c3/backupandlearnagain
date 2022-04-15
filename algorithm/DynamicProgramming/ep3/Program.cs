using System;
using System.Collections.Generic;
using System.Linq;

namespace MyApp // Note: actual namespace depends on the project name.
{
    public class Program{

        static int[]min = new int[1000];
        static int[]cost = new int[1000];
    public static int solve (int []cost)
    {   
        min[0]=0;
        min[1]=0;
        for (int i=2;i<=cost.Length;i++){
            min[i] = Math.Min(min[i-1]+cost[i-1],min[i-2]+cost[i-2]);
        }
        return min[cost.Length];
    }
        public static void Main(string[] args)
        {
        cost = new int[] {1,100,1,1,1,100,1,1,100,1};
        Console.WriteLine(solve(cost));            
            
         
        }
        
    }
}