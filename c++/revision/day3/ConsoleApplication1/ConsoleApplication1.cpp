// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
struct LinkedList {
    int name;
    LinkedList* next;
};
int main()
{
    LinkedList node1; 
    LinkedList node2;
    LinkedList node3;
    LinkedList node4;
    node1.name = 1;
    node1.next = &node2;
    node2.name = 2;
    node2.next = &node3;
    node3.name = 3;
    node3.next = &node4;
    node4.name = 4;
    node4.next = nullptr;
    LinkedList* temp = &node1;
    while (temp!= nullptr) {
        cout << temp->name<<endl;
        temp = temp->next;
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
