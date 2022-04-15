// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n, v;
    cin >> n >> v;
    if (n <= v) {
        cout << n - 1 << endl;
        return 0;
    }
    int result = v;
    for (int i = 2; i <= n - v; i++) {
        result += i;
    }
    cout << result << endl;
    return 0;

}

