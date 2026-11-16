# Q14 — Intersection Point of Two Linked Lists

## Problem
Find the node where two singly linked lists intersect.

Important: Intersection means the same physical node in memory, NOT merely equal node values.

## Approach 1: Brute Force

For every node in List 1, traverse List 2 and compare addresses.

```cpp
Node *findIntersectionBrute(Node *l1, Node *l2)
{
    Node *tmp1 = l1;

    while (tmp1 != nullptr)
    {
        Node *tmp2 = l2;

        while (tmp2 != nullptr)
        {
            if (tmp1 == tmp2)
                return tmp1;

            tmp2 = tmp2->next;
        }

        tmp1 = tmp1->next;
    }

    return nullptr;
}
```

Time: O(N × M)

Space: O(1)

## Approach 2: Optimal Two-Pointer Method

### Logic
- Initialize `p1` at List 1 and `p2` at List 2.
- Move both one node at a time.
- When `p1` reaches nullptr, redirect it to List 2.
- When `p2` reaches nullptr, redirect it to List 1.
- Continue until both pointers are equal.

### Code

```cpp
Node *findIntersection(Node *l1, Node *l2)
{
    Node *p1 = l1;
    Node *p2 = l2;

    while (p1 != p2)
    {
        p1 = (p1 == nullptr) ? l2 : p1->next;
        p2 = (p2 == nullptr) ? l1 : p2->next;
    }

    return p1;
}
```

### Why does switching work?
Both pointers travel the same combined distance:

- List 1 + List 2

This compensates for the difference in lengths before the intersection.

If an intersection exists, they meet at the shared node.

If no intersection exists, both eventually become nullptr.

### Complexity
- Time: O(N + M)
- Auxiliary Space: O(1)

## Important Interview Concepts
1. Compare node addresses using `p1 == p2`, not node values.
2. Save the actual shared node when constructing test cases.
3. Switching heads balances the traversal distances.
4. The algorithm also handles lists with no intersection.