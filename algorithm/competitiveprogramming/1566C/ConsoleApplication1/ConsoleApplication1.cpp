// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
void solveeachtest();
int solve(string s) {
    int ans = count(s.begin(), s.end(), '0');
    bool a =false, b = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0'){
            a = true;
        }
        if (s[i] == '1') {
            b = true;
        }
        if (a && b) {
            ans++;
            a = b = false;
        }
    }
    return ans;
}
void solveeachtest() {
    int len;
    int ans = 0;
    string s1, s2, s="";
    cin >> len;
    cin >> s1 >> s2;
    for (int i = 0; i < len+1; i++) {
        if (i < len) {
            if ((s1[i] != s2[i])) {
                ans += 2 + solve(s);
                s = "";
            }
            else
            {
                s += s1[i];
            }
        }
        else {
            ans += solve(s);
        }
    }
    cout << ans << endl;
}
int main()
{
    int tests;
    cin >> tests;
    while (tests--) {
        solveeachtest();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
