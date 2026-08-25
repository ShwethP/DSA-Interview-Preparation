#include <bits/stdc++.h>
using namespace std;

bool canAdd(
    const vector<int>& nums,
    int k,
    int mid
) {

    int count = 1;
    int current = nums[0];

    for (int i = 1; i < nums.size(); i++) {

        if (current + nums[i] <= mid) {
            current = current + nums[i];
        }
        else{
            count++;
            current = nums[i];
        }
    }

    return count <= k;
}

int minMaxSum(const vector<int>& nums, int k){

    if (k > nums.size()) {
    return -1;
    }

    int l = *max_element(nums.begin(), nums.end());
    
    int r = accumulate(nums.begin(), nums.end(), 0);

     while (l <= r) {

        int mid = l + (r - l) / 2;

        if (canAdd(nums, k , mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {

    vector<int> nums = {10,20, 30, 40};
    int k = 2;

    cout << minMaxSum(nums,k) << endl;

    return 0;
}