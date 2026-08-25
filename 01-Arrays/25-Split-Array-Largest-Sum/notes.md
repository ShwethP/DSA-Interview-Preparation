# Split Array Largest Sum

## Pattern

Binary Search on Answer
+
Greedy feasibility check

## Goal

Split the array into k contiguous non-empty
subarrays.

Minimize the largest subarray sum.

---

## Search Space

Minimum:

max(nums)

Because every element must belong to some
subarray, so the largest element itself
cannot be avoided.

Maximum:

sum(nums)

If everything is one subarray.

---

## Feasibility Check

Given maxSum:

Start with:

subarrays = 1
currentSum = nums[0]

Traverse the array.

If:

currentSum + nums[i] <= maxSum

add nums[i] to the current subarray.

Otherwise:

subarrays++
currentSum = nums[i]

At the end:

subarrays <= k

means maxSum is possible.

---

## Binary Search

We want the MINIMUM valid maximum sum.

If maxSum works:

right = mid - 1

Try a smaller maximum.

If maxSum doesn't work:

left = mid + 1

We need to allow a larger maximum.

Return:

left

---

## Monotonic Pattern

❌ ❌ ❌ ❌ ✅ ✅ ✅
            ↑
       minimum valid

---

## Edge Case

If:

k > nums.size()

return -1

because every subarray must be non-empty.

---

## Complexity

Let:

n = number of elements
S = sum of all elements

Feasibility:

O(n)

Binary Search:

O(log S)

Total:

O(n log S)

Space:

O(1)

---

## Important Pattern Recognition

This problem is very similar to:

Allocate Books

Both use:

minimum of the maximum

Search space:

max(array) → sum(array)

Feasibility:

greedily create groups while
currentSum + element <= candidate

Return:

left