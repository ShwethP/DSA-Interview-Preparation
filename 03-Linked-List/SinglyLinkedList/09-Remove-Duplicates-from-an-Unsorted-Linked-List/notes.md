# Q09 – Remove Duplicates from an Unsorted Linked List

## Problem

Given an unsorted singly linked list, remove duplicate values while preserving the first occurrence of every value.

**Example:**

Input:
`8 → 6 → 4 → 6 → 1 → 4 → 2`

Output:
`8 → 6 → 4 → 1 → 2`

## Approach 1: Brute Force – Nested Traversal

### Idea
For every node, traverse all nodes after it and delete any nodes containing the same value.

### Pointers
- `curr`: Selects the node whose duplicates we want to remove.
- `runner`: Scans the remaining nodes.
- `prev`: Tracks the node before `runner`, allowing safe deletion.

### Complexity
- Time: O(N²)
- Auxiliary space: O(1)

## Approach 2: Optimal – Hash Set

### Idea
Use an `unordered_set` to remember values already encountered.

For every node:
1. Check whether its value exists in `seen`.
2. If it exists, delete the current node.
3. Otherwise, insert the value into `seen` and keep the node.

### C++ Code

```cpp
Node* removeDuplicatesUnsorted(Node* first)
{
    unordered_set<int> seen;

    Node* temp = first;
    Node* prev = nullptr;

    while (temp != nullptr)
    {
        if (seen.find(temp->data) != seen.end())
        {
            Node* duplicate = temp;
            temp = temp->next;

            prev->next = temp;

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
- Time: O(N) average
- Auxiliary space: O(N)

## Important Concepts

1. An unsorted list can contain duplicates anywhere, not just next to each other.
2. `unordered_set` provides average O(1) lookup and insertion.
3. `prev` tracks the last node that we are keeping.
4. When deleting `temp`, do not advance `prev`.
5. When keeping `temp`, advance both `prev` and `temp`.
6. Preserve the first occurrence of every value.

## Pattern Recognition

When a problem asks you to remove duplicates from an unsorted linked list:

- Think of a hash set to remember previously visited values.
- Use two pointers (`prev` and `temp`) to safely delete nodes.
- Consider nested traversal if O(1) auxiliary space is required.

**Key takeaway:** Hashing helps us avoid repeatedly scanning the linked list.
