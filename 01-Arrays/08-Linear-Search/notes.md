# Linear Search

## Problem

Given an array and a target value, find the index of the target.

Return -1 if the target does not exist.

Example:

[1,3,4,6,7,8,9]

target = 7

Output:
4

---

## Approach

Traverse the array from left to right.

For every element:
- Compare it with the target.
- If equal, return its index.
- If the loop finishes without finding it, return -1.

---

## Complexity

Best Case:
O(1)

The target is the first element.

Worst Case:
O(n)

The target is the last element or doesn't exist.

Auxiliary Space:
O(1)

---

## Important Observation

Linear search works on both sorted and unsorted arrays.

However, it does not take advantage of a sorted array.

If the array is sorted, we can potentially eliminate half of the search space at each step.

This leads to Binary Search.

---

## Pattern

Linear Traversal / Brute Force Search