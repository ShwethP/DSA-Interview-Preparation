#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveOnes(vector<int>& a) {

    int count = 0;
    int maxCount = 0;

    for(int i = 0; i < a.size(); i++) {

        if(a[i] == 0) {
            count = 0;
        }
        else {
            count++;
            maxCount = max(maxCount, count);
        }
    }

    return maxCount;
}


int main(){
    vector<int> a = {1,1,0,1,1,1,1,0};
    int result = longestConsecutiveOnes(a);
    cout<< result <<endl; //4

    return 0;
}