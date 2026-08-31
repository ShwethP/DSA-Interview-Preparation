============================================================
PROBLEM 37: LONGEST SUBARRAY WITH SUM K
============================================================

Given an array containing ONLY POSITIVE numbers and an integer K,
find the length of the longest contiguous subarray whose sum is K.

Example:

a = {1, 2, 1, 1, 1, 3, 2}
k = 5

Possible valid subarrays:

{1, 2, 1, 1}     → sum = 5 → length 4
{2, 1, 1, 1}     → sum = 5 → length 4
{1, 1, 3}        → sum = 5 → length 3

Answer = 4


============================================================
BRUTE FORCE
============================================================

Generate every possible subarray.

For each starting index i:

    currentSum = 0

    for j = i → n-1:

        currentSum += a[j]

        if currentSum == k:
            update maxLen

        if currentSum > k:
            break

Because all numbers are positive, adding more elements can
never bring the sum back down.


CODE:

int longestSubarrayBrute(vector<int>& a, int k) {

    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {

        int currentSum = 0;

        for(int j = i; j < a.size(); j++) {

            currentSum += a[j];

            if(currentSum == k) {
                maxLen = max(maxLen, j - i + 1);
            }

            if(currentSum > k) {
                break;
            }
        }
    }

    return maxLen;
}


TIME:

    O(N²)

SPACE:

    O(1)


============================================================
OPTIMAL — SLIDING WINDOW
============================================================

Maintain a window:

    [l ........ r]

and its current sum.


Expand:

    r++

Add:

    sum += a[r]


If:

    sum > k

the window is too large.

Shrink from the left:

    sum -= a[l]
    l++


Continue until:

    sum <= k


When:

    sum == k

we have a valid subarray.

Update:

    maxLen = max(maxLen, r-l+1)


============================================================
CODE
============================================================

int longestSubarray(vector<int>& a, int k) {

    int l = 0;
    int sum = 0;
    int maxLen = 0;

    for(int r = 0; r < a.size(); r++) {

        sum += a[r];

        while(sum > k) {
            sum -= a[l];
            l++;
        }

        if(sum == k) {
            maxLen = max(maxLen, r - l + 1);
        }
    }

    return maxLen;
}


============================================================
WHY DOES SLIDING WINDOW WORK?
============================================================

Because the array contains positive numbers.

When we move r:

    sum ALWAYS increases.


When we move l:

    sum ALWAYS decreases.


Therefore:

    sum > k

means we need to shrink.


And:

    sum < k

means we need to expand.


This predictable behavior is what makes sliding window possible.


============================================================
WHY DOES IT FAIL WITH NEGATIVE NUMBERS?
============================================================

With negatives:

    adding an element might increase OR decrease sum.

    removing an element might increase OR decrease sum.


Example:

    [6, -2, 1]

k = 5

After seeing:

    [6]

sum = 6 > 5

We might remove 6.

But:

    [6, -2, 1]

has sum:

    6 - 2 + 1 = 5

So throwing away 6 was incorrect.


Therefore:

POSITIVE NUMBERS:

    Sliding Window ✅


NEGATIVE NUMBERS:

    Simple Sliding Window ❌

Use:

    Prefix Sum + HashMap


============================================================
COMPLEXITY
============================================================

Brute:

    Time  = O(N²)
    Space = O(1)


Optimal:

    Time  = O(N)
    Space = O(1)


Why O(N)?

r moves forward at most N times.

l also moves forward at most N times.

Total:

    O(2N) = O(N)


============================================================
IMPORTANT PATTERN
============================================================

"Longest subarray"

+

"sum equals K"

+

"all numbers are positive"

        ↓

SLIDING WINDOW


If negative numbers are allowed:

        ↓

PREFIX SUM + HASHMAP


============================================================
KEY MEMORY RULE
============================================================

Sliding Window works when the condition has predictable
movement.

Positive numbers give:

    expand → sum increases
    shrink → sum decreases

Negative numbers destroy that guarantee.


============================================================