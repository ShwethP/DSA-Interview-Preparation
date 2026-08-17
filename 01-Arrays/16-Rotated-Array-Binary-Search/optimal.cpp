#include <bits/stdc++.h>
using namespace std;

int searchRotated(const vector<int>& a, int k) {

    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (a[mid] == k) {
            return mid;
        }

        if (a[l] <= a[mid]) {

            // LEFT HALF IS SORTED

            if (k >= a[l] && k <= a[mid]) {
                r = mid -1;
            }
            else {
                l = mid +1;
            }

        }
        else {

            // RIGHT HALF IS SORTED

            if (k >= a[mid] && k <= a[r]) {
                l = mid +1;
            }
            else {
                r = mid -1;
            }
        }
    }

    return -1;
}

int main(){
    vector<int> a = {2,3,4,5,6,8,9,0,1};
    int k = 0;
    cout<<searchRotated(a,k)<<endl;

}