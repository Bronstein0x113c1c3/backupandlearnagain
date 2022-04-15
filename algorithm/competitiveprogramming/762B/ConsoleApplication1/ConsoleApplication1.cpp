// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int anscube = 0;
    int anssquare = 0;
    int cubeandsquare = 0;
    for (int i = 1; i * i <= n; i++) {
        anssquare += 1;
    }
    for (int i = 1; i * i * i <= n; i++) {
        anscube += 1;
    }
    for (int i = 1; i * i * i * i * i * i <= n; i++) {
        cubeandsquare += 1;
    }
    int ans = anscube + anssquare - cubeandsquare;
    cout << ans << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        solve();
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
