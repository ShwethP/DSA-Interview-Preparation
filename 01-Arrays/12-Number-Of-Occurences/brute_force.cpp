#include <bits/stdc++.h>
using namespace std;

int lastOccurence(const vector<int> &a, int k){
    int l = 0, r = a.size()-1;
    int ans = -1;

    while(l<=r){
        int mid = l+(r-l)/2;

        if(a[mid]==k){
            ans = mid;
            l = mid + 1;
        }
        else if(a[mid]<k){
            l= mid+1;
        }
        else{
            r= mid-1;
        }
    }
    return ans;

}

int firstOccurence(const vector<int> &a, int k){
    int l = 0, r = a.size()-1;
    int ans = -1;

    while(l<=r){
        int mid = l+(r-l)/2;

        if(a[mid]==k){
            ans = mid;
            r = mid - 1;
        }
        else if(a[mid]<k){
            l= mid+1;
        }
        else{
            r= mid-1;
        }
    }
    return ans;

}

int main(){
    vector<int> a = {1,2,2,2,4,4,4,5,7};
    int k = 4;
    int first = firstOccurence(a, k);

if (first == -1) {
    cout << 0 << endl;
} else {
    int last = lastOccurence(a, k);
    cout << last - first + 1 << endl;
}

}