using System;
using System.Text;
using System.Collections.Generic;
namespace ep11_catalan{
    public class Program{
        static int[] a = new int[1000];
        public static int Catalan(int n){
            a[0]=1;
            a[1]=1;
            for (int i=2;i<=n;i++){
                for (int j=0;j<i;j++){
                    a[i] +=a[j]*a[i-1-j];
                }
            }
            return a[n];
        }
        public static void Main(string[] args){
            Console.WriteLine(Catalan(Convert.ToInt32(args[0])));
        }
    }
}