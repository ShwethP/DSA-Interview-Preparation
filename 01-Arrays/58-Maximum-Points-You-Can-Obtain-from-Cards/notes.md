# Q58. Maximum Points You Can Obtain from Cards

## Problem

Given an array `cardPoints` and an integer `k`, take exactly `k` cards from either the left or right end to maximize the total points.

Example:

```cpp
cardPoints = {1, 2, 3, 4, 5, 6, 1};
k = 3;
// Output: 12
```

## Approach 1: Brute Force

Try every possible number of cards taken from the left, and take the remaining cards from the right.

```cpp
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;

    for (int i = 0; i < k; i++) {
        leftSum += cardPoints[i];
    }

    maxSum = leftSum;

    for (int i = 0; i < k; i++) {
        leftSum -= cardPoints[k - 1 - i];
        rightSum += cardPoints[n - 1 - i];

        maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
}
```

**Complexity:** Time `O(K)`, auxiliary space `O(1)`. This is already optimal in time when `K` is the parameter, since we examine each possible split between left and right selections.

## Approach 2: Minimum Fixed-Size Sliding Window

### Intuition

Taking exactly `k` cards means leaving behind `n-k` cards.

The cards left behind must form a contiguous middle subarray. Therefore:

```text
Maximum score = Total sum - Minimum sum of a window of size (n-k)
```

### Code

```cpp
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int totalSum = 0;

    for (int x : cardPoints) {
        totalSum += x;
    }

    int windowSize = n - k;

    if (windowSize == 0) {
        return totalSum;
    }

    int windowSum = 0;

    for (int i = 0; i < windowSize; i++) {
        windowSum += cardPoints[i];
    }

    int minWindowSum = windowSum;

    for (int right = windowSize; right < n; right++) {
        windowSum += cardPoints[right];
        windowSum -= cardPoints[right - windowSize];

        minWindowSum = min(minWindowSum, windowSum);
    }

    return totalSum - minWindowSum;
}
```

### Dry run

```text
cardPoints = [1,2,3,4,5,6,1]
k = 3
n = 7

Total sum = 22
Window size = n-k = 4
```

| Window | Sum | Minimum so far |
|---|---:|---:|
| `[1,2,3,4]` | 10 | 10 |
| `[2,3,4,5]` | 14 | 10 |
| `[3,4,5,6]` | 18 | 10 |
| `[4,5,6,1]` | 16 | 10 |

```text
Answer = 22 - 10 = 12
```

### Complexity

- Time: `O(N)`
- Auxiliary space: `O(1)`

### Memory trick

When a problem says **take K elements from either end**, consider what remains:

```text
Take K from the ends
       ↓
Leave N-K consecutive elements
       ↓
Find the minimum-sum window of size N-K
       ↓
Total sum - minimum window sum
```

Remember the edge case: if `k == n`, return the total sum.