============================================================
PROBLEM 29: MAXIMUM SUBARRAY
============================================================

PROBLEM:

Given an integer array, find the contiguous subarray having
the largest sum.

The subarray must be NON-EMPTY.

Example:

[-2,1,-3,4,-1,2,1,-5,4]

Maximum subarray:

[4,-1,2,1]

Sum:

4 + (-1) + 2 + 1 = 6

Answer:

6


------------------------------------------------------------
WHAT DOES CONTIGUOUS MEAN?
------------------------------------------------------------

Elements must be next to each other.

Valid:

[4,-1,2,1]

Invalid:

[4,2,1]

because -1 was skipped.


------------------------------------------------------------
BRUTE FORCE
------------------------------------------------------------

Use two loops.

i = starting position
j = ending position

Keep adding nums[j] to the current sum.

Instead of recalculating the entire subarray every time:

    sum += nums[j]

Then:

    maxSum = max(maxSum, sum)


TIME:

O(N²)


SPACE:

O(1)


------------------------------------------------------------
OPTIMAL: KADANE'S ALGORITHM
------------------------------------------------------------

TIME:

O(N)


SPACE:

O(1)


KEY IDEA:

At every element, decide:

    1. Extend the previous subarray

OR

    2. Start a new subarray from this element


Compare:

    currentSum + nums[i]

vs.

    nums[i]


Whichever is larger becomes currentSum.


------------------------------------------------------------
CORE KADANE'S CODE
------------------------------------------------------------

int currentSum = a[0];
int maxSum = a[0];

for (int i = 1; i < a.size(); i++) {

    currentSum = max(a[i], currentSum + a[i]);

    maxSum = max(maxSum, currentSum);
}


------------------------------------------------------------
WHY DOES THIS WORK?
------------------------------------------------------------

Suppose:

    currentSum = -5
    current element = 4

Two choices:

    continue:
        -5 + 4 = -1

    start fresh:
        4

Choose:

    4


A negative previous sum can only hurt the next
subarray, so we throw it away and start fresh.


------------------------------------------------------------
IMPORTANT:
ALL NEGATIVE NUMBERS
------------------------------------------------------------

Example:

[-5,-2,-8,-1]

We CANNOT return 0 because the subarray must be non-empty.

Kadane's gives:

    -1

which is correct.


------------------------------------------------------------
WHY INITIALIZE WITH a[0]?
------------------------------------------------------------

Use:

    currentSum = a[0]
    maxSum = a[0]

instead of:

    currentSum = 0
    maxSum = 0

because all elements might be negative.

Example:

[-5,-2,-8]

Correct answer:

    -2

Not:

    0


------------------------------------------------------------
RETURNING THE ACTUAL SUBARRAY
------------------------------------------------------------

Sometimes the question asks:

    "Return the maximum sum."

Then basic Kadane's is enough.


But sometimes it asks:

    "Return the maximum subarray."

Then we need to track indices.


Maintain:

    currentStart
    bestStart
    bestEnd


When starting a new subarray:

    currentStart = i


When we find a better maximum:

    bestStart = currentStart
    bestEnd = i


------------------------------------------------------------
KADANE'S WITH INDICES
------------------------------------------------------------

int maxSubarraySum(vector<int>& a) {

    int currentSum = a[0];
    int maxSum = a[0];

    int currentStart = 0;
    int bestStart = 0;
    int bestEnd = 0;

    for (int i = 1; i < a.size(); i++) {

        if (a[i] > currentSum + a[i]) {

            currentSum = a[i];
            currentStart = i;

        }
        else {

            currentSum += a[i];
        }

        if (currentSum > maxSum) {

            maxSum = currentSum;

            bestStart = currentStart;
            bestEnd = i;
        }
    }

    // actual maximum subarray:
    // a[bestStart ... bestEnd]

    return maxSum;
}


------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

[-2,1,-3,4,-1,2,1,-5,4]

Best subarray:

    [4,-1,2,1]

Indices:

    3 → 6


So:

    bestStart = 3
    bestEnd = 6


------------------------------------------------------------
COMPLEXITY
------------------------------------------------------------

Basic Kadane:

Time:
    O(N)

Space:
    O(1)


Kadane + indices:

Time:
    O(N)

Space:
    O(1)

If we actually create and return a new vector containing
the subarray, the OUTPUT itself requires:

    O(K)

where K is the size of the returned subarray.


------------------------------------------------------------
BRUTE FORCE vs KADANE
------------------------------------------------------------

BRUTE FORCE:

    Two loops

    Time:  O(N²)
    Space: O(1)


KADANE:

    One loop

    Time:  O(N)
    Space: O(1)


------------------------------------------------------------
KEY INTERVIEW QUESTION
------------------------------------------------------------

At every element ask:

    "Should I extend the previous subarray,
     or start a new one here?"


Formula:

    currentSum =
        max(a[i], currentSum + a[i])


Then:

    maxSum =
        max(maxSum, currentSum)


------------------------------------------------------------
KEY PATTERN
------------------------------------------------------------

NEGATIVE PREFIX?

    Throw it away.

POSITIVE PREFIX?

    Keep extending it.

Every element makes a choice:

    EXTEND
       OR
    RESTART


============================================================