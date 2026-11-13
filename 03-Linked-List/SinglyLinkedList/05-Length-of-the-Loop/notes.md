# 05 – Find the Length of a Loop

## Problem

Find the number of nodes present inside a cycle in a singly linked list.

Example:

```text
10 → 20 → 30 → 40 → 50
          ↑         |
          └─────────┘
```

The cycle contains:

```text
30 → 40 → 50 → 30
```

Expected output: `3`

## Approach: Floyd's Cycle Detection + Counting

### Phase 1 – Detect the cycle

- Initialize slow and fast at the head.
- Move slow one step.
- Move fast two steps.
- If they meet, a cycle exists.
- If fast reaches nullptr, return 0.

### Phase 2 – Count the loop length

- Keep slow stationary at the meeting node.
- Move fast one step.
- Initialize count to 1.
- Continue moving fast and increment count until it reaches slow again.
- Return count.

## Optimal Code

```cpp
int loopLength(Node* first)
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
            // Phase 2: Count loop length
            int count = 1;
            fast = fast->next;

            while (fast != slow)
            {
                count++;
                fast = fast->next;
            }

            return count;
        }
    }

    return 0;
}
```

## Why Start Count at 1?

The meeting node is already part of the cycle.

We count it first, then move fast around the remaining nodes until it returns to the meeting node.

## Complexity

- Time: O(N) – Cycle detection and one traversal around the cycle.
- Auxiliary Space: O(1) – Only two pointers and one counter are used.

## Common Mistakes

- Starting count at 0 without accounting for the meeting node.
- Moving both pointers while counting.
- Using `fast != nullptr` as the counting condition instead of `fast != slow`.
- Forgetting to return 0 when there is no cycle.

## Interview Takeaway

**Pattern:** Floyd's Cycle Detection + Circular Traversal.

Remember:
1. Detect the cycle.
2. Keep one pointer stationary.
3. Move the other around the cycle.
4. Count until it returns to the starting meeting node.

**Status:** Completed – Singly Linked List 05.