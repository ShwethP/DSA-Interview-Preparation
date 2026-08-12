# Find Largest Element

## Problem

Given an array, find the largest element.

Example:

Input:
[5, 2, 9, 1, 7]

Output:
9

---

## Approach 1 — Sorting

Sort the array and obtain the largest element.

Time Complexity:
O(n log n) using std::sort

Why it is not preferred:
We only need the largest element. Sorting the entire array performs unnecessary work.

---

## Approach 2 — Single Traversal (Optimal)

Maintain a variable `maximum`.

Initialize it to `INT_MIN`.

Traverse the array once:
- Compare the current element with `maximum`.
- If the current element is larger, update `maximum`.
- After the traversal, `maximum` contains the largest element.

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

---

## Key Learning

Do not perform work that the problem does not require.

If we only need the maximum value, sorting the entire array is unnecessary.

---

## Interview Explanation

"I don't need to sort the array because I only need the maximum element. I can traverse the array once while maintaining the largest value seen so far. This gives O(n) time and O(1) auxiliary space."

---

## Pattern

Single-pass traversal / maintaining a running maximum.

---

## Mistake / Learning

I initially thought sorting would take O(n²).

Correction:
`std::sort` is generally O(n log n), while some simple sorting algorithms such as Bubble Sort and Selection Sort are O(n²).

I also initially thought sorting automatically requires O(n) auxiliary space. That is not necessarily true; space complexity depends on the sorting algorithm/implementation.
## Approach 1 — Brute / Alternative

1. Sort the array.
2. Return the last element.

Time Complexity:
O(n log n) using std::sort

Space Complexity:
Depends on the sorting implementation; `std::sort` works in-place for the vector.

---

## Approach 2 — Optimal

1. Initialize `maximum = INT_MIN`.
2. Traverse the array once.
3. Update `maximum` whenever a larger value is found.
4. Return `maximum`.

Time Complexity:
O(n)

Auxiliary Space:
O(1)

---

## Comparison

| Approach | Time | Auxiliary Space |
|---|---:|---:|
| Sorting | O(n log n) | Implementation-dependent |
| Single traversal | O(n) | O(1) |

The optimal solution avoids sorting because sorting the entire array is unnecessary when only the maximum element is required.