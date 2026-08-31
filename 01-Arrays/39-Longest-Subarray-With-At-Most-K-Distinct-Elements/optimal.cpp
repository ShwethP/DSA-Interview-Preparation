#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& a, int k) {
    int maxLen = 0, l = 0;
    //same prob in brute we used set but here we need the element frequency so we use map
    unordered_map<int, int> m;

    for(int r = 0; r < a.size(); r++) {

        m[a[r]]++;

        while(m.size() > k) {

            m[a[l]]--;

            if(m[a[l]] == 0) {
                m.erase(a[l]);
            }

            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}


int main(){
    vector<int> a = {1,2,1,2,1,2,3};
    int k = 2;
    int result = longestSubarray(a,k);
    cout<< result <<endl; //4
    return 0;
}