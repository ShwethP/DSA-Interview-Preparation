============================================================
PROBLEM 39: LONGEST SUBARRAY WITH EQUAL 0s AND 1s
============================================================

Given a binary array, find the length of the longest contiguous
subarray containing an equal number of 0s and 1s.

Example:

a = [1, 0, 0, 1, 1, 1, 1, 0, 0]

Answer = 8

One longest subarray:

[0, 0, 1, 1, 1, 1, 0, 0]

0s = 4
1s = 4

Length = 8


============================================================
BRUTE FORCE
============================================================

Generate every possible subarray.

For each starting index:

    count0 = 0
    count1 = 0

Expand j.

Whenever:

    count0 == count1

we have a valid subarray.

Update maxLen.


CODE:

int longestSubarrayBrute(vector<int>& a) {

    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {

        int count0 = 0;
        int count1 = 0;

        for(int j = i; j < a.size(); j++) {

            if(a[j] == 0)
                count0++;
            else
                count1++;

            if(count0 == count1) {
                maxLen = max(maxLen, j - i + 1);
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
THE KEY TRICK
============================================================

Convert:

    0 → -1
    1 → +1


Why?

Suppose:

    [0, 1, 0, 1]

After conversion:

    [-1, +1, -1, +1]


Sum:

    -1 + 1 - 1 + 1 = 0


Equal number of 0s and 1s produces sum 0.


Therefore the original problem becomes:

    Find the longest subarray whose sum is 0.


This is a problem we already know how to solve.


============================================================
WHY DOES 0 → -1 WORK?
============================================================

Suppose a subarray contains:

    3 zeros
    3 ones


After conversion:

    3 × (-1) + 3 × (+1)

    = -3 + 3

    = 0


So:

    equal 0s and 1s
          ↓
    transformed sum = 0


And if:

    transformed sum = 0

then:

    number of 0s = number of 1s


============================================================
PREFIX SUM IDEA
============================================================

After conversion, we need:

    longest subarray with sum = 0


Suppose:

    prefixSum at index i = X

and an earlier prefixSum was also:

    X

Then:

    X - X = 0


Therefore the elements between those two positions
have sum 0.


So we store:

    prefixSum → FIRST INDEX


Why FIRST?

Because we want the longest possible subarray.

If the same prefix sum occurs at:

    index 2
    index 7
    index 10

and we're currently at index 10:

Using index 2:

    10 - 2 = 8

Using index 7:

    10 - 7 = 3

We want:

    8

Therefore we keep the FIRST occurrence.


============================================================
WHY m[0] = -1?
============================================================

This is extremely important.

We start with:

    m[0] = -1


It represents:

    "Prefix sum 0 existed before the array started."


Example:

    [-1, +1]

At index 1:

    currentSum = 0


We have already seen sum 0 at:

    index -1


Therefore:

    length = 1 - (-1)
           = 2


Which correctly gives:

    [-1, +1]

length = 2.


Without:

    m[0] = -1

we wouldn't correctly calculate subarrays starting at index 0.


============================================================
YOUR ALGORITHM
============================================================

Step 1:

Convert:

    0 → -1
    1 → +1


Step 2:

Create hashmap:

    prefixSum → first index


Step 3:

Initialize:

    m[0] = -1


Step 4:

Traverse the array.

Maintain:

    currentSum


Step 5:

If currentSum already exists:

    length = currentIndex - firstIndex


Update:

    maxLen


Step 6:

If currentSum has NOT been seen before:

    store its index.


IMPORTANT:

Do NOT overwrite an existing index.


============================================================
CODE
============================================================

int longestSubarray(vector<int>& a) {

    // Convert 0 → -1
    replace(a.begin(), a.end(), 0, -1);

    unordered_map<int, int> m;

    // Prefix sum 0 before the array starts
    m[0] = -1;

    int currentSum = 0;
    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {

        currentSum += a[i];

        // We need a previous prefix sum equal to currentSum
        int required = currentSum;

        if(m.find(required) != m.end()) {

            int length = i - m[required];

            maxLen = max(maxLen, length);
        }
        else {
            // Store ONLY first occurrence
            m[currentSum] = i;
        }
    }

    return maxLen;
}


============================================================
COMPLEXITY
============================================================

Brute Force:

    Time  = O(N²)
    Space = O(1)


Optimal:

    Time  = O(N) average
    Space = O(N)


============================================================
IMPORTANT CONNECTION
============================================================

We have now seen several versions of prefix sum + hashmap:


1. LONGEST SUBARRAY WITH SUM K

    prefixSum → FIRST INDEX


2. COUNT SUBARRAYS WITH SUM K

    prefixSum → FREQUENCY


3. LONGEST SUBARRAY WITH EQUAL 0s AND 1s

    Convert:

        0 → -1
        1 → +1

    Then find:

        longest subarray with sum 0

    prefixSum → FIRST INDEX


============================================================
MEMORY TRICK
============================================================

"Equal 0s and 1s"

        ↓

"Turn 0 into -1"

        ↓

"Equal 0s and 1s = sum 0"

        ↓

"Longest subarray sum 0"

        ↓

"Prefix Sum + HashMap"


============================================================
ONE SMALL IMPROVEMENT TO YOUR CODE
============================================================

You wrote:

    int k = 0;

    int required = currentSum - k;


This is mathematically correct.

But because k is ALWAYS 0 here, you can simplify it to:

    int required = currentSum;


Also, because you're modifying the input with:

    replace(a.begin(), a.end(), 0, -1);

the original array gets changed.

That's not wrong, but in interviews you can avoid modifying the
input if you want to keep it unchanged.


============================================================
FINAL PATTERN TO REMEMBER
============================================================

If the question asks:

    "Longest subarray"

and you can transform the problem into:

    "subarray sum = K"

think:

    PREFIX SUM + HASHMAP

For LONGEST:

    prefixSum → first index

For COUNT:

    prefixSum → frequency


============================================================