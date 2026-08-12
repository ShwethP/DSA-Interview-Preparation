#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {5, 2, 9, 1, 7};

    int maximum = INT_MIN;

    for (int i =0; i<arr.size(); i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    cout << maximum << endl;

    return 0;
}