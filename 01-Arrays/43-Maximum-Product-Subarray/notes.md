# Maximum Product Subarray

## Problem

Given an integer array `a`, find the contiguous subarray that has the **largest product**, and return that product.

### Example

```text
Input:  [2, 3, -2, 4]
Output: 6

Explanation:
[2, 3] → 6
```

---

# 1. Brute Force

Generate every possible subarray and calculate its product.

```cpp
int maxProductSubarray(vector<int>& a) {
    int maxProd = a[0];

    for (int i = 0; i < a.size(); i++) {
        int currentProd = 1;

        for (int j = i; j < a.size(); j++) {
            currentProd *= a[j];
            maxProd = max(maxProd, currentProd);
        }
    }

    return maxProd;
}
```

### Complexity

```text
Time:  O(N²)
Space: O(1)
```

---

# 2. Optimal — Track Maximum AND Minimum

This problem is tricky because of **negative numbers**.

A negative number can turn the smallest negative product into the largest positive product.

Example:

```text
-2 × 3 = -6
-2 × -3 = 6
```

Therefore, at every position we need to remember:

```text
currentMax → maximum product ending at this position
currentMin → minimum product ending at this position
```

We need both because:

```text
negative × minimum negative = maximum positive
```

### At every element `x`, there are 3 possibilities:

```text
x
x × previousMax
x × previousMin
```

So:

```cpp
newMax = max(x, x * previousMax, x * previousMin)
newMin = min(x, x * previousMax, x * previousMin)
```

We also keep a global `answer`.

---

## Optimal Code

```cpp
int maxProductSubarray(vector<int>& a) {
    if (a.empty()) return 0;

    int maxProd = a[0];
    int minProd = a[0];
    int answer = a[0];

    for (int i = 1; i < a.size(); i++) {
        int current = a[i];

        int oldMax = maxProd;
        int oldMin = minProd;

        maxProd = max({
            current,
            current * oldMax,
            current * oldMin
        });

        minProd = min({
            current,
            current * oldMax,
            current * oldMin
        });

        answer = max(answer, maxProd);
    }

    return answer;
}
```

---

# Why do we need `minProd`?

Consider:

```text
[-2, 3, -4]
```

After processing `-2`:

```text
max = -2
min = -2
```

After `3`:

```text
max = 3
min = -6
```

Now we encounter `-4`.

The minimum product is:

```text
-6
```

Multiplying it by `-4` gives:

```text
24
```

So the previously "bad" minimum becomes the new maximum.

That's why we cannot track only the maximum.

---

# What about 0?

Zero automatically breaks the previous product chain.

Example:

```text
[2, 3, 0, -2, -4]
```

When `current = 0`:

```text
current
current * oldMax
current * oldMin
```

all become `0`.

Then the algorithm starts building a new product from the next element.

---

# Important Edge Case

Do NOT initialize everything to `0`.

For example:

```text
[-5]
```

The answer is:

```text
-5
```

not `0`.

Therefore initialize from the first element:

```cpp
int maxProd = a[0];
int minProd = a[0];
int answer = a[0];
```

---

# Complexity

```text
Time:  O(N)
Space: O(1)
```

---

# Memory Trick

### Maximum Product Subarray

> **Negative can flip the answer → track BOTH max and min.**

At every element:

```text
x
x × max
x × min
```

Take the maximum for `maxProd` and minimum for `minProd`.

### Pattern

```text
Max Product
     ↓
Negative numbers matter
     ↓
Track max + min
     ↓
O(N), O(1)
```
