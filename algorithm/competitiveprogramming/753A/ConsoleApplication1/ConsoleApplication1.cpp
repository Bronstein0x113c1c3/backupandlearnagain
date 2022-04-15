#include<iostream>
using namespace std;
int main()
{
    int no_of_gifts;
    cin >> no_of_gifts;

    int no_of_people = 1;
    while (no_of_people * (no_of_people + 1) <= 2 * no_of_gifts)
        no_of_people++;

    no_of_people--;

  cout<<no_of_people<<endl;
    for (int i = 1; i < no_of_people; i++)
    {
        cout<<i<<" ";
        no_of_gifts -= i;
    }

    cout<<no_of_gifts<<endl; //Last person gets all remaining gifts
    return 0;
}