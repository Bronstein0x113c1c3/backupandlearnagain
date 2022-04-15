#include<iostream>
using namespace std;
int main() {
	int n;
	int agreementforall = 0;
	int agreementforeach = 0;
	int a[3][1000];
	cin >> n;
	while  (n--) {
		cin >> a[0][n] >> a[1][n] >> a[2][n];
		for (int i = 0; i < 3; i++) {
			if (a[i][n] > 0) {
				agreementforeach++;
			}
		}
		if (agreementforeach >= 2) agreementforall++;
		agreementforeach = 0;
	}
	cout << agreementforall << endl;
}