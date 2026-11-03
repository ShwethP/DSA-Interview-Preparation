#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &a)
{
    vector<int> r;
    for (int i = 0; i < a.size(); i++)
    {
        bool found = false;
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] > a[i])
            {
                r.push_back(a[j]);
                found = true;
                break;
            }
        }
        if (!found)
        {
            r.push_back(-1);
        }
    }
    return r;
}

int main()
{

    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(arr); // 5, 10, 10, -1, -1

    for (int n : result)
    {
        cout << n << endl;
    }
    return 0;
}