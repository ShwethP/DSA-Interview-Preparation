#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums){

    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

//till only n-3 cause we still need three elements after where i ends for left , right and j
    for(int i = 0; i<n-3; i++){

        //check for duplicates that i need to eliminate
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }

        //n-2 cause we need atleast two elemnts after j end for left and right pointers
        for(int j = i+1; j< n-2; j++){
            //check for duplicates that j might need to eliminate
            if(j>i+1 && nums[j] == nums[j-1]){
                continue;
            }

            // so lets apply two pint for rest of the array
            int left = j+1, right = n-1;

            while(left < right){

                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                //sum equals zero menas we have save in the result
                if(sum == 0){
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    //we have to skip the duplicates that can be caused by left and right pointers 

                    while(left<right && nums[left] == nums[left-1]){
                        left++;
                    }

                    while(left<right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }

            }
        }
          
    }
    return result;
}


int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4, 0, 0, 4};

    vector<vector<int>> result = fourSum(nums);

    for (const auto& triplet : result) {
        cout << "[ ";

        for (int num : triplet) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}