#include <bits/stdc++.h>
using namespace std;

int atMostKDistinct(vector<int>& a, int k) {
    if (k <= 0) return 0;
    int count = 0, l = 0;
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
        count += r -l+1;

    }

    return count;
}


int main(){
    vector<int> a = {1, 2, 1, 2, 4};
    int k = 2;
    int result = atMostKDistinct(a,k) - atMostKDistinct(a, k-1);
    cout<< result <<endl; //12-5 = 7
    return 0;
}