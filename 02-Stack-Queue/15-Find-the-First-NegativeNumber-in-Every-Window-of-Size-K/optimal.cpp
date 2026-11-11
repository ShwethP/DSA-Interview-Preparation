#include <bits/stdc++.h>
using namespace std;
// brute force
vector<int> firstNegativeinWindow(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> r;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        // Step 1: If current element is negative, store its index
        if (a[i] < 0)
        {
            q.push(i);
        }

        // Step 2: Once window is complete, remove expired indices
        while ((!q.empty()) && q.front() <= i - k)
        {
            q.pop();
        }

        // Step 3: If window is complete, add the answer
        if (i >= k - 1)
        {
            if (q.empty())
            {
                r.push_back(0);
            }
            else
            {
                r.push_back(a[q.front()]);
            }
        }
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