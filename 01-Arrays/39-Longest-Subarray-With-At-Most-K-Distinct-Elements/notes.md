============================================================
PROBLEM 36: LONGEST SUBARRAY WITH AT MOST K DISTINCT ELEMENTS
============================================================

PROBLEM:

Given an array and an integer K, find the length of the
longest contiguous subarray containing at most K distinct
elements.

Example:

a = [1, 2, 1, 2, 3]
k = 2

Longest valid subarray:

[1, 2, 1, 2]

Distinct elements:

{1, 2}

Answer:

4


============================================================
WHAT DOES "DISTINCT" MEAN?
============================================================

Distinct means UNIQUE values.

Example:

[1, 2, 1, 2, 3]

Distinct values:

1
2
3

So there are 3 distinct elements.

Duplicates don't increase the distinct count.


============================================================
APPROACH 1 — BRUTE FORCE
============================================================

Generate every possible subarray.

Use:

    i = starting index
    j = ending index

For every new starting index i, create a fresh set.

Then expand j.

The set automatically removes duplicates.

Example:

[1, 2, 1, 2]

Set becomes:

{1}
{1,2}
{1,2}
{1,2}


If:

    set.size() <= k

the subarray is valid.

Update maxLen.


CODE:

int longestSubarrayBrute(vector<int>& a, int k) {

    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {

        unordered_set<int> s;

        for(int j = i; j < a.size(); j++) {

            s.insert(a[j]);

            if(s.size() > k) {
                break;
            }

            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}


============================================================
WHY CAN WE BREAK?
============================================================

Suppose:

k = 2

Current window:

[1, 2, 3]

Distinct:

{1,2,3}

= 3


Already:

    3 > 2


Adding another element cannot reduce the number of distinct
elements.

So for this particular i, we can stop.


============================================================
BRUTE FORCE COMPLEXITY
============================================================

Worst case:

    Time = O(N²)

The set insertion is average O(1).

Extra space:

    O(K)

(or O(N) in the worst case if K can be N)


============================================================
WHY SET IS NOT ENOUGH FOR OPTIMAL?
============================================================

This is an important lesson.

A set can tell us:

    "Does this value exist?"

But during sliding-window shrinking, we need to know:

    "How many copies of this value are still inside
     the window?"


Example:

[1, 2, 1, 3]

Frequency:

1 → 2
2 → 1
3 → 1


If the leftmost 1 leaves:

1 → 1

We CANNOT remove 1 completely because another 1 is
still inside the window.


Therefore we need a:

    frequency map


============================================================
APPROACH 2 — SLIDING WINDOW + HASHMAP
============================================================

Maintain a window:

    [l ........ r]


Use:

    l = left pointer
    r = right pointer


And a frequency map:

    number → frequency inside window


Example:

[1, 2, 1, 3]

Map:

1 → 2
2 → 1
3 → 1


Number of distinct elements:

    map.size()


============================================================
EXPANDING THE WINDOW
============================================================

Move r from left to right.

When we encounter:

    a[r]

add it:

    m[a[r]]++;


If it already exists:

    frequency increases.


If it doesn't exist:

    a new distinct element is created.


============================================================
VALID CONDITION
============================================================

The window is valid when:

    m.size() <= k


INVALID:

    m.size() > k


When invalid, shrink from the left.


============================================================
SHRINKING THE WINDOW
============================================================

Suppose:

    m.size() > k


Remove:

    a[l]


First decrease its frequency:

    m[a[l]]--;


If its frequency becomes zero:

    m.erase(a[l]);


Then move:

    l++;


IMPORTANT:

Do NOT blindly erase a[l].

Only erase it when its frequency becomes zero.


============================================================
OPTIMAL CODE
============================================================

int longestSubarray(vector<int>& a, int k) {

    int maxLen = 0;
    int l = 0;

    unordered_map<int, int> m;

    for(int r = 0; r < a.size(); r++) {

        // Add right element
        m[a[r]]++;

        // Shrink while window is invalid
        while(m.size() > k) {

            m[a[l]]--;

            if(m[a[l]] == 0) {
                m.erase(a[l]);
            }

            l++;
        }

        // Window is now valid
        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}


============================================================
DRY RUN
============================================================

a = [1, 2, 1, 2, 3]
k = 2


Start:

l = 0
map = {}
maxLen = 0


r = 0

Add 1:

map:

1 → 1

Distinct = 1

Valid.

Window:

[1]

length = 1

maxLen = 1


------------------------------------------------------------

r = 1

Add 2:

1 → 1
2 → 1

Distinct = 2

Valid.

Window:

[1,2]

length = 2

maxLen = 2


------------------------------------------------------------

r = 2

Add 1:

1 → 2
2 → 1

Distinct = 2

Valid.

Window:

[1,2,1]

length = 3

maxLen = 3


------------------------------------------------------------

r = 3

Add 2:

1 → 2
2 → 2

Distinct = 2

Valid.

Window:

[1,2,1,2]

length = 4

maxLen = 4


------------------------------------------------------------

r = 4

Add 3:

1 → 2
2 → 2
3 → 1

Distinct = 3

But:

    3 > 2

Invalid.


Shrink from left.

Remove a[0] = 1:

1 → 1

l = 1

Still 3 distinct.


Remove a[1] = 2:

2 → 1

l = 2

Still 3 distinct.


Remove a[2] = 1:

1 → 0

Erase 1.

l = 3

Now:

2 → 1
3 → 1

Distinct = 2

Valid.


Current window:

[2,3]

length = 2


Maximum remains:

4


FINAL ANSWER:

4


============================================================
WHY IS THIS O(N)?
============================================================

There is a for loop and a while loop.

It might look like:

    O(N²)

But it isn't.

The right pointer only moves forward.

The left pointer also only moves forward.

Each element can enter the window once and leave the
window once.

Therefore:

    r movements = O(N)
    l movements = O(N)

Total:

    O(2N)

which is:

    O(N)


============================================================
COMPLEXITY
============================================================

Brute force:

    Time  = O(N²)
    Space = O(K) / O(N) worst case


Optimal:

    Time  = O(N) average
    Space = O(K) / O(N) worst case


============================================================
SLIDING WINDOW PATTERN
============================================================

This is the pattern you should remember:

    r expands
       ↓
    add a[r]
       ↓
    check condition
       ↓
    INVALID?
       ↓
    move l
       ↓
    remove a[l]
       ↓
    VALID
       ↓
    update answer


============================================================
PROBLEM 35 vs PROBLEM 36
============================================================

Problem 35:

    Maximum consecutive 1s with at most K zero flips

Track:

    number of zeros


Condition:

    zeros <= K


Problem 36:

    Longest subarray with at most K distinct values

Track:

    frequency map


Condition:

    map.size() <= K


The sliding-window structure is the SAME.


============================================================
SET vs MAP
============================================================

SET:

    unordered_set<int>

Useful when you only care whether a value exists.

Example:

    Does 5 exist?


MAP:

    unordered_map<int,int>

Useful when you need frequency.

Example:

    How many 5s exist?


For this problem:

    MAP


because duplicates matter while shrinking.


============================================================
COMMON MISTAKES
============================================================

❌ Mistake 1:

    m.erase(a[l]);

without decreasing frequency first.

Wrong because another copy might still exist.


------------------------------------------------------------

❌ Mistake 2:

Move l without removing its element from the map.

Then the map no longer represents the actual window.


------------------------------------------------------------

❌ Mistake 3:

Update maxLen while the window is still invalid.

First shrink until:

    map.size() <= k

Then update maxLen.


------------------------------------------------------------

❌ Mistake 4:

Think the nested while makes it O(N²).

Both pointers move only forward.

Total:

    O(N)


============================================================
INTERVIEW MEMORY TRICK
============================================================

"LONGEST + SUBARRAY + AT MOST K DISTINCT"

        ↓

SLIDING WINDOW

        ↓

HASHMAP FREQUENCY

        ↓

map.size() > K?

        ↓ YES

SHRINK FROM LEFT


============================================================