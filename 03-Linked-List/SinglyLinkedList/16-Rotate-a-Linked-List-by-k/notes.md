# Q16 – Rotate Linked List (Right Rotation)

## Problem
Rotate a linked list to the right by `k` positions.

Example:

Input: `10 → 20 → 30 → 40 → 50`, `k = 3`

Output: `30 → 40 → 50 → 10 → 20`

## Optimal approach

1. Find the linked list length and last node.
2. Calculate effective rotations: `k = k % len`.
3. If `k == 0`, return the original list.
4. Connect the last node to the head, temporarily forming a circular linked list.
5. Find the new tail by moving `len - k` steps from the original tail.
6. The node after the new tail becomes the new head.
7. Break the circular connection by setting `newTail->next = nullptr`.

## Important code

```cpp
int len = 1;
Node *tail = first;

while (tail->next != nullptr)
{
    len++;
    tail = tail->next;
}

k = k % len;

if (k == 0)
    return first;

tail->next = first;

int steps = len - k;

while (steps > 0)
{
    tail = tail->next;
    steps--;
}

Node *newHead = tail->next;
tail->next = nullptr;

return newHead;
```

## Why use k % len?

Rotating a list by its full length produces the original list.

For length 5:
- k = 5 → no change
- k = 7 → same as rotating twice
- k = 12 → same as rotating twice

## Complexity
- Time: O(N)
- Auxiliary space: O(1)

## Common mistakes
- Initializing `len = 0` when starting traversal from the first node and stopping at the tail. Use `len = 1`.
- Forgetting the `k == 0` check after modulo.
- Forgetting to break the circular list.
- Confusing right rotation with left rotation.