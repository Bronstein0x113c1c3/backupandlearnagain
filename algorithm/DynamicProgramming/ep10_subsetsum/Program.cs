//using memoization
using System;
using System.Collections.Generic;
using System.Text;
namespace ep10_subsetsum{
 public class Program{
     
    public static bool[] solved = new bool[1000];
    public static bool[] sumofsubset = new bool[1000];
    public static int[] remove_element(int []subset,int element){
        List<int> arr = subset.ToList();
        arr.Remove(element);
        return arr.ToArray();
    }
    
     public static bool checkingsum(int sum,int length,int[] subset){
         Console.WriteLine("{0} ",sum);
        if (sum<0) return false;
        else{
            if (sum==0) return true;
            else{
                if (length<=0) return false;
                else{
                    if (solved[sum]==true) return sumofsubset[sum];
                    else
                    {
                     bool checkbool = false;
                     foreach (int element in subset){
                         checkbool = checkbool||checkingsum(sum-element,length-1,remove_element(subset,element));
                     }   
                        solved[sum] = true;
                        sumofsubset[sum] = checkbool;
                        return checkbool;
                    }
                }
            }
        }
     }
     public static void Main(string[] args){
         int []a = new int[]{3,5,8,9,10};
        for(int i=1;i<solved.Length;i++){
            solved[i] = false;
        }
        Console.WriteLine(checkingsum(Convert.ToInt32(args[0]),a.Length,a));



       
     }
 }
}