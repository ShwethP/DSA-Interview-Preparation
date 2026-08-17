# Find Number of Rotations

## Problem

Given a sorted array rotated some number of times, find the number of rotations.

Example:

[4,5,6,7,0,1,2]

Minimum element = 0
Minimum index = 4

Therefore:

Number of rotations = 4

---

## Key Observation

For a sorted array rotated to the right:

number of rotations = index of minimum element

Therefore, we can use the same Binary Search algorithm used to find
the minimum element.

---

## Algorithm

Use the Find Minimum in Rotated Sorted Array algorithm.

At the end:

left == right

This index is the index of the minimum element.

Return:

left

---

## Examples

[4,5,6,7,0,1,2] → 4

[3,4,5,1,2] → 3

[11,13,15,17] → 0

[2,1] → 1

[1] → 0

---

## Complexity

Time:
O(log n)

Space:
O(1)

---

## Important Pattern

Problem 17:
Find minimum VALUE → return a[left]

Problem 18:
Find minimum INDEX → return left

Same algorithm, different required output.