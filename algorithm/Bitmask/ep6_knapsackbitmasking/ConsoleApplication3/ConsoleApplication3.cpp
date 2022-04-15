// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int weightlimit;
    int n;
    cin >> n;
    cin >> weightlimit;
    vector<int> weight(n + 3);
    vector<int> price(n + 3);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    int maxprice = 0;
    for (int s = 0; s < (1 << n); s++) {  //consider the permutation of bags
        int weightcheck = 0;    //initialize the weightcheck 
        int prices = 0;         //initialize the price for comparing :>>
        for (int index = 0; index < n; index++) {
            if (s & (1 << index)) {   //if bag #index was included 
                weightcheck += weight[index];   //add the weight to weightcheck
                if (weightcheck <= weightlimit) {   //if the weight is under the limit
                    prices += price[index];     // then include it to the price
                    maxprice = max(maxprice, prices);   //check the maxprice :>>>
                }
            }
        }
    }
    cout << maxprice<<endl;
}

