// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k = 3;
	int N = 9;
	int s = (1 << k) - 1;
	while (!(s & 1 << N))
	{
		cout << "__________________________" << endl;
		cout << bitset<16>(s) << endl;
		//làm gì đó với s
		int lo = s & ~(s - 1);   //bit 1 thấp nhất
		cout <<"lo = "<< bitset<16>(lo) << endl;
		int lz = (s + lo) & ~s;  //bit 0 thấp nhất trên lo
		cout << "lz = "<< bitset<16>(lz) << endl;
		s |= lz;                       //thêm lz vào tập hợp
		cout << bitset<16>(s) << endl;
		s &= ~(lz - 1);             //reset bit phía dưới lz
		cout << bitset<16>(s) << endl;
		s |= (lz / lo / 2) - 1;     //đặt lại đúng số bit ở cuối
		cout << bitset<16>(s) << endl;
		cout << endl;
		
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
