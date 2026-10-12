#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &a, int k)
{
    int totalSum = 0;

    int n = a.size();

    for (int x : a)
    {
        totalSum += x;
    }

    int windowSize = n - k;

    if (windowSize == 0)
        return totalSum;
    int minWindowSum = 0;

    for (int i = 0; i < windowSize; i++)
    {
        minWindowSum += a[i];
    }
    int minSum = minWindowSum;

    for (int right = windowSize; right < n; right++)
    {
        minWindowSum += a[right];
        minWindowSum -= a[right - windowSize];
        minSum = min(minSum, minWindowSum);
    }

    return totalSum - minSum;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int result = maxScore(a, k);
    cout << result << endl; // Output: 12
    return 0;
}
