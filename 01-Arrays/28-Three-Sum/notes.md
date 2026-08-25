============================================================
PROBLEM 25: 3SUM
============================================================

PROBLEM:
Given an integer array, find all unique triplets
[a, b, c] such that:

    a + b + c = 0

The answer must not contain duplicate triplets.

Example:
Input:
[-1, 0, 1, 2, -1, -4]

Output:
[[-1, -1, 2], [-1, 0, 1]]


------------------------------------------------------------
BRUTE FORCE APPROACH
------------------------------------------------------------

Use 3 nested loops to check every possible combination
of 3 elements.

Logic:

for i = 0 to n-1
    for j = i+1 to n-1
        for k = j+1 to n-1

            if nums[i] + nums[j] + nums[k] == 0
                triplet found

Why j = i+1 and k = j+1?

It ensures:
    i < j < k

Therefore:
- Same index is never used twice.
- The same combination of indices is not checked repeatedly.

TIME COMPLEXITY:
O(N^3)

SPACE COMPLEXITY:
O(1) excluding output.

PROBLEM:
Checking every possible combination is too slow for large arrays.
Duplicate triplets also need to be handled.


------------------------------------------------------------
OPTIMAL APPROACH: SORT + TWO POINTERS
------------------------------------------------------------

KEY IDEA:

Convert:

    a + b + c = 0

by fixing one element:

    b + c = -a

So:

1. Sort the array.
2. Fix one element using a for loop.
3. Use two pointers for the remaining two elements.


Example:

Original:
[-1, 0, 1, 2, -1, -4]

After sorting:
[-4, -1, -1, 0, 1, 2]


For each nums[i]:

    left = i + 1
    right = n - 1

Calculate:

    sum = nums[i] + nums[left] + nums[right]


------------------------------------------------------------
TWO POINTER LOGIC
------------------------------------------------------------

IF sum < 0:

The sum is too small.

Since the array is sorted, we need a larger value.

    left++


IF sum > 0:

The sum is too large.

We need a smaller value.

    right--


IF sum == 0:

A valid triplet is found.

    store the triplet

Then:

    left++
    right--

because the current left and right elements have already
been used.


------------------------------------------------------------
DUPLICATE HANDLING
------------------------------------------------------------

There are 3 places where duplicates need to be handled.


1. DUPLICATE i

If the current fixed value is the same as the previous one:

    if(i > 0 && nums[i] == nums[i-1])
        continue;

Reason:

We have already processed this value as the first element,
so processing it again can produce duplicate triplets.


2. DUPLICATE LEFT

After finding a valid triplet:

    while(left < right && nums[left] == nums[left-1])
        left++;

Skip repeated left values.


3. DUPLICATE RIGHT

After finding a valid triplet:

    while(left < right && nums[right] == nums[right+1])
        right--;

Skip repeated right values.


IMPORTANT:

Duplicate left/right values are skipped AFTER finding a
valid triplet.


------------------------------------------------------------
WHY left < right?
------------------------------------------------------------

We need 3 different indices:

    i
    left
    right

If:

    left == right

we would use the same element twice.

Therefore:

    while(left < right)


------------------------------------------------------------
WHY SORTING IS IMPORTANT
------------------------------------------------------------

Sorting allows us to know which direction to move.

If:

    sum < 0

we need a bigger value:

    left++


If:

    sum > 0

we need a smaller value:

    right--


Without sorting, this pointer logic would not work.


------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

Sorting:

    O(N log N)

Outer loop:

    O(N)

Two pointer traversal for each i:

    O(N)

Total:

    O(N log N) + O(N^2)

Dominant term:

    O(N^2)


TIME COMPLEXITY:
O(N^2)


SPACE COMPLEXITY:
O(1)

excluding the output/result.


------------------------------------------------------------
BRUTE FORCE vs OPTIMAL
------------------------------------------------------------

Brute Force:
    3 nested loops
    Time: O(N^3)
    Space: O(1)

Optimal:
    Sort + Fix one element + Two Pointers
    Time: O(N^2)
    Space: O(1) excluding output


------------------------------------------------------------
KEY PATTERN
------------------------------------------------------------

3SUM
  ↓
Sort the array
  ↓
Fix one element
  ↓
Remaining problem becomes TWO SUM
  ↓
Use two pointers
  ↓
sum < 0  → left++
sum > 0  → right--
sum == 0 → store + move both
  ↓
Skip duplicates


------------------------------------------------------------
INTERVIEW TAKEAWAY
------------------------------------------------------------

3Sum can be optimized from O(N^3) to O(N^2) by sorting
the array, fixing one element, and solving the remaining
Two Sum problem using two pointers.

Sorting also makes duplicate handling easier.
============================================================