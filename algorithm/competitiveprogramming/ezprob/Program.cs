using System;
namespace ezprob{
    public class Program{
        static string solve(){
            string s  = Console.ReadLine();
        
        if(s.Length>10){
            string x = (s.Length-2).ToString();
            Console.WriteLine(s[0]+x+s[s.Length-1]);
        }
        else{
            Console.WriteLine(s);
        }
        }
     static void Main(){
        int n= Convert.ToInt32(Console.ReadLine());
        while (n--){
            solve();
        }
    }
}
}