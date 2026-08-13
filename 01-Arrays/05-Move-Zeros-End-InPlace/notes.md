# Move Zeroes

## Problem

Move all zeroes to the end of the array while maintaining the relative order of all non-zero elements.

The operation should be performed in-place.

Example:

[0, 1, 0, 3, 12]

Output:

[1, 3, 12, 0, 0]

---

## Approach 1 — Extra Space

Create another array.

1. Traverse the original array.
2. Add every non-zero element to the new array.
3. Add the required number of zeroes at the end.

Time Complexity:
O(n)

Auxiliary Space:
O(n)

This works but does not satisfy the in-place requirement.

---

## Approach 2 — Optimal — Two Pointers

Use two pointers:

- `j` scans every element.
- `i` represents the next position where a non-zero element should be placed.

Whenever `a[j]` is non-zero:

1. Swap `a[i]` and `a[j]`.
2. Increment `i`.

Zeroes are naturally pushed toward the end.

---

## Example

Input:

[0, 1, 0, 3, 12]

After processing 1:

[1, 0, 0, 3, 12]

After processing 3:

[1, 3, 0, 0, 12]

After processing 12:

[1, 3, 12, 0, 0]

---

## Time Complexity

O(n)

The array is traversed once.

---

## Auxiliary Space

O(1)

Only two pointers are used.

---

## Pattern

Two Pointers

Specifically:
- slow pointer → next position for valid/non-zero element
- fast pointer → scans the array

---

## Key Learning

When modifying an array in-place, be careful not to overwrite data that is still needed.

`swap()` can be useful when two positions need to exchange their values.

---

## Mistake / Learning

My first attempt correctly identified that one pointer should track the next position for a non-zero element and another should scan the array.

However, I used:

a[i] = a[j];
a[j] = 0;

This could overwrite the value at `a[i]`.

Using:

swap(a[i], a[j]);

preserves both values.

---

## Interview Explanation

"I can solve this in-place using two pointers. One pointer scans the array, while the other tracks the next position where a non-zero element should be placed. Whenever I find a non-zero element, I swap it into that position. This preserves the relative order of non-zero elements and takes O(n) time with O(1) auxiliary space."