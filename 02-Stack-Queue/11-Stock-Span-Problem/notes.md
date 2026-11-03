# Stack/Queue – Problem 11: Stock Span Problem

## 1. Problem Statement

Given an array of stock prices, calculate the stock span for every day.

The span is the number of consecutive days ending on the current day where prices were less than or equal to the current day's price.

Example:

```cpp
Input:  {100, 80, 60, 70, 60, 75, 85}
Output: {1, 1, 1, 2, 1, 4, 6}
```

## 2. Approach 1: Brute Force

For every day:
1. Start with count = 1 (current day).
2. Traverse backwards.
3. If the previous price is less than or equal to today's price, increment count.
4. Otherwise, stop.
5. Store the count.

### Code

```cpp
vector<int> stockSpan(vector<int> &prices)
{
    int n = prices.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
        int count = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (prices[j] <= prices[i])
                count++;
            else
                break;
        }

        result[i] = count;
    }

    return result;
}
```

**Time Complexity:** O(N²)

**Space Complexity:** O(N) for the result vector.

## 3. Approach 2: Monotonic Stack

### Main Idea

Find the Previous Greater Element's index for every day.

Instead of repeatedly traversing backwards, maintain a stack of indices.

We need indices rather than prices because we calculate the span using the distance between days.

### Algorithm

Traverse from left to right:

1. While the stack is not empty and the price at the stack's top index is less than or equal to the current price, pop.
2. If the stack is empty, span = `i + 1`.
3. Otherwise, span = `i - st.top()`.
4. Push the current index.

### Formula

If a previous greater element exists:

`span[i] = i - previousGreaterIndex`

Otherwise:

`span[i] = i + 1`

### C++ Code

```cpp
vector<int> stockSpan(vector<int> &prices)
{
    int n = prices.size();

    vector<int> result(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() &&
               prices[st.top()] <= prices[i])
        {
            st.pop();
        }

        if (st.empty())
            result[i] = i + 1;
        else
            result[i] = i - st.top();

        st.push(i);
    }

    return result;
}
```

## 4. Dry Run

Input:

`{100, 80, 60, 70, 60, 75, 85}`

| Day (index) | Price | Previous greater index | Span |
|---:|---:|---:|---:|
| 0 | 100 | None | 1 |
| 1 | 80 | 0 | 1 |
| 2 | 60 | 1 | 1 |
| 3 | 70 | 1 | 2 |
| 4 | 60 | 3 | 1 |
| 5 | 75 | 1 | 4 |
| 6 | 85 | 0 | 6 |

Output:

`{1, 1, 1, 2, 1, 4, 6}`

## 5. Why use `<=`?

We include equal prices in the span.

Therefore, we remove previous prices that are less than OR equal to the current price.

If we used only `<`, equal prices would incorrectly stop the span.

## 6. Complexity Analysis

| Complexity | Value |
|---|---:|
| Time | O(N) |
| Auxiliary space | O(N) |
| Result space | O(N) |

Each index is pushed once and popped at most once.

## 7. Pattern Comparison

| Problem | Traversal | What we find |
|---|---|---|
| Next Greater Element | Right to left | Next greater element |
| Next Smaller Element | Right to left | Next smaller element |
| Stock Span | Left to right | Previous greater element |

## Key Takeaways

- Stock Span is a Previous Greater Element problem.
- Store indices instead of values when distance or position matters.
- Use `<=` because equal prices are included in the span.
- If no previous greater element exists, the span is `i + 1`.
- Monotonic Stack reduces O(N²) to O(N).