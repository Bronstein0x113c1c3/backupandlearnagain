using System;

namespace filling{
    public class Program{
        static void Main(){
            int n = Convert.ToInt32(Console.ReadLine());
            int[] dp = new int[61];
            dp[0] = 1;
            dp[1] = 0;
            for (int i = 2;i<=n;i++){
                dp[i] = dp[i-2]<<1;
            }
            Console.WriteLine(dp[n]);
        }
    }
}