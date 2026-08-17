# Count Occurrences Using Lower Bound & Upper Bound

## Problem

Given a sorted array with duplicates, count how many times
a target occurs.

Example:

[1,2,2,2,4,4,4,4,5,7]

target = 4

Lower Bound = 4
Upper Bound = 8

Count = 8 - 4
      = 4

---

## Key Idea

Lower Bound gives:

first index where a[index] >= target

Upper Bound gives:

first index where a[index] > target

Therefore all occurrences of target lie between:

[lowerBound, upperBound)

The right boundary is exclusive.

So:

count = upperBound - lowerBound

---

## Why No +1?

Upper Bound points to the FIRST element greater than target.

Example:

[1,2,2,2,4,4,4,5]

target = 4

Lower Bound = 4
Upper Bound = 7

Indices containing 4:

4,5,6

Count:

7 - 4 = 3

The upper bound index 7 is not included.

---

## Edge Cases

Target does not exist:

lowerBound == upperBound

Therefore:

count = 0

Target occurs once:

upperBound - lowerBound = 1

Target occurs throughout the entire array:

lowerBound = 0
upperBound = n

---

## Complexity

Lower Bound:
O(log n)

Upper Bound:
O(log n)

Total:
O(log n) + O(log n)
= O(log n)

Space:
O(1)

---

## Important Pattern

Boundary searches can be combined to solve counting problems.

count = upperBound(target) - lowerBound(target)