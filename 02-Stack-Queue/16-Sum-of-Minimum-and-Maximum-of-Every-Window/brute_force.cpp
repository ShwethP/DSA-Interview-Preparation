#include <bits/stdc++.h>
using namespace std;
// brute force
vector<int> sumofMaxMininWindow(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> r;
    for (int i = 0; i <= n - k; i++)
    {
        int maxnum = a[i], minnum = a[i];
        for (int j = i; j <= i + k - 1; j++)
        {
            maxnum = max(maxnum, a[j]);
            minnum = min(minnum, a[j]);
        }
        r.push_back(maxnum + minnum);
    }
    return r;
}

int main()
{
    vector<int> a = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    vector<int> result = sumofMaxMininWindow(a, k); // 6 4 4 4
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}