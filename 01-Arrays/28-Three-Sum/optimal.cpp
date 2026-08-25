#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                result.push_back({
                    nums[i],
                    nums[left],
                    nums[right]
                });

                left++;
                right--;

                // Skip duplicate left values
                while (left < right &&
                       nums[left] == nums[left - 1]) {
                    left++;
                }

                // Skip duplicate right values
                while (left < right &&
                       nums[right] == nums[right + 1]) {
                    right--;
                }
            }

            else if (sum < 0) {
                // Need a larger sum
                left++;
            }

            else {
                // Need a smaller sum
                right--;
            }
        }
    }

    return result;
}

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[ ";

        for (int num : triplet) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}