using System;
using System.Text;
using System.Collections.Generic;
namespace ep6{
    public class Program{
        public static int solve(int[] a){
           int []dp = new int[a.Length];
           int []dptmp = new int[a.Length];
           int max = 0;
            int neg=0;

            if(a[0]<0) {
                dp[0]=0;
                dptmp[0]=1;
                neg=1;
            }
            if(a[0]==0){
                dp[0]=0;
                dptmp[0]=0;
                neg=0;
            }
            if(a[0]>0){
                dp[0]=1;
                dptmp[0]=1;
                neg=0;
            }


           for (int i=1;i<a.Length;i++){
               if (a[i]>0){
                   dp[i] = dp[i-1]+1;
                   dptmp[i]=dptmp[i-1]+1;
               }
                if(a[i]==0){
                    dp[i]=0;
                    dptmp[i]=0;
                }
                if(a[i]<0){
                    neg++;
                    dp[i]=0;
                    dptmp[i] = dptmp[i-1]+1;
                    if(neg%2==0){
                        dp[i] = dptmp[i];
                    }
                }
            max = Math.Max(max,dp[i]);


           }
           return max;
        }
     public static void Main(string[] args){
            int []a = new int[]{1,2,-7,8,3,9,5,4};
            Console.WriteLine(solve(a));
          }
        }
    
}