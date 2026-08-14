#include <bits/stdc++.h>
using namespace std;

int firstOccurence(const vector<int> &a, int k){
    int l = 0, r = a.size()-1;

//     while(l<=r){
// // It's not that (l+r)/2 will usually crash. The problem is that if l + r exceeds the maximum value representable by the integer type, integer overflow can occur.
//         int mid = l+(r-l)/2;

//         if(a[mid]==k){
//             // Safe Check: If mid is 0, it IS the first occurrence. prventing the out of bound 
//             // Otherwise, check if the previous element is different.
//             if (mid == 0 || a[mid - 1] != k) {
//                 return mid;
//             }
//             // If the previous element is ALSO k, the first occurrence is to the LEFT.
//             r = mid - 1; 
//         }
//         else if(a[mid]>k){
//             r = mid-1;
//         }
//         else{
//             l = mid+1;
//         }
//     }
//     return -1;

int answer = -1;

while (l <= r) {

    int mid = l + (r-l)/2;

    if (a[mid] == k) {
        answer = mid;
        r = mid - 1;
        // l= mid+1;
    }
    else if (a[mid] > k) {
        r = mid - 1;
    }
    else {
        l = mid + 1;
    }
}

return answer;

}

int main(){
    vector<int> a = {1,2,2,2,4,5,7};
    int k = 4;
    cout<<firstOccurence(a,k)<<endl;

}