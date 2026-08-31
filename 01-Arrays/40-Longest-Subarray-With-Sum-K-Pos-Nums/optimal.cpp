#include <bits/stdc++.h>
using namespace std;
// sliding window approach on prefix sum kinda question works only because the proble has only positive numbers
int longestSubarrayPrefixSum(vector<int>& a, int k){
    int maxLen = 0, l = 0;
    int sum = 0;
    for(int r = 0; r<a.size(); r++){
        sum += a[r];
        while(sum > k){
            sum -= a[l];
            l++;
        }
        if(sum == k){
            maxLen = max(maxLen, r-l+1);
        }
    }
    return maxLen;
}


int main(){
    vector<int> a = {1,0,3,2,-1,-1,-1, -3, -4};
    int k = 3;
    int result = longestSubarrayPrefixSum(a, k);
    cout<< result <<endl; //4

    return 0;
    // for(int a : result){
    //     cout<< a <<endl;
    // }
}