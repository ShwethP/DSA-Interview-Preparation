# Stack/Queue – Problem 9: Next Greater Element

## 1. Problem Statement

Given an array, find the first greater element to the right of every element.

If no greater element exists, return `-1`.

Example:

```cpp
Input:  {4, 5, 2, 10, 8}
Output: {5, 10, 10, -1, -1}
```

## 2. Approach 1: Brute Force

For every element:
1. Traverse the elements to its right.
2. Find the first element greater than the current element.
3. Store it and break.
4. If no greater element is found, store `-1`.

### Code

```cpp
vector<int> nextGreaterElement(vector<int> &a)
{
    vector<int> r;

    for (int i = 0; i < a.size(); i++)
    {
        bool found = false;

        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] > a[i])
            {
                r.push_back(a[j]);
                found = true;
                break;
            }
        }

        if (!found)
            r.push_back(-1);
    }

    return r;
}
```

**Complexity:**
- Time: O(N²)
- Space: O(N) for the result vector.

## 3. Approach 2: Monotonic Stack (Optimized)

### What is a Monotonic Stack?

A monotonic stack is a normal stack where elements are maintained in a particular order.

Types:
- Monotonically increasing stack.
- Monotonically decreasing stack.

For Next Greater Element, we use a **monotonically decreasing stack**.

### Why traverse from right to left?

We need the next greater element to the right.

By traversing from right to left, we can maintain useful elements from the right side in our stack.

### Algorithm

For every element, moving from right to left:

1. While the stack is not empty and `st.top() <= a[i]`, pop the stack.
2. If the stack is empty, the answer is `-1`.
3. Otherwise, the answer is `st.top()`.
4. Push the current element onto the stack.

### C++ Code

```cpp
vector<int> nextGreaterElement(vector<int> &a)
{
    int n = a.size();

    vector<int> r(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= a[i])
        {
            st.pop();
        }

        if (st.empty())
            r[i] = -1;
        else
            r[i] = st.top();

        st.push(a[i]);
    }

    return r;
}
```

## 4. Dry Run

Input: `{4, 5, 2, 10, 8}`

| Current element | Stack action | Answer |
|---:|---|---:|
| 8 | Push 8 | -1 |
| 10 | Pop 8, push 10 | -1 |
| 2 | Push 2 | 10 |
| 5 | Pop 2, push 5 | 10 |
| 4 | Push 4 | 5 |

Final answer in original array order:

`{5, 10, 10, -1, -1}`

## 5. Why use `<=` instead of `<`?

We need a strictly greater element.

Consider:

```cpp
arr = {5, 5, 5, 5};
```

Expected output:

```cpp
{-1, -1, -1, -1}
```

Using `<=` removes equal elements because they cannot be the next greater element.

## 6. Important C++ Concept: Vector Initialization

This declaration:

```cpp
vector<int> r;
```

Creates an empty vector. Direct assignment like `r[i] = -1` is invalid because the index does not exist.

Instead:

```cpp
vector<int> r(n);
```

Creates a vector with `n` elements, allowing indexed assignment.

Alternatively, use `push_back()`, but remember that traversing right to left will produce reversed result order unless you reverse the vector.

## 7. Complexity Analysis

| Complexity | Brute Force | Monotonic Stack |
|---|---:|---:|
| Time | O(N²) | O(N) |
| Auxiliary space | O(1) | O(N) |
| Result space | O(N) | O(N) |

Why is the optimized approach O(N)?

- Each element is pushed exactly once.
- Each element is popped at most once.
- Therefore, total stack operations are O(N).

## Key Takeaways

1. Use a stack when recent elements need to be processed first.
2. Monotonic stacks maintain elements in a particular order.
3. For Next Greater Element, traverse from right to left.
4. Remove smaller or equal elements using `<=`.
5. Store answers at their original indices using `r[i]`.
6. Monotonic Stack can optimize certain nested-loop problems from O(N²) to O(N).