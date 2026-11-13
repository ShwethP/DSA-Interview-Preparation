# 04 – Find the Starting Node of a Cycle

## Problem

Find the exact node where a cycle begins in a singly linked list.

Example:

```text
10 → 20 → 30 → 40 → 50
          ↑         |
          └─────────┘
```

Expected output: `30`

## Approach: Floyd's Cycle Detection Algorithm

This problem has two phases.

### Phase 1 – Detect the cycle

Use two pointers:

- `slow` moves one step.
- `fast` moves two steps.

If they meet, a cycle exists.

### Phase 2 – Find the cycle starting node

1. Reset `slow` to the head.
2. Keep `fast` at the meeting point.
3. Move both pointers one step at a time.
4. When they meet again, that node is the cycle entry.

## Complete Code

```cpp
Node* detectCycle(Node* first)
{
    Node* slow = first;
    Node* fast = first;

    // Phase 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Phase 2: Find cycle entry
            slow = first;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}
```

## Why Does Phase 2 Work?

Define:

- L = Distance from head to cycle entry.
- C = Length of the cycle.
- X = Distance from cycle entry to the first meeting point.
- D = Distance travelled by slow before the meeting.

Since fast moves twice as quickly:

```text
Slow distance = D
Fast distance = 2D
```

Fast has travelled an additional D edges.

At the meeting point, the distance relationship is:

```text
D = L + X + kC
```

Rearranging:

```text
D - L = X + kC
```

This means the distance from the meeting point to the cycle entry is equivalent to L when moving around the cycle.

Therefore:

- Pointer 1 travels L edges from the head.
- Pointer 2 travels L edges from the meeting point.
- They meet at the cycle entry.

Here, k represents the number of additional complete cycles travelled.

## Complexity

- Time: O(N) – The pointers traverse the linked list and cycle.
- Auxiliary Space: O(1) – Only two pointers are used.

## Important Edge Cases

1. Empty list: Return `nullptr`.
2. Single node pointing to itself: Return that node.
3. Single node pointing to `nullptr`: Return `nullptr`.
4. Cycle beginning at the head: Return the head.
5. Cycle beginning somewhere in the middle: Return that entry node.

## Common Mistakes

- Returning the first meeting point instead of the cycle entry.
- Resetting both pointers to the head.
- Moving fast two steps during Phase 2.
- Forgetting to return `nullptr` if no cycle exists.
- Comparing node data instead of pointer addresses.

## Interview Takeaway

**Pattern:** Floyd's Cycle Detection – Two Phases.

Remember:

1. Slow one step, fast two steps → detect cycle.
2. Reset one pointer to head.
3. Both one step → find cycle entry.

**Status:** Completed – Singly Linked List 04.