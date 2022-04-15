using System;
using System.Collections.Generic;
using System.Text;
namespace ep5{
    public class Program{


        //3 states work asychronously 
        public static int solve(int []a){
            int hold = -a[0];
            int sold = 0;
            int cool = 0;
            for (int i=1;i<a.Length;i++){
                 int lastsold = sold;
                hold = Math.Max(hold,cool-a[i]);
                cool = Math.Max(cool,lastsold);
                sold = hold+a[i];
                
            }
        return Math.Max(cool,sold);
        }
        public static void Main(string[] args){
            int []trade = new int[]{1};
            Console.WriteLine(solve(trade));
        }
    }
}