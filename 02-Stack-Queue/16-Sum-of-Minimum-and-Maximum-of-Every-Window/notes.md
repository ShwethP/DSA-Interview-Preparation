# Sum of Minimum and Maximum of Every Window

## Problem
For every window of size K, find its minimum and maximum, then calculate their sum.

## Brute Force
- Outer loop selects each window.
- Inner loop finds both minimum and maximum.
- Add their sum to the result.

Time: O(N × K)  
Auxiliary Space: O(1), excluding result.

## Optimal — Two Monotonic Deques

Use two deques storing indices:

1. `maxDQ`: decreasing order of values. Front gives maximum.
2. `minDQ`: increasing order of values. Front gives minimum.

### Algorithm
For every index `i`:

1. Remove expired indices from the front: `front <= i-k`.
2. For maximum deque, remove from back while `a[maxDQ.back()] <= a[i]`.
3. For minimum deque, remove from back while `a[minDQ.back()] >= a[i]`.
4. Push current index at the back of both deques.
5. Once `i >= k-1`, add `a[maxDQ.front()] + a[minDQ.front()]` to the result.

## Important Conditions
- Compare array values using deque indices: `a[dq.back()]`.
- Insert at the back, not the front.
- Maximum deque uses `<=` when removing.
- Minimum deque uses `>=` when removing.
- Expired indices are removed from the front.

## Complexity
- Time: O(N)
- Auxiliary Space: O(K)
- Result Space: O(N-K+1)

## Pattern
Sliding Window + Two Monotonic Deques.