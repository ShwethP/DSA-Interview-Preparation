# Q15 – Reverse Nodes in K Groups

## Problem
Reverse a linked list in groups of `k` nodes. If fewer than `k` nodes remain, leave that final group unchanged.

## Optimal approach: Iterative pointer reversal

### Important pointers
- `groupPrev`: node immediately before the current group.
- `kth`: last node of the current group.
- `groupNext`: first node after the current group.
- `prev`, `curr`, `nextNode`: pointers used for reversal.

### Algorithm
1. Create a dummy node pointing to the head.
2. Find the kth node starting from `groupPrev`.
3. If kth is nullptr, stop because fewer than k nodes remain.
4. Save `groupNext = kth->next`.
5. Initialize `prev = groupNext` and `curr = groupPrev->next`.
6. Reverse nodes until `curr == groupNext`.
7. Connect `groupPrev->next = kth`.
8. Move `groupPrev` to the old group start, which is now the tail.
9. Repeat for the next group.

### Important reversal difference

Normal reversal:
```cpp
prev = nullptr;
```

K-group reversal:
```cpp
prev = groupNext;
```

This automatically connects the reversed group's tail to the remaining list.

## Complexity
- Time: O(N)
- Auxiliary space: O(1)

## Key interview takeaway
Use a dummy node to simplify head changes. Save the next group's starting node before reversing, and leave an incomplete final group unchanged.