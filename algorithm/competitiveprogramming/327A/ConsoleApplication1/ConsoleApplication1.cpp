// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0, ans = 0;
    int ones = 0;
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>dp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            ones++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            sum += 1;
        }
        else {
            sum -= 1;
        }
        ans = max(ans, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    if (ones == n) {
        cout << ones-1;
    }
    else {
        cout << ones + ans;
    }

}

