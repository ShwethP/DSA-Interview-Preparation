#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(const vector<int>& a) {

    int maxSum = INT_MIN;

    for (int i = 0; i < a.size(); i++) {

        int sum = 0;

        for (int j = i; j < a.size(); j++) {

            sum += a[j];

            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {

    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubarraySum(a) << endl;

    return 0;
}