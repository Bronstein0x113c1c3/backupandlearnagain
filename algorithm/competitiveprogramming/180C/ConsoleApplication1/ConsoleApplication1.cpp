#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.length();
    vector<int> l(n);
    vector<int> r(n);
    //how many small letters in my left
    l[0] = 0;
    for (int i = 1; i < n; i++)
    {
        l[i] = l[i - 1];
        if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
            l[i]++;
    }

    //how many capital letters in my right
    r[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = r[i + 1];
        if (s[i + 1] >= 'A' && s[i + 1] <= 'Z')
            r[i]++;
    }

    int mn = n;
    for (int i = 0; i < n; i++)
    {
        //let ith be the point where capital|small occurs
        if (mn > l[i] + r[i]) {
            mn = l[i] + r[i];
        }
    }
    cout << mn << endl;
}