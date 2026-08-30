============================================================
PROBLEM 32: LEADERS IN AN ARRAY
============================================================

PROBLEM:

An element is called a LEADER if it is strictly greater
than every element to its right.

The last element is always a leader because there is
nothing to its right.


Example:

[10, 22, 12, 3, 0, 6]

Leaders:

[22, 12, 6]


------------------------------------------------------------
BRUTE FORCE APPROACH
------------------------------------------------------------

For every element a[i]:

    Check every element to its right.

If we find an element:

    a[j] >= a[i]

then a[i] is NOT a leader.

If no such element exists:

    a[i] is a leader.


CODE:

vector<int> leadersBrute(vector<int>& a) {

    vector<int> result;

    int n = a.size();

    for(int i = 0; i < n; i++) {

        bool isLeader = true;

        for(int j = i + 1; j < n; j++) {

            if(a[j] >= a[i]) {
                isLeader = false;
                break;
            }
        }

        if(isLeader) {
            result.push_back(a[i]);
        }
    }

    return result;
}


TIME COMPLEXITY:

    O(N²)

Because for every element we may scan the elements
to its right.


SPACE COMPLEXITY:

    O(K)

where K = number of leaders.

Worst case:

    O(N)

because every element could potentially be a leader.


------------------------------------------------------------
OPTIMAL APPROACH
------------------------------------------------------------

Instead of repeatedly checking all elements to the right,
traverse the array FROM RIGHT TO LEFT.


Maintain:

    rightMax

rightMax = maximum element seen so far on the right.


For every element:

    if a[i] > rightMax

then:

    a[i] is a leader

and:

    rightMax = a[i]


Why?

Because rightMax already represents the largest element
to the right of the current element.

Therefore we don't need to check every element individually.


------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

[10, 22, 12, 3, 0, 6]

Start from the right:

6

6 is automatically a leader.

    rightMax = 6


Now:

0

    0 > 6 ? NO


Now:

3

    3 > 6 ? NO


Now:

12

    12 > 6 ? YES

12 is a leader.

Update:

    rightMax = 12


Now:

22

    22 > 12 ? YES

22 is a leader.

Update:

    rightMax = 22


Now:

10

    10 > 22 ? NO


Leaders discovered:

    [6, 12, 22]


But this is backwards.

Expected order:

    [22, 12, 6]


Therefore reverse the result.


------------------------------------------------------------
OPTIMAL CODE
------------------------------------------------------------

vector<int> leaders(vector<int>& a) {

    vector<int> result;

    int n = a.size();

    int rightMax = INT_MIN;

    for(int i = n - 1; i >= 0; i--) {

        if(a[i] > rightMax) {

            result.push_back(a[i]);

            rightMax = a[i];
        }
    }

    reverse(result.begin(), result.end());

    return result;
}


------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

We traverse the array once:

    O(N)

reverse() also takes:

    O(N)

Therefore:

    O(N) + O(N)
    = O(N)


SPACE:

    O(K)

for the result.

Worst case:

    O(N)


------------------------------------------------------------
KEY OBSERVATION
------------------------------------------------------------

The important trick is:

        TRAVERSE FROM RIGHT → LEFT


Because the definition of a leader depends on:

        ELEMENTS TO THE RIGHT


By traversing from the right, we can maintain:

        maximum element seen so far


So instead of:

    "Check every element to my right"

we ask:

    "Am I greater than the maximum I've already seen?"


------------------------------------------------------------
IMPORTANT CONDITION
------------------------------------------------------------

Use:

    a[i] > rightMax


NOT:

    a[i] >= rightMax


Because the leader must be STRICTLY greater.

Example:

[10, 10, 5]

First 10 is NOT a leader because another 10
exists to its right.


------------------------------------------------------------
EDGE CASES
------------------------------------------------------------

Empty array:

    []

→ return []


Single element:

    [5]

→ [5]


Strictly increasing:

    [1,2,3,4,5]

→ [5]


Strictly decreasing:

    [5,4,3,2,1]

→ [5,4,3,2,1]


Duplicates:

    [10,10,5]

→ [10,5]


------------------------------------------------------------
BRUTE FORCE vs OPTIMAL
------------------------------------------------------------

BRUTE:

    For every element:
        scan everything to the right

    Time:  O(N²)
    Space: O(K)


OPTIMAL:

    Traverse right → left
    Maintain rightMax

    Time:  O(N)
    Space: O(K)


------------------------------------------------------------
INTERVIEW TAKEAWAY
------------------------------------------------------------

Whenever a problem asks about:

    "all elements to the right"

think:

    Can I traverse from RIGHT → LEFT?


And whenever you need:

    maximum/minimum of everything seen so far

think about maintaining a:

    max / min variable


============================================================