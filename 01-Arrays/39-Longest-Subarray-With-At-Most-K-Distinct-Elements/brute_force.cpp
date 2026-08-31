#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& a, int k) {
    int maxLen = 0;
    for(int i = 0; i<a.size();i++){
        unordered_set<int> s;
        for(int j = i; j<a.size(); j++){
            s.insert(a[j]);
            if(s.size()<=k){
                maxLen = max(maxLen, j-i+1);
            }
            //id not we dont need to add anymore elements to set from j so we need to braek the j loop
            else{
                break;
            }
        }
    }

    return maxLen;
}


int main(){
    vector<int> a = {0,1,2,1,2,1,2,4,5};
    int k =4;
    int result = longestSubarray(a,k);
    cout<< result <<endl; //4
    return 0;
}