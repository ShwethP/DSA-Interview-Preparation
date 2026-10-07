# Number of Substrings Containing All Three Characters — Sliding Window / Last-Seen Array

## Problem

Given a string `s` consisting only of the characters `'a'`, `'b'`, and `'c'`, return the number of substrings containing at least one occurrence of all three characters.

Example:

```text
s = "abcabc"

Answer = 10
```

Valid substrings:

```text
Length 3: "abc", "bca", "cab", "abc"      (4 substrings)
Length 4: "abca", "bcab", "cabc"          (3 substrings)
Length 5: "abcab", "bcabc"                (2 substrings)
Length 6: "abcabc"                        (1 substring)

Total = 4 + 3 + 2 + 1 = 10
```

---

# 1. Brute Force

Generate every substring and check if it contains `'a'`, `'b'`, and `'c'`.

```cpp
int numberOfSubstrings(string s) {
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        unordered_set<char> seen;

        for (int j = i; j < s.size(); j++) {
            seen.insert(s[j]);

            if (seen.size() == 3) {
                // If substring s[i..j] contains all 3,
                // every extension s[i..k] (where k >= j) also contains all 3
                count += (s.size() - j);
                break;
            }
        }
    }

    return count;
}
```

### Complexity

```text
Time:  O(N²)
Space: O(1)
```

---

# 2. Optimal — Last Seen Array

Instead of checking windows repeatedly, keep track of the **most recent index** where each character `'a'`, `'b'`, and `'c'` appeared.

For any current index `i`:
- Update the last-seen index of `s[i]`.
- If all three characters have been seen at least once, the smallest valid window ending at `i` starts at:

```text
minStart = min(lastSeen['a'], lastSeen['b'], lastSeen['c'])
```

Because `s[minStart ... i]` contains `'a'`, `'b'`, and `'c'`, any substring starting before `minStart` (from index `0` up to `minStart`) and ending at `i` will **also** contain all three characters.

Therefore, the number of valid substrings ending at index `i` is:

```text
minStart + 1
```

---

# 3. Complete Optimal Solution

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                int minStart = min({lastSeen[0], lastSeen[1], lastSeen[2]});
                count += (minStart + 1);
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    string s = "abcabc";
    cout << sol.numberOfSubstrings(s) << endl; // Output: 10
    return 0;
}
```

---

# 4. Dry Run

```text
s = "abcabc"
lastSeen = [-1, -1, -1]
count = 0
```

| `i` | `s[i]` | `lastSeen` (`[a, b, c]`) | All 3 seen? | `minStart = min(lastSeen)` | `count += minStart + 1` | Total `count` | Valid Substrings Ending at `i` |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---|
| 0 | `'a'` | `[0, -1, -1]` | No | — | 0 | 0 | None |
| 1 | `'b'` | `[0, 1, -1]` | No | — | 0 | 0 | None |
| 2 | `'c'` | `[0, 1, 2]` | Yes | `min(0, 1, 2) = 0` | `0 + 1 = 1` | 1 | `s[0..2]` ("abc") |
| 3 | `'a'` | `[3, 1, 2]` | Yes | `min(3, 1, 2) = 1` | `1 + 1 = 2` | 3 | `s[0..3]`, `s[1..3]` ("abca", "bca") |
| 4 | `'b'` | `[3, 4, 2]` | Yes | `min(3, 4, 2) = 2` | `2 + 1 = 3` | 6 | `s[0..4]`, `s[1..4]`, `s[2..4]` ("abcab", "bcab", "cab") |
| 5 | `'c'` | `[3, 4, 5]` | Yes | `min(3, 4, 5) = 3` | `3 + 1 = 4` | 10 | `s[0..5]`, `s[1..5]`, `s[2..5]`, `s[3..5]` ("abcabc", "bcabc", "cabc", "abc") |

Total valid substrings:

```text
10
```

---

# 5. Complexity

```text
Time:  O(N) — Single pass through string of length N
Space: O(1) — Fixed array of size 3
```

---

# 6. Memory Trick

```text
Count substrings containing at least one of all required characters:
       ↓
Keep lastSeen indices of all target characters
       ↓
At index i:
minStart = min(lastSeen)
       ↓
Valid starting points ending at i:
0, 1, ..., minStart
       ↓
count += minStart + 1
```