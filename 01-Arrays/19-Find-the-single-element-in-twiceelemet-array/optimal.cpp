#include <bits/stdc++.h>
using namespace std;

int findSingleElement(const vector<int>& a) {

    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        // Make mid even
        if (mid % 2 == 1) {
            mid--;
        }

        if (a[mid] == a[mid + 1]) {
            // Correct pair → single is to the right
            l = mid+2;
        }
        else {
            // Broken pair → single is here or to the left
            r = mid;
        }
    }

    return a[l];
}

int main(){
    vector<int> a = {9,9,1,1,7,7,0,1,1,3,3,5,5};
    cout<<findSingleElement(a)<<endl;

}