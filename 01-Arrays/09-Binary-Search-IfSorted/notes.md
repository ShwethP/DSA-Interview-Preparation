# Binary Search

## Problem

Given a sorted array and a target, return the index of the target.

Return -1 if the target doesn't exist.

---

## Core Idea

Instead of checking every element, check the middle element.

Because the array is sorted:

- If a[mid] == target → found
- If a[mid] > target → search left half
- If a[mid] < target → search right half

Each iteration eliminates approximately half of the remaining search space.

---

## Algorithm

1. Set `left = 0`
2. Set `right = n - 1`
3. While `left <= right`:
   - Calculate `mid`
   - Compare `a[mid]` with target
   - Eliminate the appropriate half
4. Return -1 if the search space becomes empty.

---

## Mid Calculation

Use:

`mid = left + (right - left) / 2`

instead of:

`mid = (left + right) / 2`

because `left + right` can overflow for very large integer values.

---

## Complexity

Best Case:
O(1)

The target is immediately at the middle.

Worst Case:
O(log n)

Each iteration halves the search space.

Auxiliary Space:
O(1)

The iterative implementation uses only a few variables.

---

## Requirement

The array/search space must be sorted or otherwise ordered in a way that allows half of the search space to be eliminated.

---

## Comparison

Linear Search:
O(n)

Binary Search:
O(log n)

For very large sorted arrays, Binary Search is significantly faster.

---

## Pattern

Divide and Conquer / Search Space Reduction

---

## Interview Explanation

"Because the array is sorted, I can use binary search. I maintain left and right boundaries and check the middle element. If the middle element is smaller than the target, I discard the left half; if it's larger, I discard the right half. This halves the search space on every iteration, giving O(log n) time and O(1) auxiliary space."