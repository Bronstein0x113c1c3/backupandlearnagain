// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void solve() {
    string result;
    string n;
    cin >> n;
    if (n.length() % 2 != 0) {
        result = "NO";
    }
    else {
        result = "YES";
        for (int i = 0; i < n.length() / 2; i++) {
            if (n[i] != n[i + n.length()/2]) {
                result = "NO";
                break;
            }
        }
    }
    cout << result << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}


