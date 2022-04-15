using System;
using System.Text;

namespace ep5_knapsackalternative{
    public class Program{
      public static bool check_pattern(int a,int[] step_patterns){
          int m  = step_patterns.Sum();
          int stepmask = 1;
          while (stepmask < (1<<(a+m))){
              foreach (int step_pattern in step_patterns){
                  stepmask = (stepmask<<step_pattern)|stepmask;
              }
          }
          return ((stepmask>>a)&1)==1 ?true : false; 
      }
        public static void Main(string[] args){
            int[] step_patterns = new int[] {3,4,5};
            Console.WriteLine(check_pattern(12,step_patterns));
        }
    }
}