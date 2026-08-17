#include <bits/stdc++.h>
using namespace std;

int lowerbound(const vector<int> &a, int k){
    int l = 0, r = a.size() - 1;
    
    // FIX: Default to a.size() because if k is larger than all elements,
    // it belongs at the very end of the array.
    // int ans = a.size(); 

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] >= k) {
            // ans = mid;    // This index is a candidate insertion point
            r = mid - 1;  // Keep looking left for a smaller valid index
        }
        else { 
            // Simplified: Since a[mid] is strictly less than k
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    vector<int> a = {2, 5, 6, 10, 1000};
    int k = 1001;
    
    // Now correctly outputs 5
    cout << lowerbound(a, k) << endl; 

    return 0;
}
