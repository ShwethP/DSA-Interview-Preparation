#include <bits/stdc++.h>
using namespace std;

int countSubarraysXorK(vector<int>& a, int k) {
    int count = 0;

    for (int i = 0; i < a.size(); i++) {

        int currentXor = 0;

        for (int j = i; j < a.size(); j++) {

            currentXor ^= a[j];

            if (currentXor == k) {
                count++;
            }
        }
    }

    return count;
}


int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int result = countSubarraysXorK(a, k);
    cout<< result <<endl; //4

    return 0;
    
}