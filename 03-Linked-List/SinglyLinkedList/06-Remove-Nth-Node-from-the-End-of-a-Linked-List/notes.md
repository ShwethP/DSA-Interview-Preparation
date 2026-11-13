# 06 – Remove Nth Node From the End of a Linked List

## Problem

Given the head of a linked list and an integer `n`, remove the nth node from the end and return the updated head.

Example:

```text
Input:  10 → 20 → 30 → 40 → 50
n = 2

Output: 10 → 20 → 30 → 50
```

The 2nd node from the end is `40`.

---

## Approach 1: Brute Force – Two Traversals

### Idea

1. Traverse the list and count the total number of nodes.
2. Calculate the position from the beginning:

   `position = length - n`

3. Traverse again to reach the node just before the target.
4. Change its `next` pointer to skip the target node.
5. Delete the target node.

### Complexity

- Time: O(N) – two traversals.
- Space: O(1).

### Limitation

We need to traverse the list twice.

---

## Approach 2: Optimal – Two Pointers + Dummy Node

### Main idea

Use two pointers: `slow` and `fast`.

Maintain a gap of `n + 1` nodes between them.

When `fast` reaches `nullptr`, `slow` will be at the node just before the node we need to delete.

### Why do we use a dummy node?

Consider removing the first node:

```text
10 → 20 → 30 → 40
```

If we want to remove the 4th node from the end, we must delete `10`.

Normally, deleting the head requires a separate condition.

A dummy node solves this:

```text
dummy → 10 → 20 → 30 → 40
```

Now even the original head has a predecessor: `dummy`.

### Code

```cpp
Node* removeNthFromLast(Node* first, int n)
{
    Node* dummy = new Node(0);
    dummy->next = first;

    Node* slow = dummy;
    Node* fast = dummy;

    // Move fast n + 1 steps
    for (int i = 0; i < n + 1; i++)
    {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete target node
    Node* removeNode = slow->next;
    slow->next = removeNode->next;
    delete removeNode;

    // Update head
    Node* newHead = dummy->next;

    delete dummy;

    return newHead;
}
```

This version assumes `n` is valid: `1 <= n <= list length`.

### Dry run

```text
List: 10 → 20 → 30 → 40 → 50
n = 2
```

Start:

```text
dummy → 10 → 20 → 30 → 40 → 50
slow
fast
```

Move `fast` `n + 1 = 3` steps:

```text
dummy → 10 → 20 → 30 → 40 → 50
slow                  fast
```

Move both until `fast` becomes `nullptr`:

```text
dummy → 10 → 20 → 30 → 40 → 50 → nullptr
                 slow                  fast
```

Now:

- `slow` points to `20`.
- `slow->next` points to `30`.
- Delete `30`.

Result:

```text
10 → 20 → 40 → 50
```

### Complexity

- Time: O(N) – one traversal overall.
- Space: O(1) – only a few pointers.

---

## Important concepts to remember

| Concept | Meaning |
|---|---|
| Dummy node | Temporary node placed before the original head |
| Fast pointer | Moves ahead by `n + 1` steps |
| Slow pointer | Eventually reaches the predecessor of the target |
| `slow->next` | Node that needs to be deleted |
| `slow->next = removeNode->next` | Skips the target node |
| `delete removeNode` | Frees the deleted node's memory |
| `dummy->next` | Updated head of the list |

## Edge cases

- `n = 1`: Delete the last node.
- `n = length`: Delete the first node.
- One node with `n = 1`: Delete the only node; return `nullptr`.

## Common mistakes

1. Starting `slow` at `first` instead of `dummy`.
2. Moving `fast` only `n` steps instead of `n + 1`.
3. Forgetting to update the head using `dummy->next`.
4. Forgetting to delete the removed node.
5. Traversing the old `first` pointer after deleting the original head. Always use the returned head.

**Pattern learned:** Two pointers with a fixed gap + dummy node.

**Status:** Completed.