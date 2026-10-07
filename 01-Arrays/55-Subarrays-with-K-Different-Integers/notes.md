# Subarrays with K Different Integers — Sliding Window

## Problem

Given an integer array `nums` and an integer `k`, return the number of good subarrays where the number of distinct integers is exactly `k`.

Example:

```text
nums = [1, 2, 1, 2, 3]
k = 2

Answer = 7
```

Valid subarrays:

```text
[1, 2]         indices 0..1
[1, 2, 1]      indices 0..2
[1, 2, 1, 2]   indices 0..3
[2, 1]         indices 1..2
[2, 1, 2]      indices 1..3
[1, 2]         indices 2..3
[2, 3]         indices 3..4
```

---

# 1. Brute Force

Generate every subarray and track the distinct elements using a set.

```cpp
int numOfSubarrayswithKDifInt(vector<int>& a, int k) {
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        unordered_set<int> s;

        for (int j = i; j < a.size(); j++) {
            s.insert(a[j]);

            if (s.size() == k) {
                count++;
            } else if (s.size() > k) {
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
Space: O(N)
```

---

# 2. Optimal — AtMost(K) - AtMost(K-1)

The key identity is:

```text
exactly(K) = atMost(K) - atMost(K-1)
```

For example:

```text
exactly(2)
=
atMost(2) - atMost(1)
```

Why?

`atMost(2)` contains subarrays with:

```text
1 distinct element
2 distinct elements
```

`atMost(1)` contains subarrays with:

```text
1 distinct element
```

Subtracting removes the first group, leaving only:

```text
2 distinct elements
```

Therefore:

```text
exactly(2) = atMost(2) - atMost(1)
```

---

# 3. How AtMost(K) Works

Because we only need to bound distinct elements from above, we can use a dynamic sliding window.

Maintain:

```text
left
right
freq map
```

`freq.size()` = number of unique elements inside the window.

If:

```text
freq.size() > k
```

the window is invalid.

Move `left` forward, decrement frequencies, and erase keys reaching `0` until:

```text
freq.size() <= k
```

---

# 4. Counting Valid Subarrays

This is the most important part.

Suppose:

```text
left = 1
right = 4
```

and the current window has `<= k` distinct integers.

Then every subarray ending at `right` and starting from:

```text
left, left+1, ..., right
```

is also valid because shrinking a valid window never introduces new distinct integers.

Therefore the number of valid subarrays ending at `right` is:

```text
right - left + 1
```

So:

```cpp
count += right - left + 1;
```

This is the key counting trick.

---

# 5. AtMost Code

```cpp
int atMostKDistinct(vector<int>& nums, int k) {
    if (k <= 0) return 0;

    int left = 0;
    int count = 0;
    unordered_map<int, int> freq;

    for (int right = 0; right < nums.size(); right++) {
        freq[nums[right]]++;

        while (freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
        }

        count += right - left + 1;
    }

    return count;
}
```

---

# 6. Complete Optimal Solution

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int atMostKDistinct(const vector<int>& nums, int k) {
        if (k <= 0) return 0;

        int left = 0;
        int count = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};
```

---

# 7. Dry Run

```text
nums = [1, 2, 1, 2, 3]
k = 2
```

We calculate:

```text
exactly(2)
=
atMost(2) - atMost(1)
```

For `atMost(2)`:

```text
right = 0 [1]             distinct = 1 <= 2  → count += 1 (total: 1)
right = 1 [1, 2]          distinct = 2 <= 2  → count += 2 (total: 3)
right = 2 [1, 2, 1]       distinct = 2 <= 2  → count += 3 (total: 6)
right = 3 [1, 2, 1, 2]    distinct = 2 <= 2  → count += 4 (total: 10)
right = 4 [1, 2, 1, 2, 3] distinct = 3 > 2   → shrink left to index 3
                          [2, 3] <= 2        → count += 2 (total: 12)
```

Total:

```text
atMost(2) = 12
```

For `atMost(1)`:

```text
right = 0 [1]    → count += 1 (total: 1)
right = 1 [2]    → count += 1 (total: 2)
right = 2 [1]    → count += 1 (total: 3)
right = 3 [2]    → count += 1 (total: 4)
right = 4 [3]    → count += 1 (total: 5)
```

Total:

```text
atMost(1) = 5
```

Therefore:

```text
12 - 5 = 7
```

Answer:

```text
7
```

---

# 8. Complexity

Each `atMost()` call:

```text
Time:  O(N)
Space: O(K)
```

We call it twice:

```text
O(N) + O(N) = O(N)
```

Final:

```text
Time:  O(N)
Space: O(K)
```

---

# 9. Memory Trick

Remember:

```text
EXACTLY K
    =
AT MOST K
    -
AT MOST K-1
```

And:

```text
atMost(K)
    ↓
Sliding Window
    ↓
freq.size() <= K
    ↓
count += right - left + 1
```

This pattern is especially useful for:

```text
Subarrays with exact sum
Subarrays with exact distinct integers
Substrings with exact character frequencies
```

---

# 10. Important Insight

Why does standard sliding window fail on `exactly(K)`?

Because shrinking `left` can either keep the distinct count at `K` or drop it to `K-1`. That creates ambiguity and prevents simple pointer progression.

Converting the problem into two monotonic conditions (`atMost(K)` and `atMost(K-1)`) restores monotonicity, allowing the classic `right - left + 1` window formula to work in O(N) time.