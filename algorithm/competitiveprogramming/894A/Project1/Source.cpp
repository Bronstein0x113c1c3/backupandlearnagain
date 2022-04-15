#include<iostream>
using namespace std;
int dp[100];
int main() {
	string s;
	cin >> s;
	dp[0] = 0;
	int stop = 0;
	int countq = 0;
	if (s[0] == 'Q') {
		countq++;
	}
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'Q') {
			dp[i] = dp[i - 1] + stop;
			countq++;
		}
		if (s[i] == 'A') {
			dp[i] = dp[i - 1];
			stop = countq;
		}
	}
	cout << dp[s.length() - 1]<<endl;
}