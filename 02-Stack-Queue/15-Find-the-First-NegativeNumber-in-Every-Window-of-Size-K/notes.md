# First Negative Number in Every Window of Size K

## Problem
Given an array and window size `k`, find the first negative number in every contiguous window of size `k`. If a window has no negative number, return `0`.

## Brute Force Approach
- Use two loops.
- Outer loop selects each window.
- Inner loop searches for the first negative number.
- Stop searching once a negative number is found.
- If none is found, store `0`.

**Time:** O(N × K)  
**Auxiliary Space:** O(1), excluding the result.

## Optimal Approach — Queue of Indices

Use a queue to store the indices of negative elements.

### Algorithm
1. Traverse the array using `i`.
2. If `a[i] < 0`, push index `i` into the queue.
3. Remove expired indices while `q.front() <= i - k`.
4. Once `i >= k - 1`, the window is complete:
   - If the queue is empty, add `0`.
   - Otherwise, add `a[q.front()]`.

### C++ Code
```cpp
vector<int> firstNegativeinWindow(vector<int>& a, int k)
{
    int n = a.size();
    vector<int> r;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            q.push(i);

        while (!q.empty() && q.front() <= i - k)
            q.pop();

        if (i >= k - 1)
        {
            if (q.empty())
                r.push_back(0);
            else
                r.push_back(a[q.front()]);
        }
    }

    return r;
}
```

## Important Conditions
- `a[i] < 0`: identify negative elements.
- `q.front() <= i - k`: remove indices outside the current window.
- `i >= k - 1`: check whether the first complete window has formed.
- Store indices instead of values so we can identify expired elements.

## Complexity
- **Time:** O(N), because each index is pushed and popped at most once.
- **Auxiliary Space:** O(K) for the queue.
- **Result Space:** O(N - K + 1).

## Pattern Learned
Sliding Window + Queue.

Instead of searching every window again, maintain useful information as the window moves.