# Subarray Sum Equals K

## Problem

Given an integer array `a` and an integer `k`, find the **number of contiguous subarrays whose sum equals `k`**.

### Example

```text
Input:
a = [1, 2, 3]
k = 3

Output:
2
```

Valid subarrays:

```text
[1, 2] → 3
[3]    → 3
```

---

# 1. Brute Force

Start a subarray at every index and keep calculating its sum.

```cpp
int subarraySumK(vector<int>& a, int k) {
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        int currentSum = 0;

        for (int j = i; j < a.size(); j++) {
            currentSum += a[j];

            if (currentSum == k) {
                count++;
            }
        }
    }

    return count;
}
```

### Important

Do **not** `break` when `currentSum == k`.

There can be another valid subarray starting at the same `i`.

For example:

```text
[0, 0, 0], k = 0
```

Starting at index `0`:

```text
[0]       → 0
[0,0]     → 0
[0,0,0]   → 0
```

All three must be counted.

### Complexity

```text
Time:  O(N²)
Space: O(1)
```

---

# 2. Optimal — Prefix Sum + HashMap

The key equation is:

```text
currentPrefixSum - previousPrefixSum = k
```

Therefore:

```text
previousPrefixSum = currentPrefixSum - k
```

At every index, calculate:

```cpp
int needed = currentSum - k;
```

Then check whether `needed` has appeared before.

---

# 3. Why Store Frequency?

The HashMap stores:

```text
prefixSum → frequency
```

Example:

```text
a = [1, -1, 1, 1]
k = 2
```

Prefix sums:

```text
0 → 1 → 0 → 1 → 2
```

Notice that prefix sum `0` appears twice.

When we reach prefix sum `2`:

```text
needed = 2 - 2
       = 0
```

Since prefix sum `0` appeared twice, there are two different subarrays ending here with sum `2`.

Therefore:

```cpp
count += m[needed];
```

not simply:

```cpp
count++;
```

---

# 4. Why `m[0] = 1`?

Before processing any elements, the prefix sum is `0`.

```cpp
m[0] = 1;
```

This handles subarrays that start at index `0`.

Example:

```text
a = [1, 2]
k = 3
```

At index `1`:

```text
currentSum = 3
needed = 3 - 3
        = 0
```

Because:

```text
m[0] = 1
```

we count:

```text
[1,2]
```

---

# 5. Optimal Code

```cpp
int subarraySumK(vector<int>& a, int k) {

    unordered_map<int, int> m;

    // prefix sum 0 has occurred once
    m[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < a.size(); i++) {

        currentSum += a[i];

        int needed = currentSum - k;

        // Number of previous prefix sums equal to needed
        if (m.find(needed) != m.end()) {
            count += m[needed];
        }

        // Store frequency of current prefix sum
        m[currentSum]++;
    }

    return count;
}
```

---

# 6. Dry Run

```text
a = [1, 2, 3]
k = 3
```

Initially:

```text
m = {0 : 1}
currentSum = 0
count = 0
```

### i = 0

```text
currentSum = 1
needed = 1 - 3 = -2
```

`-2` doesn't exist.

Store:

```text
m[1]++
```

---

### i = 1

```text
currentSum = 3
needed = 3 - 3 = 0
```

`0` exists once:

```text
count += 1
```

This represents:

```text
[1,2]
```

Then:

```text
m[3]++
```

---

### i = 2

```text
currentSum = 6
needed = 6 - 3 = 3
```

`3` exists once:

```text
count += 1
```

This represents:

```text
[3]
```

Final:

```text
count = 2
```

---

# 7. Complexity

```text
Time:  O(N) average
Space: O(N)
```

The HashMap stores prefix-sum frequencies.

---

# Most Important Pattern

There are two very similar prefix-sum problems:

## Longest Subarray Sum K

Store:

```text
prefixSum → FIRST INDEX
```

Why?

We want the **longest distance** between two prefix sums.

```text
length = currentIndex - firstIndex
```

---

## Count Subarrays Sum K

Store:

```text
prefixSum → FREQUENCY
```

Why?

We want to know **how many previous prefix sums** can form a subarray with sum `k`.

```text
needed = currentSum - k

count += frequency[needed]
```

---

# Memory Trick

```text
LONGEST
→ store FIRST INDEX

COUNT
→ store FREQUENCY
```

And the core equation:

```text
currentSum - previousSum = k
```

Therefore:

```text
previousSum = currentSum - k
```

### Pattern

```text
Prefix Sum
     ↓
currentSum - k
     ↓
HashMap lookup
     ↓
Count its frequency
```
