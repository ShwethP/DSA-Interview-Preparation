# Remove Duplicates from Sorted Array

## Problem

Given a sorted array, remove duplicates in-place.

Example:

[1, 1, 2, 2, 3, 3, 4]

Result:

[1, 2, 3, 4]

---

## Important Property

The array is sorted.

Therefore, duplicate values are adjacent.

This allows us to detect duplicates by comparing neighboring/previous unique values.

---

## Approach 1 — Extra Space

Maintain a second vector.

For each element:
- If the result vector is empty, add it.
- Otherwise, compare the current element with the last element in the result.
- If different, add it.

Time: O(n)

Auxiliary Space: O(n)

### Important

This is efficient in time but does not satisfy the true in-place requirement because it creates another vector.

---

## Approach 2 — Optimal — Two Pointers

Use two pointers:

- `i` → position of the last unique element
- `j` → scans the array

If:

a[j] != a[i]

then a new unique element has been found.

Move `i` forward and copy `a[j]` to `a[i]`.

Time: O(n)

Auxiliary Space: O(1)

---

## Why Does Sorted Order Matter?

Because duplicates are guaranteed to be adjacent.

Without sorting, duplicates could appear anywhere.

Example:

[3, 1, 2, 3, 1]

In that case, a HashSet can be used to track values already seen.

---

## Pattern

Two Pointers

Specifically:

Slow pointer + Fast pointer

---

## Key Learning

Always look for useful properties in the input.

Here, the sorted property allows us to solve the problem without a HashSet.

---

## Interview Explanation

"Because the array is sorted, duplicates will appear next to each other. I can use two pointers: one pointer keeps track of the position of the last unique element, while the other scans the array. When a new unique value is found, I place it after the previous unique value. This modifies the array in-place and takes O(n) time and O(1) auxiliary space."