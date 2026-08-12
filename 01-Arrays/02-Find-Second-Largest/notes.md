# Second Largest Element

## Problem

Find the second largest distinct element in an array.

Example:

Input:
[10, 5, 8, 20, 15]

Output:
15

---

## Important Requirement

The second largest element must be distinct from the largest.

Example:

[10, 10, 5, 8]

Largest = 10
Second largest = 8

---

# Approach 1 — Brute Force / Sorting

### Idea

1. Sort the array in ascending order.
2. Start from the largest element.
3. Move backwards while the current element is equal to the largest.
4. The first different element is the second largest.

### Example

[10, 10, 5, 8, 20, 20, 15]

After sorting:

[5, 8, 10, 10, 15, 20, 20]

Skip duplicate 20.

15 is the second largest distinct element.

### Time Complexity

O(n log n)

`std::sort()` takes O(n log n).

The backward traversal takes O(n) in the worst case.

Overall:

O(n log n)

### Auxiliary Space

O(1) for the additional variables used by our solution, while the exact space usage of the sorting implementation is implementation-dependent.

---

# Approach 2 — Optimal / Single Traversal

### Idea

Maintain two values:

- largest
- secondLargest

Traverse the array once.

If the current element is greater than `largest`:

1. Move the current `largest` into `secondLargest`.
2. Make the current element the new `largest`.

Otherwise, if the current element is:
- greater than `secondLargest`
- different from `largest`

update `secondLargest`.

### Time Complexity

O(n)

The array is traversed exactly once.

### Auxiliary Space

O(1)

Only a constant number of variables are maintained.

---

# Comparison

| Approach | Time | Auxiliary Space |
|---|---:|---:|
| Sorting | O(n log n) | Implementation-dependent |
| Single traversal | O(n) | O(1) |

---

# Key Learning

We don't always need to sort an array to find its largest values.

If we only need the top two distinct values, we can maintain:

largest
secondLargest

while traversing the array.

This reduces the time complexity from O(n log n) to O(n).

---

# Pattern

Maintaining multiple values while performing a single traversal.

---

# Edge Cases

- Array contains only one element.
- All elements are identical.
- Largest element appears multiple times.
- Array contains negative numbers.
- Array contains exactly two distinct values.

---

# Interview Explanation

"I don't need to sort the array because I only need the two largest distinct values. I can maintain the largest and second largest values while traversing the array once. Whenever I find a new largest value, the previous largest becomes the second largest. This gives O(n) time and O(1) auxiliary space."

## Mistake / Learning

Initially, I thought my approach might be wrong because I was unsure how to handle duplicates.

The important edge case is that the second largest must be distinct.

For example:

[10, 10, 5, 8]

The answer is 8, not 10.

I also learned that when traversing backwards after sorting, I must ensure I don't access an index below 0.