#include <bits/stdc++.h>
using namespace std;

int maxSubCirarraySum(const vector<int>& a) {

    if(a.empty()) return 0;
//basically we are calculating total sum, maxarray sum and minarray sum cause once w e have all three we can just get the circularmaxsubarraysum by subtracting totalsum-minimumsubarraysum....at the end it is eoyher the maxsubarray sum or circular one

//Maximum circular sum = total sum - minimum subarray sum
    int totalsum = 0;

    int currentMaxSum = 0;
    int maxSum = a[0];

    int currentMinSum = 0;
    int minSum = a[0];

    for (int i = 0; i < a.size(); i++) {

        totalsum += a[i];

        // update currentMaxSum
        currentMaxSum = max(a[i], currentMaxSum + a[i]);
        // update maxSum
        maxSum = max(maxSum, currentMaxSum);

        //update currentMinSum
        currentMinSum = min(a[i], currentMinSum + a[i]);
        //update minsum
        minSum = min(minSum, currentMinSum);

    }
    //this following if condition is to check if all the elements in the array are negative the it is gonna return 0 so we have to check which is the maxSum and return that
    if(maxSum<0){
        return maxSum;
    }

    return max(maxSum, totalsum-minSum);
}

int main() {

    vector<int> a = {-5, -3, -5};

    cout << maxSubCirarraySum(a) << endl;

    return 0;
}