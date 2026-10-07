#include <bits/stdc++.h>
using namespace std;

int subarrayswithallThree(string s) {
    vector<int> lastSeen(3, -1);
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        lastSeen[s[i] - 'a'] = i;

        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            // Replaced the initializer list min({a, b, c}) to support older compilers
            int minStart = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            count += (minStart + 1);
        }
    }
    return count;
}

int main() {
    string s = "abcabc";
    int result = subarrayswithallThree(s);
    cout << result << endl; // Output: 10
    return 0;
}
