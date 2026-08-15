# Lower Bound / Search Insert Position

## Problem

Given a sorted array and a target, find the index where the target should be
inserted so that the array remains sorted.

This is equivalent to finding the first index where:

a[index] >= target

---

## Binary Search Logic

If:

a[mid] < target

Then mid is too small, so:

left = mid + 1

If:

a[mid] >= target

Then mid may be the answer, but there could be an earlier valid position:

right = mid - 1

After the loop:

left

is the answer.

---

## Why return left?

When the loop ends:

left > right

Everything before `left` is < target.

Everything from the valid boundary onward is >= target.

Therefore `left` is the first valid insertion position.

---

## Examples

[1,3,5,6]

target = 5 → 2
target = 2 → 1
target = 7 → 4
target = 0 → 0

---

## Complexity

Time: O(log n)

Space: O(1)

---

## Important Pattern

This is not simply searching for a value.

We are searching for a BOUNDARY.

We want:

first position where condition becomes true.

For lower bound:

a[index] >= target

---

## Important Insight

If target is larger than every element:

left becomes n.

For example:

[2,5,6,10]

target = 20

left = 4

So the insertion position is index 4, after the last element.