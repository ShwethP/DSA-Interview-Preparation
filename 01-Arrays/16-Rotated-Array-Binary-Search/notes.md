# Search in Rotated Sorted Array

## Problem

Given a sorted array that has been rotated, search for a target.

Example:

[4,5,6,7,0,1,2]

target = 0

Output:
4

---

## Key Observation

Although the entire array is not sorted, at every step at least one half
of the current search space is sorted.

Determine which half is sorted.

---

## Step 1: Check Middle

If:

a[mid] == target

return mid.

---

## Step 2: Determine Sorted Half

### Left half sorted

If:

a[left] <= a[mid]

then:

[left ... mid]

is sorted.

Check whether target lies inside it:

a[left] <= target && target <= a[mid]

If yes:

right = mid - 1

Otherwise:

left = mid + 1

---

### Right half sorted

Otherwise, the right half is sorted.

Check:

a[mid] <= target && target <= a[right]

If yes:

left = mid + 1

Otherwise:

right = mid - 1

---

## Mental Model

1. Check mid.
2. Determine which half is sorted.
3. Check whether target belongs to that sorted half.
4. Search the appropriate half.
5. Repeat.

---

## Complexity

Time:
O(log n)

Space:
O(1)

---

## Important Condition

This version assumes the array contains distinct elements.

Duplicates require additional handling because it may be impossible to determine
which half is sorted from the boundary values alone.

---

## Interview Explanation

"Even though the array is rotated, at least one half of the current search
space is guaranteed to be sorted. I identify the sorted half and check whether
the target lies within its range. If it does, I search that half; otherwise,
I search the other half. Since the search space is reduced each iteration,
the time complexity is O(log n) and the auxiliary space is O(1)."