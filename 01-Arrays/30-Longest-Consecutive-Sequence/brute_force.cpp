#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCons(vector<int>& a) {
    if (a.empty()) return 0;

    // 1. Sort the array
    sort(a.begin(), a.end()); // {1, 2, 3, 4, 10, 11, 20, 100}

    int longestStreak = 1;
    int currentStreak = 1;

    for (size_t i = 1; i < a.size(); i++) {
        // Skip duplicate elements
        if (a[i] == a[i - 1]) {
            continue;
        }
        // If consecutive, increase the current sequence count
        if (a[i] == a[i - 1] + 1) {
            currentStreak++;
        } 
        // If the streak breaks, record the max and reset
        else {
            longestStreak = max(longestStreak, currentStreak);
            currentStreak = 1;
        }
    }

    return max(longestStreak, currentStreak);
}

int main() {
    vector<int> a = {100, 4, 200, 2, 11, 3, 20, 1};
    cout << "Longest sequence length: " << longestCons(a) << endl; // Outputs 4 (1, 2, 3, 4)
    return 0;
}
