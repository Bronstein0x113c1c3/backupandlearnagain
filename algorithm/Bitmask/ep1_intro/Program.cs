using System;
using System.Collections.Generic;
using System;
namespace intro_to_bitmask{
    public class Program{
        static void Main(){
            int []x = new int[]{2,3,5};
            for(int i=0;i<(1<<(x.Length));i++){
                for (int j=0;j<x.Length;j++){
                    if((i&(1<<j))>0){
                        Console.Write("{0} ",x[j]);
                    }
                }
                Console.WriteLine();
            }

        }
    }
}