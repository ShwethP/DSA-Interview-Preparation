#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(const vector<int>& a) {

    int currentSum = a[0];
    int maxSum = a[0];

    for (int i = 1; i < a.size(); i++) {

        // Should we start fresh or extend?
        
        // update currentSum
        currentSum = max(a[i], currentSum + a[i]);

        // update maxSum
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {

    vector<int> a = {-5, -2, -8, -1};

    cout << maxSubarraySum(a) << endl;

    return 0;
}