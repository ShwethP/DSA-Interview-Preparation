============================================================
PROBLEM 28: MAJORITY ELEMENT
============================================================

PROBLEM:

Given an array nums of size N, find the element that appears
MORE THAN N/2 TIMES.

It is guaranteed that a majority element exists.


Example:

[3, 2, 3]

3 appears 2 times.

N = 3

N/2 = 1

Therefore:

answer = 3


------------------------------------------------------------
APPROACH 1: BRUTE FORCE
------------------------------------------------------------

For every element:

    Count how many times it appears.

If frequency > N/2:

    return that element.


TIME:
O(N²)

SPACE:
O(1)


------------------------------------------------------------
APPROACH 2: HASHMAP
------------------------------------------------------------

Store:

    element → frequency


Example:

[2,2,1,1,1,2,2]

HashMap:

    2 → 4
    1 → 3


If:

    frequency > N/2

return that element.


TIME:
O(N) average

SPACE:
O(N)


IMPORTANT:

HashMap is useful when we need GENERAL frequency
information.

For example:

    frequency of every element
    most frequent element
    count occurrences

Boyer-Moore is specifically useful when the problem
guarantees an element occurring MORE THAN N/2 times.


------------------------------------------------------------
APPROACH 3: SORTING
------------------------------------------------------------

Sort the array.

Example:

[2,2,1,1,1,2,2]

↓

[1,1,1,2,2,2,2]

The majority element must occupy the middle position.

Therefore:

    nums[N/2]

is the answer.


TIME:
O(N log N)

SPACE:
O(1) auxiliary space if sorting in-place.


------------------------------------------------------------
APPROACH 4: BOYER-MOORE VOTING ALGORITHM
------------------------------------------------------------

Goal:

    O(N) time
    O(1) extra space


KEY IDEA:

Different elements cancel each other.

Because the majority element occurs MORE THAN N/2 times,
it has more occurrences than all other elements combined.

Therefore, after cancellation, the majority element
will survive.


------------------------------------------------------------
TWO VARIABLES
------------------------------------------------------------

candidate:

    Current possible majority element.


count:

    Current vote balance for candidate.


Initialize:

    candidate = 0
    count = 0


------------------------------------------------------------
ALGORITHM
------------------------------------------------------------

For every number num:

1. If count == 0:

       candidate = num

   The previous candidate has no remaining votes.


2. If num == candidate:

       count++


3. Otherwise:

       count--


At the end:

    candidate

is the majority element.


------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

nums:

    [2,2,1,1,1,2,2]


Start:

    candidate = ?
    count = 0


2:

    candidate = 2
    count = 1


2:

    same candidate

    count = 2


1:

    different

    count = 1


1:

    different

    count = 0


1:

    count == 0

    candidate = 1
    count = 1


2:

    different

    count = 0


2:

    count == 0

    candidate = 2
    count = 1


Final:

    candidate = 2


------------------------------------------------------------
WHY DOES IT WORK?
------------------------------------------------------------

Suppose:

    N = 7

A majority element must appear at least:

    4 times

All other elements together can appear at most:

    3 times


Worst case:

    Majority = 4
    Others   = 3

Cancel:

    4 - 3 = 1


The majority element still remains.

Therefore it survives the cancellation process.


------------------------------------------------------------
CODE
------------------------------------------------------------

int majorityElement(vector<int>& nums) {

    int candidate = 0;
    int count = 0;

    for (int num : nums) {

        if (count == 0) {
            candidate = num;
        }

        if (num == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return candidate;
}


------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

One traversal:

    O(N)


SPACE:

    O(1)


Therefore:

    Time  = O(N)
    Space = O(1)


------------------------------------------------------------
IMPORTANT LIMITATION
------------------------------------------------------------

Simple Boyer-Moore works for:

    frequency > N/2


It does NOT directly solve:

    frequency > N/3
    frequency > N/4
    most frequent element
    frequency of every element


For general frequency counting:

    unordered_map<int, int> freq;


------------------------------------------------------------
COMPARISON
------------------------------------------------------------

BRUTE FORCE:

    Time:  O(N²)
    Space: O(1)


HASHMAP:

    Time:  O(N) average
    Space: O(N)


SORTING:

    Time:  O(N log N)
    Space: O(1) auxiliary


BOYER-MOORE:

    Time:  O(N)
    Space: O(1)


------------------------------------------------------------
KEY INTERVIEW TAKEAWAY
------------------------------------------------------------

If the problem says:

    "An element appears MORE THAN N/2 times"

immediately think:

    BOYER-MOORE VOTING ALGORITHM


If the problem asks for general frequency counting:

    unordered_map


If sorting is acceptable:

    sort + middle element


============================================================