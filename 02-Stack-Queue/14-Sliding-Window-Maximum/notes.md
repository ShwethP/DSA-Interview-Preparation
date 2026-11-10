# Problem 14 – Sliding Window Maximum

## 1. Problem Understanding

Given an array and a window size `k`, find the maximum element in every sliding window.

Example:

```cpp
nums = {1, 3, -1, -3, 5, 3, 6, 7};
k = 3;
```

Output:

```cpp
{3, 3, 5, 5, 6, 7}
```

## 2. Brute Force Approach

For every window:
1. Traverse all `k` elements.
2. Find the maximum.
3. Add the maximum to the result.
4. Move the window one position forward.

```cpp
vector<int> slidingWindowMax(vector<int>& a, int k)
{
    int n = a.size();
    vector<int> result;

    for(int i = 0; i <= n-k; i++)
    {
        int maxnum = a[i];

        for(int j = i; j < i+k; j++)
        {
            maxnum = max(maxnum, a[j]);
        }

        result.push_back(maxnum);
    }

    return result;
}
```

Complexity:
- Time: O((N-K+1) × K), or O(N × K) in the worst case.
- Auxiliary space: O(1).
- Output space: O(N-K+1).

## 3. Optimal Approach – Monotonic Deque

### What is a Deque?

A double-ended queue allows insertion and deletion from both ends.

```cpp
deque<int> dq;

dq.push_back(10);
dq.push_front(20);

dq.front();
dq.back();

dq.pop_front();
dq.pop_back();
```

### Main idea

Maintain a deque of indices in decreasing order of their corresponding array values.

The front always contains the index of the maximum element in the current window.

We store indices instead of values because we need to:
- Access the original array value.
- Identify elements that have gone outside the current window.

### Three important operations

**1. Remove expired indices from the front**

```cpp
while(!dq.empty() && dq.front() <= i-k)
{
    dq.pop_front();
}
```

The current window starts at index `i-k+1`.

Any index before this position is expired.

**2. Remove smaller or equal elements from the back**

```cpp
while(!dq.empty() && a[dq.back()] <= a[i])
{
    dq.pop_back();
}
```

Why?

If a newer element is greater than an older element, the older element can never become the maximum in any future window containing the newer one.

We remove equal elements too because the newer equal element stays in the window longer.

**3. Insert the current index**

```cpp
dq.push_back(i);
```

Once the first complete window is formed:

```cpp
if(i >= k-1)
{
    result.push_back(a[dq.front()]);
}
```

The front contains the maximum.

## 4. Optimal C++ Code

```cpp
vector<int> slidingWindowMax(vector<int>& a, int k)
{
    int n = a.size();

    vector<int> result;
    deque<int> dq;

    for(int i = 0; i < n; i++)
    {
        // Remove expired indices
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();

        // Remove smaller or equal values
        while(!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        // Insert current index
        dq.push_back(i);

        // Store maximum for complete window
        if(i >= k-1)
            result.push_back(a[dq.front()]);
    }

    return result;
}
```

## 5. Complexity Analysis

| Approach | Time | Auxiliary space |
|---|---|---|
| Brute force | O(N × K) | O(1) |
| Monotonic deque | O(N) | O(K) |

Each index enters the deque once and leaves it at most once. Therefore, total deque operations are O(N), even though we use `while` loops inside the `for` loop.

## 6. Important Interview Takeaways

1. Sliding window means processing a fixed-size range that moves through the array.
2. Brute force recalculates the maximum for every window.
3. A monotonic deque maintains only useful maximum candidates.
4. Store indices, not values.
5. Remove expired indices from the front.
6. Remove smaller or equal values from the back.
7. The front always gives the current window maximum.

**Pattern:** Sliding Window + Monotonic Deque.