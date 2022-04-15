#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a[51];
	int n, k;
	cin >> n >> k;
	int count = 0;
	int k1 = k - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if ((a[i] > 0) && a[i] >= a[k1]) {
			count++;
		}
	}
	cout << count<<endl;

}