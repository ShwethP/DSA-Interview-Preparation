# Count Number of Nice Subarrays — Sliding Window

## Problem

Given an array of integers `nums` and an integer `k`, return the number of continuous subarrays that contain exactly `k` odd numbers.

Example:

```text
nums = [1, 1, 2, 1, 1]
k = 3

Answer = 2
```

Valid subarrays:

```text
[1, 1, 2, 1]      indices 0..3 (contains three 1s: 1, 1, 1)
[1, 2, 1, 1]      indices 1..4 (contains three 1s: 1, 1, 1)
```

---

# 1. Brute Force

Generate every subarray and count how many odd numbers it contains.

```cpp
int numberOfSubarrays(vector<int>& nums, int k) {
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        int oddCount = 0;

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] % 2 != 0) {
                oddCount++;
            }

            if (oddCount == k) {
                count++;
            } else if (oddCount > k) {
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

# 2. Optimal — Transformation to Binary Subarray Sum

Every odd number contributes `1` to the count, and every even number contributes `0`.

```text
Odd number  → 1
Even number → 0
```

Therefore, finding subarrays with **exactly `k` odd numbers** is identical to finding subarrays with **sum equal to `k`** in a binary array.

We apply the same identity:

```text
exactly(k) = atMost(k) - atMost(k - 1)
```

---

# 3. How AtMost(K) Works

Maintain:

```text
left
right
oddCount
```

`oddCount` = total count of odd numbers inside the current window `[left, right]`.

If:

```text
oddCount > k
```

the window has too many odd numbers. Move `left` forward until:

```text
oddCount <= k
```

Whenever the window is valid, the number of valid subarrays ending at `right` is:

```text
right - left + 1
```

---

# 4. AtMost Code

```cpp
int atMost(vector<int>& nums, int k) {
    if (k < 0) return 0;

    int left = 0;
    int oddCount = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] % 2 != 0) {
            oddCount++;
        }

        while (oddCount > k) {
            if (nums[left] % 2 != 0) {
                oddCount--;
            }
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}
```

---

# 5. Complete Optimal Solution

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int atMost(const vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int oddCount = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl; // Output: 2
    return 0;
}
```

---

# 6. Dry Run

```text
nums = [1, 1, 2, 1, 1], k = 3
```

Calculate:

```text
exactly(3) = atMost(3) - atMost(2)
```

For `atMost(3)`:

```text
right = 0 (1): odds = 1 <= 3 → count += 1 (total: 1)
right = 1 (1): odds = 2 <= 3 → count += 2 (total: 3)
right = 2 (2): odds = 2 <= 3 → count += 3 (total: 6)
right = 3 (1): odds = 3 <= 3 → count += 4 (total: 10)
right = 4 (1): odds = 4 > 3  → shrink left until odds <= 3
               left moves past index 0 (odds drops to 3)
               window is [1, 2, 1, 1], length = 4 → count += 4 (total: 14)
```

Total `atMost(3)` = 14

For `atMost(2)`:

```text
right = 0 (1): odds = 1 <= 2 → count += 1 (total: 1)
right = 1 (1): odds = 2 <= 2 → count += 2 (total: 3)
right = 2 (2): odds = 2 <= 2 → count += 3 (total: 6)
right = 3 (1): odds = 3 > 2  → shrink left past index 0 → count += 3 (total: 9)
right = 4 (1): odds = 3 > 2  → shrink left past index 1 → count += 3 (total: 12)
```

Total `atMost(2)` = 12

Therefore:

```text
14 - 12 = 2
```

Answer:

```text
2
```

---

# 7. Complexity

Each `atMost()` call:

```text
Time:  O(N)
Space: O(1)
```

We call it twice:

```text
O(N) + O(N) = O(N)
```

Final:

```text
Time:  O(N)
Space: O(1)
```

---

# 8. Memory Trick

```text
Count exact odd numbers
       ↓
Odd = 1, Even = 0
       ↓
Binary Subarray Sum problem
       ↓
exactly(K) = atMost(K) - atMost(K-1)
       ↓
O(1) extra space
```