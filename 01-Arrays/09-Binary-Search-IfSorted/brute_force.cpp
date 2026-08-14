#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &a, int k){
    int l = 0, r = a.size()-1;

    while(l<=r){
// It's not that (l+r)/2 will usually crash. The problem is that if l + r exceeds the maximum value representable by the integer type, integer overflow can occur.
        int mid = l+(r-l)/2;

        if(a[mid]==k){
            return mid;
        }
        else if(a[mid]>k){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;

}

int main(){
    vector<int> a = {1,3,4,6,7,8,9};
    int k = 100;
    cout<<binarySearch(a,k)<<endl;

}