# Problem 17 — Celebrity Problem

## 1. Problem Statement

There are N people at a party. One person may be a celebrity.

A celebrity satisfies TWO conditions:

1. The celebrity knows nobody.
2. Everybody else knows the celebrity.

Given an N × N matrix:

```cpp
a[i][j] = 1; // Person i knows person j
a[i][j] = 0; // Person i does not know person j
```

Return the celebrity's index, or `-1` if no celebrity exists.

The diagonal is ignored because a person knowing themselves does not matter.

---

# Approach 1: Brute Force

## Idea

Check every person as a possible celebrity.

For each candidate `i`, verify:

- Entire row `i` contains zeroes (excluding diagonal).
- Entire column `i` contains ones (excluding diagonal).

## Algorithm

1. Loop through every person `i`.
2. Initialize:
   - `knowsNobody = true`
   - `everyoneKnows = true`
3. Loop through every other person `j`.
4. If `a[i][j] == 1`, the candidate knows someone. Set `knowsNobody = false`.
5. If `a[j][i] == 0`, someone does not know the candidate. Set `everyoneKnows = false`.
6. If both conditions remain true, return `i`.
7. If no candidate passes, return `-1`.

## C++ Code

```cpp
int celebrityBruteForce(vector<vector<int>>& a)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        bool knowsNobody = true;
        bool everyoneKnows = true;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (a[i][j] == 1)
                knowsNobody = false;

            if (a[j][i] == 0)
                everyoneKnows = false;

            if (!knowsNobody || !everyoneKnows)
                break;
        }

        if (knowsNobody && everyoneKnows)
            return i;
    }

    return -1;
}
```

## Complexity

- Time: O(N²), because we check every candidate against every other person.
- Auxiliary Space: O(1).

---

# Approach 2: Optimal — Two Pointers

## Idea

Instead of fully checking every person, eliminate impossible candidates.

Initialize:

```cpp
int top = 0;
int bottom = n - 1;
```

Compare:

```cpp
a[top][bottom]
```

There are two possibilities.

### Case 1: a[top][bottom] == 1

Person `top` knows person `bottom`.

Therefore, `top` cannot be a celebrity.

Eliminate `top`:

```cpp
top++;
```

### Case 2: a[top][bottom] == 0

Person `top` does not know person `bottom`.

Therefore, `bottom` cannot be a celebrity because everyone must know the celebrity.

Eliminate `bottom`:

```cpp
bottom--;
```

Continue until only one candidate remains.

IMPORTANT: Elimination only finds a potential candidate. We must verify that candidate.

## Algorithm

1. Initialize `top = 0`, `bottom = n - 1`.
2. While `top < bottom`:
   - If `a[top][bottom] == 1`, increment `top`.
   - Otherwise, decrement `bottom`.
3. The remaining candidate is `top`.
4. Verify the candidate's entire row and column.
5. Return candidate if valid, otherwise `-1`.

## C++ Code

```cpp
int celebrityTwoPointer(vector<vector<int>>& a)
{
    int n = a.size();

    if (n == 0)
        return -1;

    int top = 0;
    int bottom = n - 1;

    // Step 1: Eliminate impossible candidates
    while (top < bottom)
    {
        if (a[top][bottom] == 1)
            top++;
        else
            bottom--;
    }

    // Step 2: Remaining potential candidate
    int candidate = top;

    // Step 3: Verify both celebrity conditions
    for (int i = 0; i < n; i++)
    {
        if (i == candidate)
            continue;

        if (a[candidate][i] == 1 ||
            a[i][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}
```

## Complexity

- Elimination: O(N).
- Verification: O(N).
- Total Time: O(N).
- Auxiliary Space: O(1).

---

# Approach 3: Optimal — Stack

## Idea

Use a stack to store all possible candidates.

Eliminate two people at a time until only one remains.

## Algorithm

### Step 1: Push everyone

```cpp
stack<int> st;

for (int i = 0; i < n; i++)
    st.push(i);
```

### Step 2: Eliminate candidates

While the stack contains at least two people:

```cpp
int first = st.top();
st.pop();

int second = st.top();
st.pop();
```

Compare:

```cpp
if (a[first][second] == 1)
{
    st.push(second);
}
else
{
    st.push(first);
}
```

WHY?

- If first knows second, first cannot be the celebrity.
- Otherwise, second cannot be the celebrity.

Push the surviving candidate back into the stack.

### Step 3: Get the remaining candidate

```cpp
int candidate = st.top();
```

### Step 4: Verify the candidate

Check that:

- Candidate knows nobody.
- Everybody else knows the candidate.

## C++ Code

```cpp
int celebrityStack(vector<vector<int>>& a)
{
    int n = a.size();

    if (n == 0)
        return -1;

    stack<int> st;

    // Step 1: Push everyone
    for (int i = 0; i < n; i++)
        st.push(i);

    // Step 2: Eliminate impossible candidates
    while (st.size() > 1)
    {
        int first = st.top();
        st.pop();

        int second = st.top();
        st.pop();

        if (a[first][second] == 1)
            st.push(second);
        else
            st.push(first);
    }

    // Step 3: Get remaining candidate
    int candidate = st.top();

    // Step 4: Verify candidate
    for (int i = 0; i < n; i++)
    {
        if (i == candidate)
            continue;

        if (a[candidate][i] == 1 ||
            a[i][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}
```

## Complexity

- Pushing people: O(N).
- Elimination: O(N).
- Verification: O(N).
- Total Time: O(N).
- Auxiliary Space: O(N) for the stack.

---

# Comparison of All Three Approaches

| Approach | Time | Auxiliary Space |
|---|---|---|
| Brute Force | O(N²) | O(1) |
| Two Pointers | O(N) | O(1) |
| Stack | O(N) | O(N) |

# Important Interview Concepts

1. **Candidate elimination:** A single comparison can prove that one person cannot be the celebrity.
2. **Verification is mandatory:** A remaining candidate is not automatically a celebrity.
3. **Two-pointer technique:** Eliminates candidates without needing an extra data structure.
4. **Stack technique:** Stores candidates and eliminates them in pairs.
5. **Celebrity conditions:** Candidate's row must be zero and candidate's column must be one, excluding the diagonal.

## Final Takeaway

The Celebrity Problem has three approaches:

- Brute force: Check everyone.
- Two pointers: Eliminate using comparisons.
- Stack: Push everyone and eliminate in pairs.

Both optimal approaches take O(N) time. Two pointers are more space-efficient, while the stack approach demonstrates a classic stack-based elimination pattern.