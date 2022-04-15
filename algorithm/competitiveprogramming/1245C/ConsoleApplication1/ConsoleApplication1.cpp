#include<string>
#include <iostream>
using namespace std;
long long dp[100006];
int main()
{
    string s;
    cin >> s;
    int result = 0;
    int countn = 0, countu = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
       }
    }
  
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.length(); i++) {
            if ((s[i - 1] == s[i - 2]) && (s[i - 1] == 'n' || s[i - 1] == 'u')) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        cout << dp[s.length()];
    
  
}

