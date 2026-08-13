# Left Rotate Array by One

## Problem

Given an array, rotate all elements one position to the left.

Example:

[1, 2, 3, 4, 5]

becomes:

[2, 3, 4, 5, 1]

---

## Approach 1 — Repeated Swapping

Maintain two indices:

i = 0
j = 1

Swap a[i] and a[j], then increment both.

This effectively moves the first element one position to the right repeatedly until it reaches the end.

Time Complexity:
O(n)

Auxiliary Space:
O(1)

---

## Approach 2 — Shift

1. Store the first element in a temporary variable.
2. Shift every remaining element one position to the left.
3. Put the stored first element at the end.

Example:

[1, 2, 3, 4, 5]

Store 1.

Shift:

[2, 3, 4, 5, 5]

Put 1 at the end:

[2, 3, 4, 5, 1]

Time Complexity:
O(n)

Auxiliary Space:
O(1)

---

## Edge Cases

Empty array:
[]

Single element:
[5] → [5]

Two elements:
[1,2] → [2,1]

---

## Key Learning

There can be multiple correct algorithms with the same Big-O complexity.

Big-O describes how the algorithm scales with input size, but it does not mean every O(n) algorithm performs exactly the same number of operations.

---

## Interview Explanation

"I can store the first element, shift all remaining elements one position to the left, and then place the stored element at the end. This takes O(n) time and O(1) auxiliary space."