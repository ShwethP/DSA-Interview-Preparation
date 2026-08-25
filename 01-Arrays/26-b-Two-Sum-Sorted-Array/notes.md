# Two Sum — Two Pointer Approach

## Requirement

The array must be sorted.

## Approach

Use two pointers:

left = 0
right = n - 1

Calculate:

sum = nums[left] + nums[right]

If:

sum == target

    pair found

If:

sum < target

    need a larger sum
    left++

If:

sum > target

    need a smaller sum
    right--

---

## Why Does This Work?

Because the array is sorted.

If:

nums[left] + nums[right] > target

Moving left forward would make the sum
even larger.

Therefore we must decrease right.

If:

nums[left] + nums[right] < target

Moving right backward would make the sum
even smaller.

Therefore we must increase left.

---

## Complexity

If array is already sorted:

Time: O(n)
Space: O(1)

Each pointer moves only forward/backward
through the array.

Therefore the total number of pointer
movements is at most n.

---

## Important Comparison

Brute Force:

O(n²) time
O(1) space

Hash Map:

O(n) average time
O(n) space

Two Pointers:

O(n) time
O(1) space

But Two Pointers requires sorted input.

---

## Interview Insight

When you see:

- sorted array
- pair/triplet
- target sum
- find values satisfying a condition

Think:

TWO POINTERS