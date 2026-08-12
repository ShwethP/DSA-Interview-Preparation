#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {5, 2, 9, 1, 7};

    sort(arr.begin(), arr.end());

    cout << arr[arr.size() - 1] << endl;

    return 0;
}