#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& a) {
    int n = a.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++) {

        // Find maximum on left
        int leftMax = 0;
        for (int j = 0; j < i; j++) {
            leftMax = max(leftMax, a[j]);
        }

        // Find maximum on right
        int rightMax = 0;
        for (int k = i + 1; k < n; k++) {
            rightMax = max(rightMax, a[k]);
        }

        int minHeight = min(leftMax, rightMax);
        
        // Ensure we don't add negative water if a[i] is taller than its boundaries
        if (minHeight > a[i]) {
            totalWater += (minHeight - a[i]);
        }
    }

    return totalWater;
}


int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(a);
    cout<< result<< endl;//6
    return 0;

}