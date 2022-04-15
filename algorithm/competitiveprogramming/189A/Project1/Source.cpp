#include<iostream>
using namespace std;
int dp[4010];
int choice[3];
bool accepted[4010];
int maxi(int a, int b) {
	if (a >= b) return a;
	else return b;
}
int main() {
	accepted[0] = true;
	dp[0] = 0;
	for (int i = 1; i < 4010; i++) {
		dp[i] = -1;
		accepted[i] = false;
	}
	int n, a, b, c;
	cin >> n>> a>> b>> c;
	choice[0] = a;
	choice[1] = b;
	choice[2] = c;
	for (int i = 1; i < 4010; i++) {
		for (int j = 0 ; j <3 ;j++){
			if (i - choice[j] >= 0) {
				if (accepted[i-choice[j]]==true) {
					accepted[i] = accepted[i] || accepted[i - choice[j]];
					dp[i] = maxi(dp[i],dp[i-choice[j]]+1);
				}
			}
		}
	}
	cout << dp[n];
}