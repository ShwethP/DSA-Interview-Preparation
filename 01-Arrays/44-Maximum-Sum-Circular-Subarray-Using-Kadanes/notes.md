# Maximum Sum Circular Subarray

## Problem

Given a circular array, find the maximum sum of a **non-empty subarray**.

A circular array means the end connects back to the beginning.

### Example

```text
Input:  [5, -3, 5]
Output: 10

Explanation:
Because the array is circular, we can take:

[5] + [5] = 10
```

---

# 1. Normal Maximum Subarray

If the maximum subarray does **not wrap around**, we can simply use **Kadane's Algorithm**.

```cpp
currentMaxSum = max(a[i], currentMaxSum + a[i]);
maxSum = max(maxSum, currentMaxSum);
```

---

# 2. Maximum Wrapping Subarray

The important trick is:

```text
Maximum wrapping sum
=
Total array sum - Minimum subarray sum
```

### Why?

Suppose:

```text
[ A B C D E ]
```

A wrapping subarray could be:

```text
[A B] + [D E]
```

The excluded part is:

```text
[C]
```

Therefore:

```text
Wrapping sum
=
Total sum - excluded sum
```

To maximize the wrapping sum, we want the excluded part to have the **smallest possible sum**.

Therefore:

```text
Maximum wrapping sum
=
Total sum - Minimum subarray sum
```

---

# 3. Finding Minimum Subarray

We can use a modified version of Kadane's Algorithm.

Normal Kadane:

```cpp
currentMaxSum = max(a[i], currentMaxSum + a[i]);
```

Minimum version:

```cpp
currentMinSum = min(a[i], currentMinSum + a[i]);
```

So we calculate both:

```text
Maximum subarray sum
Minimum subarray sum
```

---

# 4. Optimal Solution

```cpp
int maxSubCircularArraySum(const vector<int>& a) {

    if (a.empty()) return 0;

    int totalSum = 0;

    int currentMaxSum = 0;
    int maxSum = a[0];

    int currentMinSum = 0;
    int minSum = a[0];

    for (int i = 0; i < a.size(); i++) {

        totalSum += a[i];

        // Maximum subarray - Kadane
        currentMaxSum = max(a[i], currentMaxSum + a[i]);
        maxSum = max(maxSum, currentMaxSum);

        // Minimum subarray - modified Kadane
        currentMinSum = min(a[i], currentMinSum + a[i]);
        minSum = min(minSum, currentMinSum);
    }

    // If all elements are negative,
    // totalSum - minSum would incorrectly give 0.
    if (maxSum < 0) {
        return maxSum;
    }

    // Either the best subarray does not wrap,
    // or it wraps around.
    return max(maxSum, totalSum - minSum);
}
```

---

# 5. Why the All-Negative Check Is Necessary

Example:

```text
[-5, -3, -5]
```

The correct answer is:

```text
-3
```

But:

```text
totalSum = -13
minSum = -13

totalSum - minSum
= -13 - (-13)
= 0
```

`0` means we selected nothing, which is invalid because the subarray must be **non-empty**.

Therefore:

```cpp
if (maxSum < 0)
    return maxSum;
```

---

# 6. Complete Example

```text
[5, -3, 5]

totalSum = 7
maxSum = 7
minSum = -3

wrappingSum = totalSum - minSum
             = 7 - (-3)
             = 10

answer = max(7, 10)
       = 10
```

---

# 7. Complexity

```text
Time:  O(N)
Space: O(1)
```

We only make one pass through the array and maintain a constant number of variables.

---

# Memory Trick

### Circular Maximum Subarray

Think:

```text
NORMAL
→ Kadane

WRAPPING
→ Total - Minimum Subarray

ANSWER
→ max(Normal, Wrapping)
```

And remember the edge case:

```text
All negative
→ return normal Kadane result
```

### One-line intuition

> **For a wrapping maximum, remove the smallest middle part from the total array.**
