#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& a, int k) {

    unordered_map<int, int> m;
    m[0] = 1; // Handles subarrays that sum up to k starting from index 0

    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        currentSum += a[i];

        int needed = currentSum - k;

        // If (currentSum - k) exists in the map, it means we found 
        // subarray(s) that sum up to k
        if (m.find(needed) != m.end()) {
            count += m[needed];
        }

        // Store the frequency of the current prefix sum
        m[currentSum]++;
    }

    return count;
}


int main(){
    vector<int> a = {1, 2, 3};
    int k = 3;
    int result = longestSubarray(a, k);
    cout<< result <<endl; //4

    return 0;
    
}