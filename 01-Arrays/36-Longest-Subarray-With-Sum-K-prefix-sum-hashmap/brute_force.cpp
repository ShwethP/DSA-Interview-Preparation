#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& a, int k){
    int maxLen = 0;

    for(int i = 0; i<a.size(); i++){
        int currentSum = 0;
        for(int j = i; j< a.size(); j++){
            currentSum += a[j];

            if(currentSum == k){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }
    return maxLen;
}


int main(){
    vector<int> a = {1, 2, 3, 1, 1, 0, 1, 1};
    int k = 3;
    int result = longestSubarray(a, k);
    cout<< result <<endl; //4

    return 0;
    // for(int a : result){
    //     cout<< a <<endl;
    // }
}