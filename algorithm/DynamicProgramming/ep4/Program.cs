using System;
using System.Collections.Generic;
using System.Linq;

namespace MyApp // Note: actual namespace depends on the project name.
{
    
    public class Program{
    public static int [] max;
    public static int [] a;
    static void Main(){
        a = new int[]{4, -8, 9, -4, 1, -8, -1, 6};
        max = new int[a.Length];
        int realmax = -32768;
        max[0]=a[0];
        for(int i=1;i<max.Length;i++){
            max[i] = Math.Max(max[i-1]+a[i],a[i]);
            realmax = Math.Max(realmax,max[i]);
        }
        Console.WriteLine(realmax);
    }  
    } 
        }


    
