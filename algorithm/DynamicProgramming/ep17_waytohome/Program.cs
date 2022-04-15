using System;
namespace ep17_waytohome{
    class Program{
        static void Main(string[] args){ 
            int n = Convert.ToInt32(args[0]);
            int d = Convert.ToInt32(args[1]);
            string seq = args[2];
            int[] dp = new int[seq.Length];
            for (int i=1;i<seq.Length;i++){
                dp[i] = 32768;
            }
            for (int i =0;i<seq.Length;i++){
                for (int j = 1;j<=d;j++){
                    if ((i>=j)&&(seq[i]!='0')&&(seq[i-j]!='0')){
                        dp[i] = Math.Min(dp[i],dp[i-j]+1);
                    }
                }
            }

           for (int i = 0;i<seq.Length;i++){
               Console.WriteLine($"{dp[i]}");
           }
}
    }
}