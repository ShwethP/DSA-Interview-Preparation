#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumSorted(const vector<int>& a, int target){

    int l = 0, r = a.size()-1;

    while(l <= r){
    int sum = a[l] + a[r];

        if(sum == target){
            return {l,r};
        }

        if(sum < target){
            l = l+1;
        }
        else{
            r = r-1;
        }
    }
    return {};

}

int main(){
    vector<int> a = {1,2,3,4,6};
    int target = 6;

    vector<int> result = twoSumSorted(a, target);

    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}