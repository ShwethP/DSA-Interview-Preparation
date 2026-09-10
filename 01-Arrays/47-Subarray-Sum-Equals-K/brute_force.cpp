#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& a, int k){
    int count = 0;

    for(int i = 0; i<a.size(); i++){
        int currentSum = 0;
        for(int j = i; j< a.size(); j++){
            currentSum += a[j];

            if(currentSum == k){
                count++;
            }
        }
    }
    return count;
}


int main(){
    vector<int> a = {1, 2, 3, 10, -7};
    int k = 3;
    int result = longestSubarray(a, k);
    cout<< result <<endl; //4

    return 0;
    
}