============================================================
PROBLEM 27: LONGEST CONSECUTIVE SEQUENCE
============================================================

PROBLEM:

Given an unsorted array of integers, find the length of the
longest consecutive sequence.

Consecutive means each number is exactly 1 greater than the
previous number.

Example:

Input:
[100, 4, 200, 1, 3, 2]

Output:
4

Because:

1, 2, 3, 4

is the longest consecutive sequence.


------------------------------------------------------------
BRUTE FORCE / SORTING APPROACH
------------------------------------------------------------

Sort the array first.

Example:

[100, 4, 200, 1, 3, 2]

        ↓ sort

[1, 2, 3, 4, 100, 200]

Then traverse the array and keep track of:

    currentStreak
    longestStreak

If:

    nums[i] == nums[i-1] + 1

then:

    currentStreak++

If duplicate:

    nums[i] == nums[i-1]

skip it.

Otherwise:

    update longestStreak
    reset currentStreak = 1


TIME COMPLEXITY:

Sorting:
    O(N log N)

Traversal:
    O(N)

Total:
    O(N log N)


SPACE COMPLEXITY:

O(1) auxiliary space if sorting in-place.


------------------------------------------------------------
OPTIMAL APPROACH: UNORDERED SET
------------------------------------------------------------

KEY IDEA:

Use an unordered_set to store all elements.

Why?

Because unordered_set provides average O(1) lookup.

We can quickly check:

    Does x exist?
    Does x + 1 exist?
    Does x - 1 exist?


Create the set:

    unordered_set<int> s(a.begin(), a.end());

Duplicates are automatically removed.


------------------------------------------------------------
MAIN OBSERVATION
------------------------------------------------------------

We should NOT start a sequence from every number.

Example:

    1, 2, 3, 4

If we start from:

    1 → 2 → 3 → 4

we find the whole sequence.

But if we also start from:

    2 → 3 → 4

and:

    3 → 4

we repeatedly scan the same sequence.

Therefore:

ONLY START A SEQUENCE IF:

    num - 1 DOES NOT EXIST.


------------------------------------------------------------
FINDING THE START OF A SEQUENCE
------------------------------------------------------------

Condition:

    if (!s.contains(num - 1))

or:

    if (s.count(num - 1) == 0)


Example:

    [1, 2, 3, 4]

For 1:

    1 - 1 = 0
    0 doesn't exist

Therefore:

    1 is the START.


For 2:

    2 - 1 = 1
    1 exists

Therefore:

    2 is NOT the start.


For 3:

    3 - 1 = 2
    2 exists

Therefore:

    3 is NOT the start.


For 4:

    4 - 1 = 3
    3 exists

Therefore:

    4 is NOT the start.


Only 1 starts the sequence.


------------------------------------------------------------
COUNTING THE SEQUENCE
------------------------------------------------------------

Once we find the starting number:

    current = num
    length = 1

Then repeatedly check:

    current + 1


If it exists:

    current++
    length++


Example:

    current = 1

    2 exists → current = 2, length = 2
    3 exists → current = 3, length = 3
    4 exists → current = 4, length = 4
    5 doesn't exist → stop


Finally:

    longest = max(longest, length)


------------------------------------------------------------
ALGORITHM
------------------------------------------------------------

1. Create an unordered_set from the array.

2. Traverse every unique number in the set.

3. Check whether num - 1 exists.

4. If num - 1 exists:
       num is not the beginning.
       Skip it.

5. If num - 1 doesn't exist:
       num is the beginning of a sequence.

6. Start checking num + 1 repeatedly.

7. Count the sequence length.

8. Update the longest sequence.


------------------------------------------------------------
CODE
------------------------------------------------------------

int longestCons(vector<int>& a) {

    unordered_set<int> s(a.begin(), a.end());

    int longest = 0;

    for (int num : s) {

        if (!s.contains(num - 1)) {

            int current = num;
            int length = 1;

            while (s.contains(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}


------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

Building the unordered_set:

    O(N) average

Traversing the set:

    O(N) average

Finding consecutive elements:

    O(N) total average

IMPORTANT:

Although there is a while loop inside the for loop,
the total work is still O(N) average.

Why?

Because we only start a sequence from its FIRST element.

Each element belongs to a sequence and is effectively
processed only as part of its sequence.

Therefore:

TIME:
    O(N) average


SPACE:
    O(N)

Because the unordered_set stores the elements.


------------------------------------------------------------
WHY THE WHILE LOOP DOES NOT MAKE IT O(N²)
------------------------------------------------------------

This is important.

At first it may look like:

    for loop
        +
    while loop

= O(N²)

But we DON'T run the while loop from every number.

For:

    1, 2, 3, 4

We only start from 1.

We don't start from 2, 3, or 4 because:

    2 - 1 exists
    3 - 1 exists
    4 - 1 exists

Therefore the sequence:

    1 → 2 → 3 → 4

is traversed only once.

This keeps the overall average complexity:

    O(N)


------------------------------------------------------------
BRUTE FORCE vs OPTIMAL
------------------------------------------------------------

SORTING:

    Sort array
    Traverse array

    Time:  O(N log N)
    Space: O(1) auxiliary


OPTIMAL:

    unordered_set
    Find sequence starts
    Count consecutive numbers

    Time:  O(N) average
    Space: O(N)


------------------------------------------------------------
IMPORTANT EDGE CASES
------------------------------------------------------------

Empty array:

    []

Answer:

    0


Single element:

    [5]

Answer:

    1


Duplicates:

    [1, 1, 2, 2, 3]

Answer:

    3

Because:

    1, 2, 3


No consecutive numbers:

    [10, 20, 30]

Answer:

    1


Negative numbers also work:

    [-3, -2, -1, 5]

Answer:

    3


------------------------------------------------------------
KEY PATTERN
------------------------------------------------------------

LONGEST CONSECUTIVE SEQUENCE

        ↓

Put everything in unordered_set

        ↓

Find sequence START

    num - 1 doesn't exist

        ↓

Keep checking:

    num + 1
    num + 2
    num + 3
    ...

        ↓

Count length

        ↓

Update maximum


------------------------------------------------------------
INTERVIEW TAKEAWAY
------------------------------------------------------------

The key optimization is to use an unordered_set for
average O(1) lookup and only start counting a sequence
when num - 1 does not exist.

This avoids repeatedly scanning the same sequence and
reduces the average time complexity from O(N log N) using
sorting to O(N) using a hash set.
============================================================