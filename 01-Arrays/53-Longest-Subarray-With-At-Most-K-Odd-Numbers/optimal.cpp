#include <bits/stdc++.h>
using namespace std;

int lengthLongestSubArrAtmostOnesOptimized(vector<int>& a, int k) {
    int left = 0, maxlength = 0, onesCount = 0;

    for (int right = 0; right < a.size(); right++) {
        if (a[right] == 1) onesCount++;

        while (onesCount > k) {
            if (a[left] == 1) onesCount--;
            left++;
        }
        maxlength = max(maxlength, right - left + 1);
    }
    return maxlength;
}


int main(){
    vector<int> a = {1, 1, 0, 1, 0, 0, 1, 1, 1};
    int k = 2;
    int result = lengthLongestSubArrAtmostOnesOptimized(a, k);//5
    cout<< result<< endl;
}