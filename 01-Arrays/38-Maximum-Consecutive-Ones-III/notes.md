============================================================
PROBLEM 35: MAXIMUM CONSECUTIVE ONES III
============================================================

PROBLEM:

Given a binary array and an integer K, you can flip at most
K zeros into ones.

Find the length of the longest contiguous subarray that can
become all 1s after flipping at most K zeros.

Example:

nums = [0,1,0,1,1,1,1]
k = 1

We can flip one zero.

Best window:

[0,1,0,1,1,1,1]
 ↑
 flip

Actually, the best valid window contains only ONE zero:

[1,0,1,1,1,1]

length = 6

Answer = 6


============================================================
APPROACH 1 — BRUTE FORCE
============================================================

Generate every possible subarray.

For each starting position i:

    start a window

Then move j from i → n-1.

Keep track of the number of zeros.

If:

    zeros <= k

the current window is valid.

Calculate its length.

If:

    zeros > k

we can stop extending this particular window because
adding more elements cannot reduce the number of zeros.


CODE:

int longestConsecutiveOnesBrute(vector<int>& a, int k) {

    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {

        int zeros = 0;

        for(int j = i; j < a.size(); j++) {

            if(a[j] == 0) {
                zeros++;
            }

            if(zeros > k) {
                break;
            }

            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}


============================================================
BRUTE FORCE COMPLEXITY
============================================================

Worst case:

    O(N²)

Even though we can break early when zeros > K,
the worst case can still require checking O(N²) windows.

SPACE:

    O(1)


============================================================
OPTIMAL APPROACH — SLIDING WINDOW
============================================================

Instead of generating every possible subarray,
maintain ONE window.

Use two pointers:

    l = left boundary
    r = right boundary


Also maintain:

    zeros = number of zeros inside the current window


Initially:

    l = 0
    zeros = 0
    maxLen = 0


Move r from left → right.

Whenever:

    a[r] == 0

increase:

    zeros++


Now check whether the window is valid.

A valid window must satisfy:

    zeros <= k


If:

    zeros > k

the window is invalid.

So move l forward until the window becomes valid again.


============================================================
THE SHRINKING LOGIC
============================================================

When moving l forward, remember:

The element at l is LEAVING the window.


Therefore:

if(a[l] == 0)

    zeros--;


Then:

    l++;


So:

while(zeros > k) {

    if(a[l] == 0) {
        zeros--;
    }

    l++;
}


============================================================
WHY DO WE DO THIS?
============================================================

Example:

a = [1,1,0,0,1]
k = 1


Suppose our window becomes:

[1,1,0,0]

Number of zeros:

    2


But we're allowed only:

    1


So the window is invalid.


Move l:

[1,0,0]

Still:

    2 zeros


Move l again:

[0,0]

Still:

    2 zeros


Move l again:

[0]

Now:

    1 zero


Window is valid again.


We didn't restart the search.

We simply SHRANK the existing window.


============================================================
OPTIMAL CODE
============================================================

int longestConsecutiveOnes(vector<int>& a, int k) {

    int zeros = 0;
    int maxLen = 0;
    int l = 0;

    for(int r = 0; r < a.size(); r++) {

        if(a[r] == 0) {
            zeros++;
        }

        while(zeros > k) {

            if(a[l] == 0) {
                zeros--;
            }

            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}


============================================================
DRY RUN
============================================================

a = [0,1,0,1,1,1,1]
k = 1


Start:

l = 0
zeros = 0
maxLen = 0


r = 0

a[0] = 0

zeros = 1

Valid.

Window:

[0]

length = 1

maxLen = 1


r = 1

a[1] = 1

zeros = 1

Window:

[0,1]

length = 2

maxLen = 2


r = 2

a[2] = 0

zeros = 2

But:

    2 > 1

Invalid.


Shrink from left.

a[l] = a[0] = 0

So:

zeros--

zeros = 1

l++

l = 1


Window:

[1,0]

length = 2


r = 3

a[3] = 1

zeros = 1

Window:

[1,0,1]

length = 3


r = 4

Window:

[1,0,1,1]

length = 4


r = 5

Window:

[1,0,1,1,1]

length = 5


r = 6

Window:

[1,0,1,1,1,1]

length = 6


FINAL ANSWER:

6


============================================================
WHY IS IT O(N)?
============================================================

At first it looks like there is a for loop AND a while loop,
so you might think:

    O(N²)

But that's NOT the case.


The right pointer r moves:

    N times


The left pointer l also moves forward:

    at most N times


Neither pointer ever moves backwards.


Therefore total pointer movements are:

    N + N

    = 2N

    = O(N)


TIME:

    O(N)


SPACE:

    O(1)


============================================================
THE SLIDING WINDOW PATTERN
============================================================

This is the pattern to remember:

    EXPAND
       ↓
    right pointer moves
       ↓
    window becomes invalid?
       ↓
    SHRINK
       ↓
    left pointer moves
       ↓
    window becomes valid
       ↓
    RECORD ANSWER


In this problem:

VALID CONDITION:

    zeros <= k


INVALID CONDITION:

    zeros > k


============================================================
IMPORTANT DIFFERENCE FROM PROBLEM 34
============================================================

Problem 34:

    Find longest consecutive 1s.

Only actual 1s count.


Problem 35:

    We are allowed to flip K zeros.

So a window containing zeros can still be valid.


Problem 34:

    [1,1,0,1,1]

Longest = 2


Problem 35 with k = 1:

    [1,1,0,1,1]

Flip the zero.

Longest = 5


============================================================
EDGE CASES
============================================================

1. k = 0

No zeros can be flipped.

This becomes essentially the same as the previous
"longest consecutive ones" problem.


2. k >= number of zeros

We can flip every zero.

Therefore the entire array is valid.

Answer:

    N


3. All zeros

Example:

    [0,0,0,0]

k = 2

Answer:

    2


4. All ones

Example:

    [1,1,1,1]

k = 0

Answer:

    4


5. Empty array

Return:

    0


============================================================
COMMON MISTAKES
============================================================

❌ Mistake 1:

Only increment zeros but forget to decrement it when
the left side leaves the window.


When doing:

    l++


remember that:

    a[l]

is leaving the window.


------------------------------------------------------------

❌ Mistake 2:

Update maxLen only when a[r] == 0.

WRONG.

The window can become larger when a[r] is 1 as well.

Therefore update maxLen AFTER the shrinking logic.


------------------------------------------------------------

❌ Mistake 3:

Restart the window when zeros > k.

Don't restart.

Just move l forward.


------------------------------------------------------------

❌ Mistake 4:

Think nested for + while automatically means O(N²).

Here both pointers only move forward.

Total movement:

    O(N)


============================================================
BRUTE FORCE vs OPTIMAL
============================================================

BRUTE:

    Generate every possible window.

    Time  = O(N²)
    Space = O(1)


OPTIMAL:

    Sliding window + two pointers.

    Time  = O(N)
    Space = O(1)


IMPROVEMENT:

    O(N²) → O(N)


============================================================
INTERVIEW TAKEAWAY
============================================================

Whenever you see something like:

    "Longest subarray..."
    "At most K..."
    "Can tolerate K bad elements..."
    "Maximum length..."
    "Contiguous..."

start thinking:

    SLIDING WINDOW


Typical structure:

    right expands the window

    condition becomes invalid

    left shrinks the window

    condition becomes valid

    update answer


============================================================
MEMORY TRICK
============================================================

MAXIMUM CONSECUTIVE ONES III:

    Count zeros.

    zeros <= K
        → valid window

    zeros > K
        → move left until valid

    answer = max(answer, window length)


============================================================