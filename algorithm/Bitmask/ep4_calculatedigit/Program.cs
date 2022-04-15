using System;
using System.Text;

namespace ep4_calculatedigit{
    public class Program{
        public static int [,]dp = new int[1025,10];
        public static int fullmask = (1<<4)-1;
        public static int calculate(int mask,int number,int pos){
        if (number>9) return 0;
        else{
            if (mask==fullmask) return 1;
             else{
                if(dp[mask,number]!=-1) return dp[mask,number];
                else{
                    int x = 0;
                    for (int i=0;i<5;i++){
                    x+=calculate(mask|(1<<pos),i,pos+1);
                    }
                    return x;
            }
        }
        }
        }
        public static void Main(string[] args){
            for (int i=0;i<1025;i++){
                for (int j=0;j<10;j++){
                    dp[i,j] = -1;
                }
            }
            Console.WriteLine(calculate(0,0,0));





        }
    }
}