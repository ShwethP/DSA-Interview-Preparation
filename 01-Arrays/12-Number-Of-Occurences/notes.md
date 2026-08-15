# Count Occurrences in Sorted Array

## Problem

Given a sorted array containing duplicates, count how many times a target occurs.

Example:

[1,2,2,2,4,4,4,5,7]

target = 4

First occurrence = 4
Last occurrence = 6

Count = 6 - 4 + 1
      = 3

---

## Approach

Use Binary Search to find:

1. First occurrence
2. Last occurrence

Then:

count = last - first + 1

If the first occurrence is -1, the target doesn't exist, so return 0.

---

## Complexity

First occurrence:
O(log n)

Last occurrence:
O(log n)

Total:

O(log n) + O(log n)
= O(2 log n)
= O(log n)

Auxiliary Space:
O(1)

---

## Important Big-O Rule

Constant multipliers are ignored.

O(2 log n) = O(log n)

However, if an O(log n) operation is performed n times:

O(n × log n) = O(n log n)

---

## Pattern

Combine Binary Search variations to solve more complex problems.

First occurrence:
search left after finding target.

Last occurrence:
search right after finding target.

Count:
last - first + 1