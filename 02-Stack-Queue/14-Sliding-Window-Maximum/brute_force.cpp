#include <bits/stdc++.h>
using namespace std;
// brute force
vector<int> slidingWindowMax(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> r;
    for (int i = 0; i <= n - k; i++)
    {
        int maxnum = a[i];
        for (int j = i; j <= i + k - 1; j++)
        {
            maxnum = max(maxnum, a[j]);
        }
        r.push_back(maxnum);
    }
    return r;
}

int main()
{
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = slidingWindowMax(a, k); // 3 3 5 5 6 7
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}