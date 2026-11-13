# 08 – Remove Duplicates from a Sorted Linked List

## Problem

Given a sorted singly linked list, remove duplicate values so that every value appears only once.

Example:

```text
Input:  1 → 1 → 2 → 3 → 3 → 4 → 4
Output: 1 → 2 → 3 → 4
```

## Important observation

The linked list is already sorted.

Therefore, duplicate values are always adjacent.

We only need to compare:

```cpp
temp->data == temp->next->data
```

No sorting or hash map is required in the optimal approach.

## Approach 1 – Brute Force (Hash Set)

### Idea

1. Create an unordered set.
2. Traverse the linked list.
3. If the current value already exists in the set, delete the current node.
4. Otherwise, insert the value and move forward.
5. Maintain a previous pointer to reconnect the list after deletion.

### Code

```cpp
Node* removeDuplicatesBrute(Node* first)
{
    unordered_set<int> seen;

    Node* temp = first;
    Node* prev = nullptr;

    while (temp != nullptr)
    {
        if (seen.find(temp->data) != seen.end())
        {
            Node* duplicate = temp;

            prev->next = temp->next;
            temp = temp->next;

            delete duplicate;
        }
        else
        {
            seen.insert(temp->data);

            prev = temp;
            temp = temp->next;
        }
    }

    return first;
}
```

### Complexity

- Time: O(N) average.
- Auxiliary space: O(N).

## Approach 2 – Optimal (Two Adjacent Nodes)

### Idea

1. Start with `temp = first`.
2. Compare `temp` and `temp->next`.
3. If their values are equal, delete `temp->next`.
4. Keep `temp` at the same position because another duplicate might follow.
5. If their values are different, move `temp` forward.
6. Continue until the end.

### Code

```cpp
Node* removeDuplicates(Node* first)
{
    Node* temp = first;

    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->data == temp->next->data)
        {
            Node* duplicate = temp->next;

            temp->next = duplicate->next;

            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }

    return first;
}
```

### Complexity

- Time: O(N).
- Auxiliary space: O(1).

## Important Pointer Concepts

### 1. Why check both pointers?

```cpp
while (temp != nullptr && temp->next != nullptr)
```

We access `temp->next->data`, so both nodes must exist.

### 2. Why don't we move temp after deleting?

Consider:

```text
1 → 1 → 1 → 2
↑
temp
```

After deleting the next node:

```text
1 → 1 → 2
↑
temp
```

Another duplicate is still present. Therefore, we stay at the same node.

### 3. Why move temp when values differ?

If the values are different, the current node has no duplicate immediately after it.

We can safely move forward:

```cpp
temp = temp->next;
```

### 4. Why is no dummy node needed?

We never delete the first node. We only delete the next node when it has the same value as the current node.

Therefore, the original head remains unchanged.

## Comparison

| Approach | Time | Auxiliary Space |
|---|---|---|
| Brute force | O(N) average | O(N) |
| Optimal | O(N) | O(1) |

**Pattern:** Sorted List + Adjacent Comparison + Pointer Reconnection.

**Status:** Completed – Linked List Q08.
