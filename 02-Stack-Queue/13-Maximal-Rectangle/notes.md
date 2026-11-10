# Problem 13 – Maximal Rectangle

## 1. Problem Understanding

Given a binary matrix containing only `0`s and `1`s, find the largest rectangular area containing only `1`s.

Example:

```cpp
matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};
```

Output:

```cpp
6
```

## 2. Main Pattern – Histogram + Monotonic Stack

We reuse our previous problem:

**Largest Rectangle in Histogram.**

Instead of solving the matrix directly, convert each row into a histogram representing consecutive vertical `1`s.

### Important rule

For every column:

- If the current cell is `'1'`, increase its height.
- If the current cell is `'0'`, reset its height to zero.

```cpp
if(matrix[i][j] == '1')
    heights[j]++;
else
    heights[j] = 0;
```

Why?

Because we need consecutive `1`s, not the total number of `1`s in a column.

## 3. Step-by-Step Example

Input:

```cpp
{
    {'1','0','1','0'},
    {'1','1','1','1'},
    {'1','1','1','1'}
}
```

### After Row 1

```cpp
{1, 0, 1, 0}
```

### After Row 2

```cpp
{2, 1, 2, 1}
```

### After Row 3

```cpp
{3, 2, 3, 2}
```

For every row, apply Largest Rectangle in Histogram.

| Row | Histogram | Largest area |
|---|---|---:|
| 1 | `{1,0,1,0}` | 1 |
| 2 | `{2,1,2,1}` | 4 |
| 3 | `{3,2,3,2}` | 6 |

Final answer = **6**.

## 4. Why Can't We Simply Add All Column Values?

Suppose:

```cpp
{
    {'1','1'},
    {'0','1'},
    {'1','1'}
}
```

Column sums:

```cpp
{2, 3}
```

Applying histogram logic to these sums gives area 4, but the actual maximum rectangle is only 3.

The problem is that the first column contains a zero in the middle.

Therefore:

- Column sum = total number of ones.
- Histogram height = consecutive ones ending at the current row.

We must use consecutive heights.

## 5. C++ Solution

Filename: `MaximalRectangle.cpp`

```cpp
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& a)
{
    int n = a.size();
    int maxArea = 0;
    stack<int> st;

    for(int i = 0; i <= n; i++)
    {
        int current = (i == n) ? 0 : a[i];

        while(!st.empty() && current <= a[st.top()])
        {
            int height = a[st.top()];
            st.pop();

            int width;

            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            int area = height * width;
            maxArea = max(maxArea, area);
        }

        if(i < n)
            st.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    if(matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);
    int maxArea = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        int area = largestRectangleArea(heights);

        maxArea = max(maxArea, area);
    }

    return maxArea;
}
```

## 6. Complexity Analysis

Let:
- R = number of rows.
- C = number of columns.

| Operation | Complexity |
|---|---|
| Updating histogram | O(C) per row |
| Largest Rectangle algorithm | O(C) per row |
| Processing all rows | O(R × C) |
| Auxiliary space | O(C) |

Overall:

- Time Complexity: **O(R × C)**
- Auxiliary Space: **O(C)**

## 7. Important Interview Takeaways

1. Recognize when a complex problem can be reduced to a previously solved problem.
2. Maintain consecutive heights instead of simply counting ones.
3. Reset the height whenever a zero appears.
4. Apply Largest Rectangle in Histogram after processing every row.
5. Keep track of the maximum area across all rows.

### Stack/Queue Revision So Far

| Problem | Main pattern |
|---|---|
| 8. Valid Parentheses | Stack matching |
| 9. Next Greater Element | Monotonic decreasing stack |
| 10. Next Smaller Element | Monotonic increasing stack |
| 11. Stock Span | Previous greater element |
| 12. Largest Rectangle in Histogram | Previous + next smaller boundaries |
| 13. Maximal Rectangle | Histogram + monotonic stack |

**Remember:** Maximal Rectangle is not a completely new stack algorithm. It is an application of the Largest Rectangle in Histogram algorithm.