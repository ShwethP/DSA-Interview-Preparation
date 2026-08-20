#include <bits/stdc++.h>
using namespace std;

bool canMakeBouquets(
    const vector<int>& bloomDay,
    int day,
    int m,
    int k
) {

    int bouquets = 0;
    int consecutive = 0;

    for (int flower : bloomDay) {

        if (flower <= day) {

            consecutive++;

            if (consecutive == k) {
                bouquets++;
                consecutive = 0;
            }
        }
        else {
            consecutive = 0;
        }
    }

    return bouquets >= m;


}

int minDays(const vector<int>& bloomDay, int m, int k){
    if((long long)m*k>bloomDay.size()){
        return -1;
    }

    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int r = *max_element(bloomDay.begin(), bloomDay.end());

     while (l <= r) {

        int mid = l + (r - l) / 2;

        if (canMakeBouquets(bloomDay, mid, m, k)) {
            // This day works.
            // Try to find an earlier day.
            r = mid - 1;
        }
        else {
            // This day doesn't work.
            // Need more time.
            l = mid + 1;
        }
    }
    return l;
}

int main() {

    vector<int> bloomDay = {1, 10, 3, 10, 2};

    int m = 2;
    int k = 2;

    cout << minDays(bloomDay, m, k) << endl;

    return 0;
}