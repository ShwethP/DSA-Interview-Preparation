#include <bits/stdc++.h>
using namespace std;

// 1. Changed return type to vector<int>
vector<int> twoSum(const vector<int>& nums, int target){

    unordered_map<int, int> m;

    for(int i = 0; i < nums.size(); i++){
        int val = target - nums[i];
        auto it = m.find(val);
        if (it != m.end()) {
            return {it->second, i};
        }    
        else{
            m[nums[i]] = i;
        }
    }
    
    return {}; 
}

int main(){
    vector<int> nums = {-3,4,3,90};
    int target = 0;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
