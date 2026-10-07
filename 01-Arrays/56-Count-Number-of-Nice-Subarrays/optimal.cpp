#include <bits/stdc++.h>
using namespace std;

int atMostKDistinct(vector<int>& a, int k) {
    if (k <= 0) return 0;
    int count = 0, l = 0, oddCount = 0;
    //same prob in brute we used set but here we need the element frequency so we use map

    for(int r = 0; r < a.size(); r++) {
        if(a[r] % 2 == 1) oddCount++;

        while(oddCount > k) {

            if(a[l] % 2 == 1) oddCount--;

            l++;
        }
        count += (r - l + 1);
    }
    return count;
}


int main(){
    vector<int> a = {1, 1, 2, 1, 1};
    int k = 3;
    int result = atMostKDistinct(a,k) - atMostKDistinct(a,k-1);
    cout<< result <<endl; //14- 12 = 2
    return 0;
}