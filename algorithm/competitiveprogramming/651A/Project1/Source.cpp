#include<iostream>
#include<std>
using namespace std;
int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}
int arr[301][301];

int main() {
	
	
	
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	while (a > 0 && b > 0) {
		if (a == 1 && b == 1) break; 
		else {
			if (a > b) {
				a -= 2;
				b += 1;
			}
			else {
				a += 1;
				b -= 2;
			}
			
		}
		cnt++;
	}
	cout << cnt;
	
}