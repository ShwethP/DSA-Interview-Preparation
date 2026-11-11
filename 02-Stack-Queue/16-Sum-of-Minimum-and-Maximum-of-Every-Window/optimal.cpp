#include <bits/stdc++.h>
using namespace std;
// optimal
// Time: O(N) — every index enters and leaves each deque at most once.
// Auxiliary space: O(K) — two deques, each holding at most K indices.
// Result space: O(N-K+1).
vector<int> slidingWindowMinMaxSum(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> result;

    deque<int> maxDQ;
    deque<int> minDQ;

    for (int i = 0; i < n; i++)
    {
        // 1. Remove expired indices from both deques
        while ((!minDQ.empty()) && minDQ.front() <= i - k)
        {
            minDQ.pop_front();
        }
        while ((!maxDQ.empty()) && maxDQ.front() <= i - k)
        {
            maxDQ.pop_front();
        }

        // 2. Maintain decreasing order in maxDQ
        while ((!maxDQ.empty()) && a[maxDQ.back()] <= a[i])
        {
            maxDQ.pop_back();
        }

        // 3. Maintain increasing order in minDQ
        while ((!minDQ.empty()) && a[minDQ.back()] >= a[i])
        {
            minDQ.pop_back();
        }

        // 4. Insert current index into both deques
        maxDQ.push_back(i);
        minDQ.push_back(i);

        // 5. If window is complete, calculate min + max
        if (i >= k - 1)
        {
            result.push_back(a[maxDQ.front()] + a[minDQ.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> a = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    vector<int> result = slidingWindowMinMaxSum(a, k); // 6 4 4 4
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}