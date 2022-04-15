#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, count, max = 0;
    cin >> n;
    vector<int>vec;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] <= vec[j])
            {
                count++;
                i++;
            }
            else
                break;
        }
        if (count > max)
            max = count;
    }
    cout << max << endl;
    return 0;
}