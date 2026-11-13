# 07 – Merge Two Sorted Linked Lists

## Problem

Given two sorted singly linked lists, merge them into one sorted linked list.

Example:

```text
List 1: 1 → 3 → 5
List 2: 2 → 4 → 6

Output: 1 → 2 → 3 → 4 → 5 → 6
```

## Approach 1 – Brute Force

### Idea
1. Store all values from both lists in a vector.
2. Sort the vector.
3. Create a new linked list using the sorted values.

### Code

```cpp
Node* mergeBruteForce(Node* l1, Node* l2)
{
    vector<int> values;

    while (l1 != nullptr)
    {
        values.push_back(l1->data);
        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        values.push_back(l2->data);
        l2 = l2->next;
    }

    sort(values.begin(), values.end());

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    for (int value : values)
    {
        tail->next = new Node(value);
        tail = tail->next;
    }

    Node* result = dummy->next;
    delete dummy;

    return result;
}
```

### Complexity
- Time: O((N + M) log(N + M))
- Auxiliary space: O(N + M), for the vector and newly created nodes.

## Approach 2 – Optimal (Two Pointers)

### Idea
Both lists are already sorted, so we don't need to sort again.

1. Create a dummy node.
2. Maintain a `tail` pointer.
3. Compare the current nodes of both lists.
4. Attach the smaller node to `tail->next`.
5. Advance the selected list pointer.
6. Advance `tail`.
7. Attach the remaining list when one list becomes empty.
8. Return `dummy.next`.

### Code

```cpp
Node* mergeInSorted(Node* l1, Node* l2)
{
    Node dummy(-1);
    Node* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if (l1 != nullptr)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}
```

### Complexity
- Time: O(N + M)
- Auxiliary space: O(1)

## Important Concepts

### 1. Dummy node
A dummy node provides a safe starting point so we don't need separate logic for initializing the first real node.

### 2. Tail pointer
`tail` always represents the last node of the merged list.

After attaching a node, move it forward:

```cpp
tail = tail->next;
```

### 3. Why attach the remaining list directly?

When one list becomes empty, the other list is already sorted. Therefore:

```cpp
tail->next = l1;
```

or

```cpp
tail->next = l2;
```

is sufficient.

### 4. Why return dummy.next?

The dummy node is only a temporary starting anchor. The actual merged list begins at `dummy.next`.

## Comparison

| Approach | Time | Auxiliary Space |
|---|---|---|
| Brute force | O((N+M) log(N+M)) | O(N+M) |
| Optimal | O(N+M) | O(1) |

**Pattern:** Dummy Node + Two Pointers + In-place Node Reconnection.

**Status:** Completed – Linked List Q07.
