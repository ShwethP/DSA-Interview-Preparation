#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& a, int k) {

    unordered_map<int, int> m;

    // Prefix sum 0 exists before the array starts
    m[0] = -1;

    int currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++) {

        currentSum += a[i];

        int required = currentSum - k;

        // Have we seen the required prefix sum?
        if (m.find(required) != m.end()) {

            int length = i - m[required];

            maxLen = max(maxLen, length);
        }

        // Store only the FIRST occurrence
        if (m.find(currentSum) == m.end()) {
            m[currentSum] = i;
        }
    }

    return maxLen;
}


int main(){
    vector<int> a = {1, 2, 3, 1, 1, 0, 1, 1};
    int k = 3;
    int result = longestSubarray(a, k);
    cout<< result <<endl; //4

    return 0;
    // for(int a : result){
    //     cout<< a <<endl;
    // }
}