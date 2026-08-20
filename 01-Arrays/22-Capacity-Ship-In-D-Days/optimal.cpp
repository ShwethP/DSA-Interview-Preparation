#include <bits/stdc++.h>
using namespace std;

bool canShip(
    const vector<int>& weights,
    int capacity,
    int days
) {
    int daysNeeded = 1;
    int currentLoad = 0;

    for (int weight : weights) {

        if (currentLoad + weight <= capacity) {
           currentLoad = currentLoad + weight;
        }
        else {
        // package doesn't fit
            daysNeeded++;
            currentLoad = weight;
        }
}
return daysNeeded<= days;
}
long long sum(const vector<int>& weights){
    long long sum = 0;
    for(int w: weights){
        sum += w;
    }
    return sum;
}

int minCapacity(const vector<int>& weights, int days){

    int l = *max_element(weights.begin(), weights.end());
    // int r = sum(weights);
    int r = accumulate(weights.begin(), weights.end(),0);

     while (l <= r) {

        int mid = l + (r - l) / 2;

        if (canShip(weights, mid, days)) {
            // This day works.
            // Try to find an lesser capacity.
            r = mid - 1;
        }
        else {
            // This day doesn't work.
            // Need more capacity.
            l = mid + 1;
        }
    }
    return l;
}


int main() {

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};

    int capacity = 15;
    int days = 5;

    cout << minCapacity(weights, days) << endl;

    return 0;
}