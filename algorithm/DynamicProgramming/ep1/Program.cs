using System;
using System.Collections.Generic;
using System.Linq;

namespace MyApp // Note: actual namespace depends on the project name.
{
    public class Program
    {
        public static void Main(string[] args)
        {
           int [,]a = new int[1000,1000];
           int m = Convert.ToInt32(Console.ReadLine());
           int n = Convert.ToInt32(Console.ReadLine());
           for (int i = 0; i<=m;i++){
               for ( int j = 0 ; j <=n; j++){
                   if(i==0||j==0){
                        a[i,j]=1;
                   }
                   else{
                       a[i,j]=a[i-1,j]+a[i,j-1];
                   }
               }
           }
           Console.WriteLine(a[m,n]);
        }
    }
}