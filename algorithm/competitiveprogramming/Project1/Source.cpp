#include<iostream>
#include<sstream>

using namespace std;
void solve(string s) {
	if (s.length() > 10) {
		int num = s.length()-2;
		std::stringstream ss;
		ss << num;
		std::string str = ss.str();
		cout << s[0] + str + s[s.length() - 1]<<endl;
	}
	else {
		cout << s << endl;
	}
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		solve(s);
	}
	
}