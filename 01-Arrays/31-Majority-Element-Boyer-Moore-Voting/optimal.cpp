#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {

    int candidate = 0;
    int count = 0;

    for (int num : nums) {

        if (count == 0) {
            candidate = num;
        }

        if (num == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return candidate;
}

//it will only work if the the element occurs more than n/2 times
int main() {
    vector<int> a = {1,3,1,1,3,1,1,4,1,2};
    cout << "element occuring more that n/2 times: " << majorityElement(a) << endl; // Outputs 4 (1, 2, 3, 4)
    return 0;
}