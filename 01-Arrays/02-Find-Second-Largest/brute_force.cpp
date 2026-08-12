#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {10, 5, 8, 20, 15, 20};

    if (arr.size() < 2) {
        cout << "No second largest element";
        return 0;
    }

    sort(arr.begin(), arr.end());

    int largest = arr[arr.size() - 1];

    int i = arr.size() - 2;

    while (i >= 0 && arr[i] == largest) {
        i--;
    }

    if (i < 0) {
        cout << "No second largest element";
    } else {
        cout << arr[i] << endl;
    }

    return 0;
}