# Problem 12 – Largest Rectangle in Histogram

## 1. Problem Understanding

Given an array where each element represents the height of a histogram bar, find the maximum rectangular area that can be formed.

Example:

```cpp
heights = {2, 1, 5, 6, 2, 3};
```

**Output: 10**

The rectangle with height 5 can cover bars at indices 2 and 3.

- Height = 5
- Width = 2
- Area = 5 × 2 = 10

Formula:

```cpp
area = height * width;
```

The main challenge is finding how far a bar can extend to its left and right.

---

## 2. Brute Force Approach

### Idea

Consider every bar as the minimum height of a rectangle.

For each index `i`:

1. Take `heights[i]` as the rectangle height.
2. Expand towards the left while bars are greater than or equal to this height.
3. Expand towards the right while bars are greater than or equal to this height.
4. Calculate the width.
5. Calculate the area and update the maximum.

### Code – `LargestRectangleHistogram.cpp`

```cpp
int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();
    int maxArea = 0;

    for(int i = 0; i < n; i++) {

        int height = heights[i];

        int left = i;
        int right = i;

        while(left > 0 && heights[left - 1] >= height) {
            left--;
        }

        while(right < n - 1 && heights[right + 1] >= height) {
            right++;
        }

        int width = right - left + 1;

        int area = height * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}
```

### Complexity

- Time: O(N²), because for every bar we may scan left and right.
- Auxiliary space: O(1).

---

## 3. Optimized Approach – Monotonic Stack

### Pattern: Previous Smaller + Next Smaller Element

This problem uses the same monotonic stack concept we learned in:

- Next Greater Element
- Next Smaller Element
- Stock Span

But now we use the stack to calculate the maximum width of a rectangle.

### Main idea

For every bar, we need:

1. Previous Smaller Element (PSE): nearest smaller bar on the left.
2. Next Smaller Element (NSE): nearest smaller bar on the right.

These two smaller bars act as boundaries.

The rectangle can extend between them, excluding the boundaries.

### Width formula

```cpp
width = rightBoundary - leftBoundary - 1;
```

For example:

```cpp
heights = {2, 1, 5, 6, 2, 3};
```

Consider height 5 at index 2.

- Previous smaller index = 1 (height 1).
- Next smaller index = 4 (height 2).

Therefore:

```cpp
width = 4 - 1 - 1;
      = 2;

area = 5 * 2;
     = 10;
```

### Why do we store indices instead of heights?

Because we need positions to calculate the width.

Storing only heights would not tell us how many bars are between the boundaries.

---

## 4. Why does the stack become empty?

This is an important concept.

When we pop an index from the stack, we have found its right smaller boundary.

After popping:

- If the stack is NOT empty, its top is the previous smaller boundary.
- If the stack IS empty, there is no smaller bar on the left.

In that case, the rectangle can extend all the way from index 0 to the position just before the current index `i`.

Therefore:

```cpp
if(st.empty()) {
    width = i;
}
else {
    width = i - st.top() - 1;
}
```

**Why is width equal to `i` when the stack is empty?**

Because `i` is the exclusive right boundary.

The rectangle covers indices:

```cpp
0, 1, 2, ... i-1
```

So the number of bars is exactly `i`.

Example:

```cpp
heights = {3, 2, 1};
```

When processing the final sentinel at `i = 3`, the bar with height 1 is popped and the stack becomes empty.

Its rectangle covers indices 0, 1 and 2.

```cpp
width = 3;
area = 1 * 3;
     = 3;
```

It does NOT mean that we are calculating the width from the middle of the array. An empty stack specifically means there is no smaller left boundary.

---

## 5. Optimized Code

```cpp
int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    int maxArea = 0;

    stack<int> st;

    for(int i = 0; i <= n; i++) {

        // Sentinel height to process remaining bars
        int currentHeight = (i == n) ? 0 : heights[i];

        while(!st.empty() && heights[st.top()] > currentHeight) {

            int height = heights[st.top()];

            st.pop();

            int width;

            if(st.empty()) {
                width = i;
            }
            else {
                width = i - st.top() - 1;
            }

            int area = height * width;

            maxArea = max(maxArea, area);
        }

        if(i < n) {
            st.push(i);
        }
    }

    return maxArea;
}
```

### Understanding the important condition

```cpp
while(!st.empty() && heights[st.top()] > currentHeight)
```

The stack maintains increasing bar heights.

When a smaller bar arrives, previously stored taller bars cannot extend any further to the right.

We pop them and calculate their maximum possible rectangle areas.

We use `>` here, so equal heights can remain together in the stack. This is valid with the width calculation above.

### Why do we use `i <= n`?

We process one extra imaginary bar of height zero.

This is called a **sentinel**.

It forces all remaining bars to be popped and their areas calculated.

Without it, some bars might remain in the stack after the loop finishes.

---

## 6. Dry Run

Input:

```cpp
heights = {2, 1, 5, 6, 2, 3};
```

| Index | Height | Operation | Area calculated |
|---|---:|---|---:|
| 0 | 2 | Push index 0 | — |
| 1 | 1 | Pop height 2, width 1 | 2 |
| 2 | 5 | Push index 2 | — |
| 3 | 6 | Push index 3 | — |
| 4 | 2 | Pop height 6, width 1 | 6 |
| 4 | 2 | Pop height 5, width 2 | 10 |
| 5 | 3 | Push index 5 | — |
| 6 | 0 | Pop remaining bars | 3, 8, 6 |

Maximum area = **10**.

---

## 7. Complexity Analysis

| Approach | Time | Auxiliary Space |
|---|---|---|
| Brute Force | O(N²) | O(1) |
| Monotonic Stack | O(N) | O(N) |

Why is the optimized approach O(N)?

Every index is:

- Pushed onto the stack once.
- Popped from the stack at most once.

Although there is a `while` loop inside the `for` loop, each element is processed only a constant number of times overall.

---

## 8. Revision – Stack Patterns Learned

| Problem | Traversal | What the stack finds |
|---|---|---|
| Next Greater Element | Right to left | Next greater value |
| Next Smaller Element | Right to left | Next smaller value |
| Stock Span | Left to right | Previous greater index |
| Largest Rectangle | Left to right | Previous and next smaller boundaries |

### Key things to remember

1. Store indices when position or distance matters.
2. Use a monotonic stack to maintain an ordered sequence.
3. When an element is popped, the current index can act as its right boundary.
4. The new stack top after popping gives the left boundary.
5. If the stack is empty, the rectangle can start at index 0.
6. Always check whether remaining elements need to be processed using a sentinel.

**Core formula to remember:**

```cpp
width = rightBoundary - leftBoundary - 1;

area = height * width;
```