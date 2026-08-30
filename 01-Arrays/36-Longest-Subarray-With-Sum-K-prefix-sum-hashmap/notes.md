============================================================
PROBLEM 33: LONGEST SUBARRAY WITH SUM K
============================================================

PROBLEM:

Given an array and an integer K, find the length of the
longest contiguous subarray whose sum is exactly K.

Example:

a = [1, 2, 3, 1, 1, 0, 1, 1]
k = 3

Answer = 4

One longest valid subarray is:

[1, 1, 0, 1]

sum = 3
length = 4


============================================================
IMPORTANT: SUBARRAY
============================================================

A subarray must be CONTIGUOUS.

For:

[1, 2, 3]

Valid subarrays:

[1]
[2]
[3]
[1,2]
[2,3]
[1,2,3]

[1,3] is NOT a subarray because 2 was skipped.


============================================================
APPROACH 1 — BRUTE FORCE
============================================================

Generate every possible starting position i.

Then extend the subarray using j.

Instead of calculating the sum from scratch every time,
maintain a running sum.

For every i:

    currentSum = 0

    for j = i → n-1:

        currentSum += a[j]

        if currentSum == k:
            update maxLen


CODE:

int longestSubarray(vector<int>& a, int k) {

    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {

        int currentSum = 0;

        for(int j = i; j < a.size(); j++) {

            currentSum += a[j];

            if(currentSum == k) {

                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}


============================================================
WHY j - i + 1?
============================================================

Suppose:

i = 2
j = 5

The subarray is:

index:  2  3  4  5

Number of elements:

5 - 2 + 1 = 4


Therefore:

length = j - i + 1


============================================================
BRUTE FORCE COMPLEXITY
============================================================

Outer loop:

    O(N)

Inner loop:

    O(N)

Therefore:

    TIME = O(N²)


Extra variables:

    currentSum
    maxLen
    i
    j

Therefore:

    SPACE = O(1)


============================================================
IMPORTANT OBSERVATION
============================================================

You noticed:

"If all numbers are positive, once currentSum > K,
we could break."

That is correct.

Example:

[2, 3, 5, 7]

K = 6

Once:

2 + 3 + 5 = 10

we know adding another positive number can never bring
the sum back down to 6.

So we can break early.

BUT this does NOT work when negative numbers are allowed.

Example:

[2, 5, -4]

K = 3

At:

2 + 5 = 7

we cannot stop because:

7 + (-4) = 3


Therefore the general solution must handle:

    positive
    negative
    zero


============================================================
APPROACH 2 — PREFIX SUM + HASHMAP
============================================================

KEY EQUATION:

Suppose:

current prefix sum = S

and we want a subarray with sum K.

If an earlier prefix sum was P:

    S - P = K

Therefore:

    P = S - K


So at every index we ask:

    "Have I seen currentSum - K before?"


If YES:

    We found a subarray whose sum is K.


============================================================
WHAT DOES PREFIX SUM MEAN?
============================================================

Prefix sum = sum of all elements from the beginning
up to the current index.


Example:

a = [1, 2, 3, 1]

Prefix sums:

index       0   1   2   3
value       1   2   3   1
prefix      1   3   6   7


At index 2:

currentSum = 6


Suppose:

K = 3


We need:

previousSum = currentSum - K

             = 6 - 3

             = 3


We previously saw prefix sum 3 at index 1.

Therefore the elements after index 1 are:

[3]

Their sum is:

3


============================================================
WHY DOES THIS WORK?
============================================================

Imagine:

prefix sum at index i = 10

Earlier prefix sum at index j = 6

Then:

10 - 6 = 4


That means:

elements from j+1 to i

have sum 4.


So if:

currentSum - previousSum = K

then:

previousSum = currentSum - K


That's the entire idea.


============================================================
WHAT DOES THE HASHMAP STORE?
============================================================

We store:

    prefixSum → FIRST index where it occurred


Example:

prefix sum = 5
first seen at index 2

Store:

    m[5] = 2


If prefix sum 5 appears again at index 7:

DO NOT replace:

    m[5] = 7


Keep:

    m[5] = 2


WHY?

Because we want the LONGEST subarray.

Earlier index gives a larger distance.


============================================================
SPECIAL CASE: PREFIX SUM = K
============================================================

Suppose:

a = [1, 2]
K = 3


At index 1:

currentSum = 3


We need:

currentSum - K

= 3 - 3

= 0


But there isn't an actual index containing prefix sum 0.

We solve this by pretending:

    prefix sum 0 exists at index -1


Therefore initialize:

    m[0] = -1


Then:

length = currentIndex - (-1)

       = 1 - (-1)

       = 2


Exactly correct.


============================================================
OPTIMAL CODE
============================================================

int longestSubarray(vector<int>& a, int k) {

    unordered_map<int, int> m;

    // Prefix sum 0 exists before the array starts
    m[0] = -1;

    int currentSum = 0;
    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {

        currentSum += a[i];

        int required = currentSum - k;

        if(m.find(required) != m.end()) {

            int length = i - m[required];

            maxLen = max(maxLen, length);
        }

        // Store only the FIRST occurrence
        if(m.find(currentSum) == m.end()) {

            m[currentSum] = i;
        }
    }

    return maxLen;
}


============================================================
DRY RUN
============================================================

a = [1, 2, 3, 1]
K = 3


Initial:

m[0] = -1
currentSum = 0
maxLen = 0


i = 0:

currentSum = 1

required = 1 - 3 = -2

-2 doesn't exist.

Store:

m[1] = 0


i = 1:

currentSum = 3

required = 3 - 3 = 0

0 exists at index -1.

length:

1 - (-1) = 2

maxLen = 2

Store:

m[3] = 1


i = 2:

currentSum = 6

required = 6 - 3 = 3

3 exists at index 1.

length:

2 - 1 = 1

maxLen remains 2.


i = 3:

currentSum = 7

required = 7 - 3 = 4

4 doesn't exist.

Store:

m[7] = 3


Final answer:

2


The longest subarray is:

[1,2]


============================================================
BRUTE FORCE vs OPTIMAL
============================================================

BRUTE FORCE:

Generate every subarray.

    Time  = O(N²)
    Space = O(1)


OPTIMAL:

Prefix sum + hashmap.

    Time  = O(N) average case
    Space = O(N)


============================================================
WHY DID TIME IMPROVE?
============================================================

BRUTE FORCE repeatedly searches through the array.

OPTIMAL stores previous prefix sums in a hashmap.

Therefore instead of asking:

    "Which previous prefix sum do I need?"

and searching for it,

we ask the hashmap:

    "Have I already seen currentSum - K?"

Average lookup:

    O(1)


So:

    N elements × O(1) lookup

    = O(N)


============================================================
IMPORTANT: FIRST OCCURRENCE
============================================================

For LONGEST subarray:

    Store the first occurrence of each prefix sum.


Example:

prefix sum 5 appears at:

index 2
index 6
index 9


Keep:

    m[5] = 2


NOT:

    m[5] = 9


because the earliest index gives the longest possible
subarray ending at the current position.


============================================================
EDGE CASES
============================================================

1. Empty array

[]

→ 0


2. Entire array sums to K

[1,2,3]

K = 6

→ 3


3. Negative numbers

[1,-1,5,-2,3]

K = 3

Prefix sum + hashmap handles them.


4. Zeros

[0,0,0,0]

K = 0

The longest subarray is the entire array.


5. Negative K

The approach also works.

Example:

[-2,-1,2]

K = -3

→ [−2,−1]

length = 2


============================================================
COMMON MISTAKES
============================================================

❌ Mistake 1:

Store every occurrence of prefix sum.

For longest subarray, keep the FIRST occurrence.


❌ Mistake 2:

Forget:

    m[0] = -1


This causes problems when the valid subarray starts
from index 0.


❌ Mistake 3:

Use:

    currentSum - K

incorrectly.

Remember:

    currentSum - previousSum = K

therefore:

    previousSum = currentSum - K


❌ Mistake 4:

Confuse subarray with subsequence.

Subarray must be contiguous.


============================================================
INTERVIEW PATTERN
============================================================

Whenever you see:

    "Longest subarray with sum K"

immediately think:

    PREFIX SUM + HASHMAP


The mental equation:

    currentSum - oldSum = K


Rearrange:

    oldSum = currentSum - K


Then:

    Look for currentSum - K in hashmap.


============================================================
FINAL MEMORY TRICK
============================================================

LONGEST SUBARRAY + SUM K

        ↓

PREFIX SUM

        ↓

currentSum - oldSum = K

        ↓

oldSum = currentSum - K

        ↓

HASHMAP

        ↓

store prefixSum → FIRST INDEX


============================================================