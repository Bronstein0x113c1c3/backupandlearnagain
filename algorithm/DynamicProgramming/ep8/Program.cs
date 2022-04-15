// coin problem
using System;
using System.Text;
using System.Collections.Generic;
namespace ep8{
    public class Program{
        static int []min = new int[1000];
        static int []coins = new int[]{1,3,5};
        public static void Main (string[] args){
            for (int i=0;i<min.Length;i++){
                min[i] = 9999;
            }
            min[0] = 0;
            int maxcoin = Convert.ToInt32(args[0]);
            for(int i = 0; i <= maxcoin; i++){
                foreach(int coin in coins){
                    if (i>=coin){
                        min[i] = Math.Min(min[i],1+min[i-coin]);
                    }
                }
            }
            Console.WriteLine(min[maxcoin]);
        }
    }
}