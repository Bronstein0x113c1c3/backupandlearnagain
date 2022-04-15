// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = 10e9;
map<string, int> was;
void read() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c; string s;
        cin >> c >> s;
        //sort the string: BA to AB, easy calculate.
        sort(s.begin(), s.end());
        if (was.count(s) == 0) {
            was[s] = c;
        }
        else {
            //find the minimal cost of each formula
            was[s] = min(was[s], c);
        }
    }
}
int getC(string a, string b) {
    if (!was.count(a) || !was.count(b)) {
        return INF;
    }
    return was[a] + was[b];
}
void solve() {
    int ans = INF;
    if (was.count("A") && was.count("B") && was.count("C")) {
        ans = was["A"] + was["B"] + was["C"];
    }
    if (was.count("ABC")) {
        ans = min(ans, was["ABC"]);
    }
    ans = min(ans, getC("AB", "C"));
    ans = min(ans, getC("A", "BC"));
    ans = min(ans, getC("AC", "B"));
    ans = min(ans, getC("AB", "BC"));
    ans = min(ans, getC("AC", "BC"));
    ans = min(ans, getC("AC", "AB"));
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

}
 
int main()
{
    read();
    solve();
}
