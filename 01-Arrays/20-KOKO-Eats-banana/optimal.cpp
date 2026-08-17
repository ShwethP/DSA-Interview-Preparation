#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(const vector<int>& piles, int h) {

    int l = 1;
    int r = *max_element(piles.begin(), piles.end());

    while (l <= r) {

        int mid = l + (r - l) / 2;
        long long hours = 0;

        for (int p :piles){
            hours += (p+mid-1)/mid;
        }

        if(hours<=h){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    return l;
}

int main(){
    vector<int> piles = {3, 6, 7, 11, 12};
    int h = 8;
    cout<<minEatingSpeed(piles,h)<<endl;

}