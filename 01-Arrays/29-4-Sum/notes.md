============================================================
PROBLEM 26: 4SUM
============================================================

PROBLEM:
Given an integer array nums and an integer target, find all
unique quadruplets [a,b,c,d] such that:

    a + b + c + d = target

The answer must not contain duplicate quadruplets.

Example:

Input:
nums = [1,0,-1,0,-2,2]
target = 0

Output:
[
    [-2,-1,1,2],
    [-2,0,0,2],
    [-1,0,0,1]
]


------------------------------------------------------------
BRUTE FORCE APPROACH
------------------------------------------------------------

Use 4 nested loops to check every combination of 4 elements.

    for i
        for j
            for k
                for l

            if sum == target
                quadruplet found

TIME:
O(N^4)

SPACE:
O(1) excluding output.

Problem:
O(N^4) is too slow for large arrays.


------------------------------------------------------------
OPTIMAL APPROACH
------------------------------------------------------------

4Sum can be reduced to:

    Fix 2 elements
    +
    Two Sum using two pointers

Equation:

    a + b + c + d = target

Fix a and b:

    c + d = target - a - b

Therefore:

    for i
        for j
            left = j + 1
            right = n - 1

            use two pointers


------------------------------------------------------------
STEP 1: SORT
------------------------------------------------------------

Sort the array first:

    sort(nums.begin(), nums.end());

Why?

Because sorting allows us to control the sum using
two pointers.


------------------------------------------------------------
STEP 2: FIX FIRST ELEMENT
------------------------------------------------------------

    for (int i = 0; i < n - 3; i++)

Why n - 3?

We need 3 more elements after i:

    i + j + left + right

If there aren't 3 elements remaining, a quadruplet
cannot be formed.

Example:

n = 6

Valid i:

    0, 1, 2

So:

    i < n - 3


------------------------------------------------------------
STEP 3: FIX SECOND ELEMENT
------------------------------------------------------------

    for (int j = i + 1; j < n - 2; j++)

Now i and j are fixed.

The remaining two elements will be:

    left
    right


------------------------------------------------------------
STEP 4: TWO POINTERS
------------------------------------------------------------

    left = j + 1
    right = n - 1

Calculate:

    sum = nums[i] + nums[j]
        + nums[left] + nums[right]


------------------------------------------------------------
SUM LOGIC
------------------------------------------------------------

IF:

    sum < target

The sum is too small.

Need a larger value:

    left++


IF:

    sum > target

The sum is too large.

Need a smaller value:

    right--


IF:

    sum == target

Found a valid quadruplet.

Store it:

    result.push_back({
        nums[i],
        nums[j],
        nums[left],
        nums[right]
    });

Then:

    left++;
    right--;


------------------------------------------------------------
DUPLICATE HANDLING
------------------------------------------------------------

There are 4 places to consider duplicates.


1. DUPLICATE i

    if (i > 0 && nums[i] == nums[i - 1])
        continue;

Skip because this value was already used as
the first element.


2. DUPLICATE j

    if (j > i + 1 && nums[j] == nums[j - 1])
        continue;

Skip because this value was already used as
the second element for the current i.


3. DUPLICATE LEFT

After finding a valid quadruplet:

    while (left < right &&
           nums[left] == nums[left - 1])
        left++;


4. DUPLICATE RIGHT

    while (left < right &&
           nums[right] == nums[right + 1])
        right--;


------------------------------------------------------------
WHY left < right?
------------------------------------------------------------

left and right must represent two different elements.

If:

    left == right

we would use the same element twice.

Therefore:

    while (left < right)


------------------------------------------------------------
INTEGER OVERFLOW
------------------------------------------------------------

Use long long for the sum:

    long long sum =
        (long long)nums[i]
        + nums[j]
        + nums[left]
        + nums[right];

Why?

Four large int values can exceed the range of int.


------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

Sorting:

    O(N log N)

Two nested loops:

    O(N²)

Two-pointer scan:

    O(N)

Total:

    O(N log N) + O(N³)

Dominant term:

    O(N³)


TIME COMPLEXITY:
O(N³)


SPACE COMPLEXITY:
O(1)

excluding the output.


------------------------------------------------------------
BRUTE FORCE vs OPTIMAL
------------------------------------------------------------

BRUTE FORCE:

    4 nested loops

    Time: O(N^4)
    Space: O(1)


OPTIMAL:

    Sort
    +
    Fix i
    +
    Fix j
    +
    Two pointers

    Time: O(N^3)
    Space: O(1) excluding output.


------------------------------------------------------------
KEY PATTERN
------------------------------------------------------------

2SUM:
    Two pointers

3SUM:
    Fix 1 element
    +
    Two pointers

4SUM:
    Fix 2 elements
    +
    Two pointers


GENERAL PATTERN:

    K-Sum
      ↓
    Fix elements
      ↓
    Reduce to 2Sum
      ↓
    Two pointers


------------------------------------------------------------
INTERVIEW TAKEAWAY
------------------------------------------------------------

4Sum can be optimized from O(N^4) to O(N^3) by sorting
the array, fixing two elements, and using two pointers
for the remaining two elements.

Sorting also makes duplicate handling possible.
============================================================