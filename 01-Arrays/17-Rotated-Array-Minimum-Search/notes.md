# Find Minimum in Rotated Sorted Array

## Problem

Given a sorted array rotated at an unknown position, find the minimum
element.

Example:

[4,5,6,7,0,1,2]

Answer:
0

---

## Key Observation

Compare a[mid] with a[right].

### Case 1

a[mid] > a[right]

The minimum must be to the RIGHT of mid.

Therefore:

left = mid + 1

Example:

[4,5,6,7,0,1,2]
       mid       right
        7          2

7 > 2

Minimum is to the right.

---

### Case 2

a[mid] <= a[right]

The right portion is sorted.

The minimum is either:

- at mid
- or somewhere to the LEFT of mid

Therefore:

right = mid

IMPORTANT:

Use right = mid, NOT right = mid - 1.

Why?

Because mid itself could be the minimum.

---

## Algorithm

left = 0
right = n - 1

while left < right:

    mid = left + (right - left) / 2

    if a[mid] > a[right]:
        left = mid + 1
    else:
        right = mid

return a[left]

---

## Why while(left < right)?

We are not searching for a specific target.

We are repeatedly shrinking the range until only one candidate remains.

When:

left == right

that element is the minimum.

---

## Complexity

Time:
O(log n)

Space:
O(1)

---

## Important Pattern

Normal Binary Search:

Find a target.

This problem:

Find the boundary/position of the rotation.

We keep eliminating the half that cannot contain the minimum.

---

## Assumption

This version assumes all elements are distinct.

The version with duplicates requires additional handling.