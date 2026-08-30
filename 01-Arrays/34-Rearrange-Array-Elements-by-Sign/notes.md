============================================================
PROBLEM 31: REARRANGE ARRAY ELEMENTS BY SIGN
============================================================

PROBLEM:

Given an array containing an equal number of positive and
negative numbers.

Rearrange the array so that:

1. Positive and negative numbers alternate.
2. The first element is positive.
3. Relative order of positive numbers is preserved.
4. Relative order of negative numbers is preserved.

Example:

Input:

[3, 2, 4, -1, -4, -5, 6, -7, 8, -9]

Output:

[3, -1, 2, -4, 4, -5, 6, -7, 8, -9]


============================================================
BRUTE FORCE
============================================================

Create two separate arrays:

    positive[]
    negative[]

First traverse the original array.

If:

    num > 0

put it into positive[].

Otherwise:

    put it into negative[].


Then create the result array by taking:

    positive[0]
    negative[0]
    positive[1]
    negative[1]
    ...


BRUTE FORCE CODE:

vector<int> rearrange(vector<int>& a) {

    vector<int> positive;
    vector<int> negative;

    for (int num : a) {

        if (num > 0)
            positive.push_back(num);
        else
            negative.push_back(num);
    }

    vector<int> result;

    for (int i = 0; i < positive.size(); i++) {

        result.push_back(positive[i]);
        result.push_back(negative[i]);
    }

    return result;
}


============================================================
WHY DOES THIS PRESERVE ORDER?
============================================================

Suppose:

positive numbers:

[3, 2, 4, 6, 8]

negative numbers:

[-1, -4, -5, -7, -9]


We traverse from left to right.

Therefore positive[] becomes:

[3, 2, 4, 6, 8]

and negative[] becomes:

[-1, -4, -5, -7, -9]

When we merge them:

[3, -1, 2, -4, 4, -5, 6, -7, 8, -9]

The order inside each group is unchanged.


============================================================
BRUTE FORCE COMPLEXITY
============================================================

We traverse the array:

    O(N)

We then merge the two arrays:

    O(N)

Therefore:

    TIME = O(N)


Extra arrays contain all N elements:

    SPACE = O(N)


============================================================
OPTIMAL / DIRECT PLACEMENT
============================================================

Instead of creating:

    positive[]
    negative[]

we know exactly where each number belongs.

Positive positions:

    0, 2, 4, 6, 8...


Negative positions:

    1, 3, 5, 7, 9...


Maintain:

    posIndex = 0
    negIndex = 1


For every number:

If positive:

    result[posIndex] = num;
    posIndex += 2;


If negative:

    result[negIndex] = num;
    negIndex += 2;


============================================================
OPTIMAL CODE
============================================================

vector<int> rearrange(vector<int>& a) {

    int n = a.size();

    vector<int> result(n);

    int posIndex = 0;
    int negIndex = 1;

    for (int num : a) {

        if (num > 0) {

            result[posIndex] = num;
            posIndex += 2;
        }
        else {

            result[negIndex] = num;
            negIndex += 2;
        }
    }

    return result;
}


============================================================
COMPLEXITY
============================================================

Time:

    O(N)

Space:

    O(N)


============================================================
BRUTE FORCE vs DIRECT PLACEMENT
============================================================

BRUTE FORCE:

    original
       ↓
    positive[]
    negative[]
       ↓
    result[]

    Time:  O(N)
    Space: O(N)


DIRECT PLACEMENT:

    original
       ↓
    result[]

    Time:  O(N)
    Space: O(N)


IMPORTANT:

There is NO Big-O improvement here.

Both are:

    O(N) time
    O(N) space


The direct-placement approach is cleaner because we don't
need the intermediate positive[] and negative[] arrays.


============================================================
KEY OBSERVATION
============================================================

We don't need to search for where a number belongs.

We already know:

    Positive → even indexes
    Negative → odd indexes


So maintain two indexes:

    posIndex = 0
    negIndex = 1

and increase each by 2.


============================================================
IMPORTANT CONSTRAINT
============================================================

This version assumes:

    number of positives == number of negatives

because every positive needs a positive position and every
negative needs a negative position.


============================================================
INTERVIEW TAKEAWAY
============================================================

When the required positions have a fixed pattern, ask:

    "Can I directly place each element instead of
     first separating the elements?"

Here:

    positive → 0,2,4...
    negative → 1,3,5...

This eliminates the intermediate arrays.


============================================================