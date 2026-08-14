# Left Rotate Array by K Positions

## Problem

Rotate an array to the left by K positions.

Example:

[1,2,3,4,5,6,7]

K = 3

Output:

[4,5,6,7,1,2,3]

---

# Approach 1 — Repeated Left Rotation

Rotate the array left by one position K times.

The left rotation by one can be performed using swaps.

### Optimization

Rotating an array of size n by n positions returns the original array.

Therefore:

k = k % n

This prevents unnecessary rotations when K is very large.

### Complexity

One rotation = O(n)

K rotations = O(nk)

Since after modulo k < n, worst case:

O(n²)

Auxiliary Space:

O(1)

---

# Approach 2 — Reversal Algorithm

To left rotate by K:

1. Reverse the first K elements.
2. Reverse the remaining elements.
3. Reverse the entire array.

Example:

[1,2,3,4,5,6,7]

K = 3

Reverse first part:

[3,2,1,4,5,6,7]

Reverse second part:

[3,2,1,7,6,5,4]

Reverse entire array:

[4,5,6,7,1,2,3]

---

## Complexity

Time:

O(n)

Three reversals are performed, but constants are ignored in Big-O.

Auxiliary Space:

O(1)

The array is modified in-place.

---

# Important Edge Cases

- Empty array
- Single element
- K = 0
- K = 1
- K = n
- K > n
- Very large K

Always calculate:

k = k % n

after checking that the array is not empty.

---

# Key Learning

Repeated work can often be optimized.

Instead of rotating K times, we can recognize that rotation is essentially moving two blocks and use the reversal algorithm.

---

# Interview Explanation

"The brute-force approach is to rotate the array one position at a time K times, which takes O(n²) in the worst case. We can optimize this using the reversal algorithm. We reverse the first K elements, reverse the remaining elements, and finally reverse the entire array. This gives O(n) time and O(1) auxiliary space."