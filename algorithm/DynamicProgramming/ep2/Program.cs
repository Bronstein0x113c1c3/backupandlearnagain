using System;
using System.Collections.Generic;
using System.Linq;

namespace MyApp // Note: actual namespace depends on the project name.
{
    public class Program
    {
        static Dictionary<int, bool>memo = new Dictionary<int, bool>();
        public static bool CanSum(int x,int []a, Dictionary<int, bool> mem){
                if(x<0) return false;
                if (x==0) return true;
                else{
                    if (mem.Keys.Contains(x)){
                        return mem[x];
                    }
                    else{
                        foreach (int num in a){
                        int remainder = x - num;
                        if(CanSum(remainder,a,memo)==true){
                            memo[x]=true;
                            return true;
                            break;
                        }
                        }
                        memo[x]=false;
                        return false;
                    }
                }
        }
        
        public static void Main(string[] args)
        {

          int []a = new int[4]{2,3,5,7};
          Console.WriteLine(CanSum(12,a,memo));
          Console.WriteLine(memo[10]);
        }
        
    }
}