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

int main(){
    vector<int> a = {1,2,2,2,4,4,4,5,7};
    int k = 4;
    cout<<lastOccurence(a,k)<<endl;

}