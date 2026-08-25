#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(
    const vector<int>& stalls,
    int k,
    int distance
) {

    int count = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {

        if (stalls[i]-lastPosition >= distance) {

            count++;
            lastPosition = stalls[i];

            // if (count >= k) {
            //     return true;
            // }
        }
    }

    return count >= k;
}

int maxMinDistance(const vector<int>& stalls, int k){

    int l = 0;
    
    int r = *max_element(stalls.begin(), stalls.end())-*min_element(stalls.begin(), stalls.end());

     while (l <= r) {

        int mid = l + (r - l) / 2;

        if (canPlaceCows(stalls, k , mid)) {
           //if this distance workjs means try for igher distance
            l = mid + 1;
        }
        else {
           //else go for lower cause lower works
            r = mid - 1;
        }
    }
    return r;
}

int main() {

    vector<int> stalls = {1, 2, 4, 8, 9};

    int k = 3;
    int D = 4;

    cout << maxMinDistance(stalls,k) << endl;

    return 0;
}