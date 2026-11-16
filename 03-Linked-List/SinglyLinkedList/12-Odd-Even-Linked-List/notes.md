# Q12 — Odd Even Linked List

## Problem
Rearrange a linked list so that nodes at odd positions appear first, followed by nodes at even positions.

Preserve the relative order of nodes in both groups.

Example:

Input: `10 → 20 → 30 → 40 → 50`

Output: `10 → 30 → 50 → 20 → 40`

## Optimal Approach: Pointer Manipulation

Maintain three pointers:
- `odd`: current odd-positioned node.
- `even`: current even-positioned node.
- `evenStart`: head of the even-positioned chain.

### C++ Solution

```cpp
Node *oddEvenLinkedList(Node *first)
{
    if (first == nullptr || first->next == nullptr)
        return first;

    Node *odd = first;
    Node *even = first->next;
    Node *evenStart = even;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;

    return first;
}
```

## Key Logic

1. Connect the current odd node to the next odd node.
2. Advance the odd pointer.
3. Connect the current even node to the next even node.
4. Advance the even pointer.
5. After the loop, connect the last odd node to `evenStart`.

### Why save evenStart?
Once the even chain is rearranged, we still need its original starting node to connect it after the odd chain.

### Why this loop condition?

```cpp
while (even != nullptr && even->next != nullptr)
```

Both checks prevent null-pointer access and ensure that another pair of odd/even nodes can be processed.

## Complexity

- Time: O(N)
- Auxiliary Space: O(1)

## Pattern Learned
In-place linked-list rearrangement using multiple pointers. This technique is useful in problems involving splitting, grouping, and reconnecting linked-list nodes.