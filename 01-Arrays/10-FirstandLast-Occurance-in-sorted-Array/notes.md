# First Occurrence in Sorted Array

## Problem

Given a sorted array containing duplicates, find the index of the first occurrence of a target.

Example:

[1,2,2,2,4,5,7]

target = 2

Output:
1

---

## Key Difference From Normal Binary Search

Normal Binary Search can return immediately when:

a[mid] == target

For first occurrence, finding the target is not enough.

There may be another occurrence to the left.

---

## Approach 1 — Answer Variable

When target is found:

1. Store mid as a possible answer.
2. Continue searching left.

```cpp
answer = mid;
right = mid - 1;