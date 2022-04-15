//memoization+bitmask 
using System;
using System.Collections.Generic;
using System.Linq;

namespace ep16{
    public class Program{
        public static int findposition(int mask){
            if(mask ==1){
                return 0;
            }
            else{
                int i = mask;
                int j = 0;
                while(i>1){
                    i = i>>1;
                    j++;
                }
                return j;
            }
        }
        public static int [,]dp = new int[17,4]; //17 = (1<<work_id)+1
        public static int [,]cost = new int [,] {{3,8,5,6},
                                                {2,17,9,7},
                                                {16,10,11,19},
                                                {14,18,13,15}};
        public static int []workindex = new int[17];
        public static int allmask;
        public static int MinimumCost(int mask, int work_id){
            if ((mask==allmask)||(work_id>=4)) return 0; //word_id = sqrt(cost.length)
            else{
                if(dp[mask, work_id]!=-1){
                    return dp[mask,work_id];
                }
                else{
                    int min = 32768;
                    for(int j=0;j<4;j++){
                        if((mask&(1<<j))>0) {continue;}
                        else{
                            min = Math.Min(min,MinimumCost(mask|(1<<j),work_id+1)+cost[j,work_id]);
                            if (min==MinimumCost(mask|(1<<j),work_id+1)+cost[j,work_id]){
                                    workindex[mask] = mask|(1<<j);
                            }
                            else{
                                continue;
                            }
                        }
                    }
                    dp[mask,work_id] = min;
                    return min;
                }
            }
        }
        public static void Main(){
            for(int i1 = 0;i1<17;i1++){
                for (int i2=0;i2<4;i2++){
                    dp[i1,i2]=-1;
                }
            }
            allmask = (1<<4)-1;
            Console.WriteLine(MinimumCost(0,0));
                int k = 0;
                int j = 0;
                while(j<15){
                    Console.WriteLine("workID {0}, workerID {1} ",k,findposition(workindex[j]!^j));
                    k++;
                    j = workindex[j];
                }
                
            
           
        }
    }
}