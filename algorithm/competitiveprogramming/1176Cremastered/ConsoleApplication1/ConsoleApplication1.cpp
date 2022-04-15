
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int preset[50];
	preset[4] = 0;
	preset[8] = 1;
	preset[15] = 2;
	preset[16] = 3;
	preset[23] = 4;
	preset[42] = 5;
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> dp(7);
	for (int i = 1; i <= n; i++) {
		int j = preset[a[i]];
		if (j == 0) {
			dp[j]++;
		}
		else {
			if (dp[j - 1] > 0) {
				dp[j - 1]--;
				dp[j]++;
			}
		}
	}
	cout << n - 6*dp[5] << endl;


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
