# Trapping Rain Water

## Problem

Given an array where each element represents the height of a bar, calculate how much rainwater can be trapped between the bars.

### Example

```text
Input:
[0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6
```

---

# 1. Core Idea

For every index `i`, the amount of water depends on the tallest wall:

* on the left
* on the right

The water level is determined by the shorter of those two walls.

```text
water at i
=
min(maxLeft, maxRight) - height[i]
```

If the result is negative, we don't add water.

---

# 2. Brute Force

For every index:

1. Find the maximum height on the left.
2. Find the maximum height on the right.
3. Take the smaller of the two.
4. Subtract the current height.
5. Add the result to `totalWater`.

```cpp
int trap(vector<int>& a) {
    int n = a.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++) {

        int leftMax = 0;

        for (int j = 0; j < i; j++) {
            leftMax = max(leftMax, a[j]);
        }

        int rightMax = 0;

        for (int k = i + 1; k < n; k++) {
            rightMax = max(rightMax, a[k]);
        }

        int minHeight = min(leftMax, rightMax);

        if (minHeight > a[i]) {
            totalWater += minHeight - a[i];
        }
    }

    return totalWater;
}
```

### Complexity

```text
Time:  O(N²)
Space: O(1)
```

---

# 3. Optimal — Two Pointers

The brute-force solution repeatedly searches for `leftMax` and `rightMax`.

Instead, maintain two pointers:

```text
left  → 
← right
```

and two maximum heights:

```cpp
int leftMax = 0;
int rightMax = 0;
```

---

# 4. Key Observation

If:

```text
height[left] <= height[right]
```

we process the **left side**.

Why?

Because we already know there is a right boundary at least as tall as the current left bar.

So the water on the left can be determined using `leftMax`.

Otherwise:

```text
height[right] < height[left]
```

we process the **right side**.

---

# 5. Optimal Code

```cpp
int trap(vector<int>& a) {
    int n = a.size();

    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int totalWater = 0;

    while (left < right) {

        if (a[left] <= a[right]) {

            if (a[left] >= leftMax) {
                leftMax = a[left];
            } else {
                totalWater += leftMax - a[left];
            }

            left++;

        } else {

            if (a[right] >= rightMax) {
                rightMax = a[right];
            } else {
                totalWater += rightMax - a[right];
            }

            right--;
        }
    }

    return totalWater;
}
```

---

# 6. How the Two-Pointer Logic Works

Remember:

```text
height[left] <= height[right]
        ↓
process left
```

Otherwise:

```text
height[left] > height[right]
        ↓
process right
```

For the side being processed:

### If current height is higher than the known maximum

Update the maximum:

```cpp
leftMax = a[left];
```

or:

```cpp
rightMax = a[right];
```

### If current height is lower than the maximum

Water can be trapped:

```cpp
totalWater += leftMax - a[left];
```

or:

```cpp
totalWater += rightMax - a[right];
```

---

# 7. Example

```text
[3, 0, 2]
```

At the beginning:

```text
left = 0
right = 2

a[left] = 3
a[right] = 2
```

Since:

```text
3 > 2
```

process the right side.

`rightMax` becomes `2`.

Then we encounter `0`:

```text
rightMax = 2
height = 0

water = 2 - 0
      = 2
```

Answer:

```text
2
```

---

# 8. Complexity

```text
Time:  O(N)
Space: O(1)
```

Each pointer moves only toward the other side, so every element is processed at most once.

---

# Memory Trick

### Trapping Rain Water

```text
Water at i
=
min(leftMax, rightMax) - height[i]
```

Brute:

```text
For every index
→ find leftMax
→ find rightMax
→ calculate water
```

Optimal:

```text
Two pointers
→ leftMax
→ rightMax
→ process the side with smaller boundary
```

### Most important rule

```text
a[left] <= a[right]
        → process LEFT

a[left] > a[right]
        → process RIGHT
```

**Pattern:** Two Pointers + Running Maximums.
