#include <bits/stdc++.h>
using namespace std;
// brute force
vector<int> firstNegativeinWindow(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> r;
    for (int i = 0; i <= n - k; i++)
    {
        int firstnegative = 0;
        for (int j = i; j <= i + k - 1; j++)
        {
            if (a[j] < 0)
            {
                firstnegative = a[j];
                break;
            }
        }
        r.push_back(firstnegative);
    }
    return r;
}

int main()
{
    vector<int> a = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> result = firstNegativeinWindow(a, k);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}