# 02 – Find the Middle of a Singly Linked List

## Problem

Find and return the middle node of a singly linked list.

Example:

```text
10 → 20 → 30 → 40 → 50 → nullptr
```

Output: `30`

For an even number of nodes, return the **second middle node**.

Example:

```text
10 → 20 → 30 → 40 → 50 → 60 → nullptr
```

Output: `40`

---

## Approach 1: Brute Force (Two Traversals)

### Algorithm

1. Traverse the linked list and count the total number of nodes.
2. Calculate the middle index using `count / 2`.
3. Traverse again until reaching the middle index.
4. Return the middle node.

### Code

```cpp
Node* findMiddle(Node* first)
{
    Node* temp = first;
    int count = 0;

    // Count nodes
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    // Find middle index
    int mid = count / 2;
    int pos = 0;

    Node* middle = first;

    while (pos < mid && middle != nullptr)
    {
        middle = middle->next;
        pos++;
    }

    return middle;
}
```

### Complexity

- Time: O(N) + O(N) = O(N)
- Auxiliary Space: O(1)

---

## Approach 2: Optimal (Slow and Fast Pointers)

### Pattern: Tortoise and Hare

Use two pointers moving at different speeds:

- `slow` moves one step at a time.
- `fast` moves two steps at a time.

When `fast` reaches the end, `slow` reaches the middle.

### Algorithm

1. Initialize both pointers at the head.
2. Continue while `fast` and `fast->next` are not nullptr.
3. Move `slow` one step.
4. Move `fast` two steps.
5. Return `slow`.

### Code

```cpp
Node* findMiddle(Node* first)
{
    Node* slow = first;
    Node* fast = first;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
```

### Complexity

- Time: O(N) – One traversal; fast moves two nodes per iteration.
- Auxiliary Space: O(1) – Only two pointers are used.

---

## Why Does This Work?

Because `fast` moves twice as quickly as `slow`.

When `fast` travels approximately N nodes, `slow` travels approximately N/2 nodes.

Therefore, when `fast` reaches the end, `slow` is at the middle.

## Important Loop Condition

```cpp
while (fast != nullptr && fast->next != nullptr)
```

Both checks are necessary:

- `fast != nullptr` ensures fast points to a valid node.
- `fast->next != nullptr` ensures fast can safely move two steps.

The order matters because C++ evaluates `&&` from left to right and short-circuits.

## Even vs Odd Length

| Number of nodes | Returned middle |
|---|---|
| 5 | 3rd node |
| 6 | 4th node |
| 7 | 4th node |
| 8 | 5th node |

This implementation returns the second middle for even-length lists.

## Interview Takeaway

**Problem pattern:** Slow and Fast Pointers.

Whenever a linked-list problem asks you to find the middle, detect a cycle, or reason about relative pointer speeds, consider this pattern.

**Status:** Completed – Singly Linked List 02.