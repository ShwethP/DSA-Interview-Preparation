# Binary Subarrays With Sum — Sliding Window

## Problem

Given a binary array `a` and an integer `k`, count the number of subarrays whose sum is exactly `k`.

Example:

```text
a = [1,0,1,0,1]
k = 2

Answer = 4
```

Valid subarrays:

```text
[1,0,1]       indices 0..2
[1,0,1,0]     indices 0..3
[0,1,0,1]     indices 1..4
[1,0,1]       indices 2..4
```

---

# 1. Brute Force

Generate every subarray and calculate its sum.

```cpp
int binarySubArrayWithSum(vector<int>& a, int k) {
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        int sum = 0;

        for (int j = i; j < a.size(); j++) {
            sum += a[j];

            if (sum == k) {
                count++;
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
0 ones
1 one
2 ones
```

`atMost(1)` contains:

```text
0 ones
1 one
```

Subtracting removes the first two groups, leaving only:

```text
2 ones
```

Therefore:

```text
exactly(2) = atMost(2) - atMost(1)
```

---

# 3. How AtMost(K) Works

Because the array contains only `0` and `1`, we can use a sliding window.

Maintain:

```text
left
right
ones
```

`ones` = number of `1`s inside the current window.

If:

```text
ones > k
```

the window is invalid.

Move `left` forward until:

```text
ones <= k
```

---

# 4. Counting Valid Subarrays

This is the most important part.

Suppose:

```text
left = 1
right = 4
```

and the current window is valid.

Then every subarray ending at `right` and starting from:

```text
left, left+1, ..., right
```

is also valid.

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
int atMost(vector<int>& a, int k) {
    if (k < 0) return 0;

    int left = 0;
    int ones = 0;
    int count = 0;

    for (int right = 0; right < a.size(); right++) {

        if (a[right] == 1) {
            ones++;
        }

        while (ones > k) {
            if (a[left] == 1) {
                ones--;
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
int binarySubArrayWithSum(vector<int>& a, int k) {
    return atMost(a, k) - atMost(a, k - 1);
}
```

Together:

```cpp
int atMost(vector<int>& a, int k) {
    if (k < 0) return 0;

    int left = 0;
    int ones = 0;
    int count = 0;

    for (int right = 0; right < a.size(); right++) {

        if (a[right] == 1) {
            ones++;
        }

        while (ones > k) {
            if (a[left] == 1) {
                ones--;
            }

            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int binarySubArrayWithSum(vector<int>& a, int k) {
    return atMost(a, k) - atMost(a, k - 1);
}
```

---

# 7. Dry Run

```text
a = [1,0,1,0,1]
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
right = 0 → count += 1
right = 1 → count += 2
right = 2 → count += 3
right = 3 → count += 4
right = 4 → window becomes invalid,
             move left,
             count += 4
```

Total:

```text
atMost(2) = 14
```

Similarly:

```text
atMost(1) = 10
```

Therefore:

```text
14 - 10 = 4
```

Answer:

```text
4
```

---

# 8. Complexity

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
ones <= K
    ↓
count += right - left + 1
```

This pattern is especially useful for:

```text
Binary arrays
Non-negative arrays
"Exactly K" counting problems
```

---

# 10. Important Insight

The `atMost(K) - atMost(K-1)` trick is different from the prefix-sum hashmap approach.

For this problem we have two valid O(N) approaches:

### Prefix Sum + Hashmap

```text
currentSum - previousSum = K
```

### Sliding Window

```text
exactly(K) = atMost(K) - atMost(K-1)
```

The sliding-window approach works especially nicely because the array is binary/non-negative.