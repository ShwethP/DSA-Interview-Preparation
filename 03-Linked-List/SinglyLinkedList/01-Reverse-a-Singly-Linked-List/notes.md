# 01 – Reverse a Singly Linked List

## Problem
Reverse a singly linked list by changing the direction of its `next` pointers.

**Before:**
```text
5 → 10 → 15 → 20 → nullptr
```

**After:**
```text
20 → 15 → 10 → 5 → nullptr
```

## Approach: Iterative Three-Pointer Technique

We use three pointers:

- `prev`: Points to the previous node.
- `curr`: Points to the current node being processed.
- `nextNode`: Temporarily stores the next node so we don't lose the remaining list.

### Algorithm

1. Initialize `prev = nullptr`.
2. Set `curr = first`.
3. While `curr != nullptr`:
   - Save the next node: `nextNode = curr->next`.
   - Reverse the current connection: `curr->next = prev`.
   - Move `prev` forward: `prev = curr`.
   - Move `curr` forward: `curr = nextNode`.
4. Update the head: `first = prev`.

## C++ Code

```cpp
Node* prev = nullptr;
Node* curr = first;
Node* nextNode = nullptr;

while (curr != nullptr)
{
    nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
}

first = prev;
```

## Dry Run

Initial:
```text
5 → 10 → 15 → 20 → nullptr
```

| Iteration | prev | curr |
|---|---|---|
| Initial | nullptr | 5 |
| 1 | 5 | 10 |
| 2 | 10 | 15 |
| 3 | 15 | 20 |
| 4 | 20 | nullptr |

Final:
```text
20 → 15 → 10 → 5 → nullptr
```

`first = prev` makes node 20 the new head.

## Why Do We Need nextNode?

We must save `curr->next` before changing it.

If we reverse the connection first, the original next node becomes inaccessible through `curr`.

## Complexity

- **Time Complexity:** O(N) – Every node is visited exactly once.
- **Auxiliary Space Complexity:** O(1) – Only three pointers are used.
- No additional linked-list nodes are created.

## Edge Cases

1. Empty list: No iteration; head remains `nullptr`.
2. Single node: The list remains unchanged.
3. Multiple nodes: All links are reversed.

## Common Mistakes

- Not saving the next node before reversing the link.
- Moving `curr` using `curr = curr->next` after reversing.
- Forgetting `first = prev`.
- Updating the head before the reversal is complete.

## Interview Pattern

**Pattern:** Pointer manipulation / Three-pointer technique.

**Remember the order:**
1. Save next.
2. Reverse link.
3. Move previous.
4. Move current.

**Key lesson:** Always preserve the remaining list before changing a node's connection.

**Status:** Completed – Singly Linked List 01.
