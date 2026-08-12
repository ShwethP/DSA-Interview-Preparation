# Check if Array Is Sorted

## Problem

Given an array, determine whether it is sorted in non-decreasing order.

Non-decreasing means:

a[i] <= a[i + 1]

Duplicates are allowed.

---

## Examples

[1, 2, 3, 4, 5] -> true

[1, 2, 2, 3, 5] -> true

[1, 3, 2, 4] -> false

---

## Approach — Adjacent Comparison

Compare every element with the element immediately after it.

If:

a[i] > a[i + 1]

then the array is not sorted.

Return false immediately.

If no violation is found after checking all adjacent pairs, return true.

---

## Why This Works

For an array to be sorted in non-decreasing order, every adjacent pair must satisfy:

a[i] <= a[i + 1]

If even one adjacent pair violates this condition, the entire array cannot be sorted.

---

## Time Complexity

Worst Case: O(n)

We may need to inspect every adjacent pair.

Best Case: O(1)

If the first adjacent pair is out of order, we stop immediately.

---

## Auxiliary Space

O(1)

Only a constant amount of extra memory is used.

---

## Edge Cases

- Empty array -> true
- Single element -> true
- Duplicate values -> allowed
- Negative values -> works
- Descending array -> false
- Already sorted array -> true

---

## Pattern

Adjacent comparison / single-pass traversal.

---

## Interview Explanation

"To check whether an array is sorted in non-decreasing order, I compare each element with the next element. If I find any pair where the current element is greater than the next element, I immediately return false. If I finish the traversal without finding such a pair, the array is sorted. This takes O(n) time and O(1) auxiliary space."

---

## Key Learning

We don't need to compare every element with every other element.

Checking adjacent pairs is sufficient because a sorted array must have every adjacent pair in the correct order.