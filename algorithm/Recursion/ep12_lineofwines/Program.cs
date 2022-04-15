//using recursion for pre-testing
using System;
using System.Collections.Generic;
using System.Text;
namespace ep12_lineofwines{
    public class Program{
    public static int[] remove_element(int []a, int index){
        
        List<int> lists = a.ToList();
        lists.RemoveAt(index);
        return lists.ToArray();
    }
    public static int maxlen;
    public static int MaxWine(int []a, int n){
        if (n<=0) return 0;
        else{
             return Math.Max(MaxWine(remove_element(a,0),a.Length-1)+(maxlen-a.Length+1)*a[0],MaxWine(remove_element(a,a.Length-1),a.Length-1)+(maxlen-a.Length+1)*a[a.Length-1]);
            
        }
    } 
    public static void Main(string[] args){
        int []a = Array.ConvertAll(args,int.Parse);
        maxlen = args.Length;
        Console.WriteLine(MaxWine(a,a.Length));
    }



    }



}