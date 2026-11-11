
#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int> &a, int k)
{
    int n = a.size();

    vector<int> result;
    deque<int> dq;
    // 1, 3, -1, -3, 5, 3, 6, 7

    for (int i = 0; i < n; i++)
    {
        // Step 1: Remove indices outside the window
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // Step 2: Remove smaller or equal elements
        while (!dq.empty() && a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }

        // Step 3: Insert current index
        dq.push_back(i);

        // Step 4: Record maximum once window is complete
        if (i >= k - 1)
        {
            result.push_back(a[dq.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};

    int k = 3;

    vector<int> result = slidingWindowMax(a, k);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
