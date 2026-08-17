# Single Element in a Sorted Array

## Problem

Given a sorted array where every element appears exactly twice except
one element, find the element that appears only once.

Example:

[1,1,2,2,3,3,4,5,5,6,6]

Answer:

4

---

## Key Observation

Before the single element, pairs start at EVEN indices:

(0,1)
(2,3)
(4,5)

After the single element, the pairing shifts:

(7,8)
(9,10)

Therefore:

Before single:
even index → next odd index

After single:
odd index → next even index

---

## Binary Search Strategy

Always make mid EVEN.

if (mid % 2 == 1)
    mid--;

Now compare:

a[mid] and a[mid + 1]

---

## Case 1: Pair is correct

if:

a[mid] == a[mid + 1]

Then this pair is normal.

The single element must be to the RIGHT.

Therefore:

left = mid + 2

---

## Case 2: Pair is broken

if:

a[mid] != a[mid + 1]

Then the normal pairing pattern has already broken.

The single element is at mid or to the LEFT.

Therefore:

right = mid

---

## Termination

Use:

while (left < right)

Eventually:

left == right

That index contains the single element.

Return:

a[left]

---

## Example

[1,1,2,3,3,4,4]

Indices:

0 1 2 3 4 5 6

[1,1,2,3,3,4,4]

Single = 2 at index 2.

If mid = 3:

mid is odd → make it even:

mid = 2

Compare:

a[2] and a[3]

2 != 3

Pair is broken.

Therefore:

right = mid

Eventually left == right == 2.

Answer = 2.

---

## Complexity

Time:
O(log n)

Space:
O(1)

---

## Constraints

This Binary Search solution requires:

1. Array is sorted.
2. Every element appears exactly twice.
3. Exactly one element appears once.

If these conditions aren't satisfied, this particular approach does not apply.

---

## Important Pattern

This is another example of Binary Search on a boundary.

We are detecting where the normal pairing pattern breaks.