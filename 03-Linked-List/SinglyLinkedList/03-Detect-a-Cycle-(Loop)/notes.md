# 03 – Detect a Cycle in a Singly Linked List

## Problem

Determine whether a singly linked list contains a cycle (loop).

A cycle exists when a node's `next` pointer points back to an earlier node instead of pointing to `nullptr`.

### Example: Cycle exists

```text
10 → 20 → 30 → 40 → 50
           ↑         |
           └─────────┘
```

Node 50 points back to node 30.

### Example: No cycle

```text
10 → 20 → 30 → 40 → nullptr
```

The last node points to `nullptr`.

---

## Approach: Floyd's Cycle Detection Algorithm

**Pattern:** Slow and Fast Pointers (Tortoise and Hare).

Use two pointers:

- `slow`: Moves one node at a time.
- `fast`: Moves two nodes at a time.

### Algorithm

1. Initialize both pointers at the head.
2. Move slow one step.
3. Move fast two steps.
4. Compare their addresses.
5. If `slow == fast`, a cycle exists.
6. If fast reaches `nullptr` or cannot move two steps, no cycle exists.

### Code

```cpp
bool hasCycle(Node* first)
{
    Node* slow = first;
    Node* fast = first;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
```

---

## Why Do Slow and Fast Eventually Meet?

When there is a cycle:

- Both pointers eventually enter the cycle.
- Fast moves two steps while slow moves one.
- Fast gains one node on slow during every iteration.
- Because the cycle has a finite number of nodes, fast eventually catches slow.

You do not need to calculate the meeting distance to detect a cycle.

## Important: Compare Addresses, Not Data

```cpp
if (slow == fast)
```

This compares whether both pointers refer to the same node.

Do not use:

```cpp
if (slow->data == fast->data)
```

Different nodes can contain the same data value.

## Why This Loop Condition?

```cpp
while (fast != nullptr && fast->next != nullptr)
```

- `fast != nullptr`: Fast must point to a valid node.
- `fast->next != nullptr`: Fast needs a valid next node to move two steps.

The order is important because the second condition must not be evaluated if fast is already nullptr.

## Complexity

- **Time:** O(N) – The pointers traverse the list and detect a meeting or reach the end.
- **Auxiliary Space:** O(1) – Only two pointers are used.

## Edge Cases

1. Empty list: No cycle.
2. One node pointing to nullptr: No cycle.
3. One node pointing to itself: Cycle.
4. Multiple nodes with a cycle: Cycle detected.
5. Multiple nodes without a cycle: No cycle.

## Common Mistakes

- Comparing node data instead of pointer addresses.
- Forgetting the `fast->next != nullptr` condition.
- Moving fast only one step.
- Traversing a cyclic list normally, which can cause an infinite loop.
- Forgetting to break the cycle before manually deleting nodes in a test program.

## Interview Takeaway

**Problem pattern:** Floyd's Cycle Detection / Slow and Fast Pointers.

Remember:

- If fast reaches nullptr → No cycle.
- If slow and fast meet → Cycle exists.

**Status:** Completed – Singly Linked List 03.