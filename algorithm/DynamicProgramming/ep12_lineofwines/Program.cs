//using tabulation after pre-testing, instead of recursion or memoization with more efficient method
using System;
using System.Collections.Generic;
using System.Text;

namespace ep12_lineofwines{
    public class Program
    {
        static int [,]dp = new int [1000,1000];
        public static void Main(string[] args){
        int []arr = Array.ConvertAll(args,Int32.Parse);
        for(int i=0;i<arr.Length;i++){
            dp[i,i] = arr[i];
        }
        for (int right = 0;right<arr.Length;right++){
            for (int left = right;left>=0;left--){
                if (right==0){
                    dp[left,right] = arr[0];
                    break;
                }
                else{
                dp[left,right] = Math.Max(dp[left+1,right]+(arr.Length-right+left)*arr[left], dp[left,right-1]+(arr.Length-right+left)*arr[right]);}
            }
        }
        Console.WriteLine("{0} ",dp[0,arr.Length-1]);

        }
    }
}