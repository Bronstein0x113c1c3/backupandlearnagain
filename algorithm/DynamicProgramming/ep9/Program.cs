// solve fibonacci using memoization
using System;
using System.Text;
using System.Collections.Generic;
namespace ep9_Memoization{
    public class Program{
        public static int[] dp = new int[1001];
        public static int fibonacci(int n){
            if (n<=2){
                 return 1;
            }
            else{
                if (dp[n]!=-1){ return dp[n];}
                else{
                    int fib1 = 0;
                    int fib2 = 0;
                    fib1 = fibonacci(n-1);
                    fib2 = fibonacci(n-2);
                    dp[n] = fib1+fib2;
                    return dp[n];
                }
            }
        }
        public static void Main(){
            for (int count = 1 ; count < dp.Length ; count++){
                dp[count] = -1;
            }
            Console.WriteLine(fibonacci(7));

        }
    }
}