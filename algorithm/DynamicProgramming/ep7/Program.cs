using System;
using System.Text;
using System.Collections.Generic;
namespace ep7{
    public class Program{
        static int [,]dp = new int[1000,1000];
        public static int solve(string a, string b){
            for(int i=0;i<=a.Length;i++){
                for (int j=0;j<=b.Length;j++){
                    if((i==0)||(j==0)){
                        if(i==0) dp[i,j] = j;
                        if(j==0) dp[i,j] = i;
                    }
                    else{
                        if(a[i-1]==b[j-1]){
                            dp[i,j] = dp[i-1,j-1];
                        }
                        else{
                            dp[i,j] = 1+Math.Min(Math.Min(dp[i-1,j-1],dp[i-1,j]),dp[i,j-1]);
                        }
                    }
                }
            }
            return dp[a.Length,b.Length];
        }
        public static void Main(string[] args){
            
            Console.WriteLine(solve("sunday","saturday"));
            
        } 
    }
}