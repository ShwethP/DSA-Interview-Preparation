# Q13 — Sort Linked List of 0s, 1s and 2s

## Problem
Given a linked list containing only 0, 1 and 2, sort it in ascending order.

Example:

Input: `2 → 1 → 0 → 2 → 1 → 0`

Output: `0 → 0 → 1 → 1 → 2 → 2`

## Approach 1: Counting and Replacing Node Values

### Steps
1. Traverse the linked list and count the occurrences of 0, 1 and 2.
2. Traverse again from the head.
3. Replace the first `count0` nodes with 0.
4. Replace the next `count1` nodes with 1.
5. Replace the remaining nodes with 2.

### C++ Code

```cpp
Node *sortList(Node *first)
{
    if (first == nullptr)
        return first;

    Node *temp = first;

    int count0 = 0, count1 = 0, count2 = 0;

    // Count occurrences
    while (temp != nullptr)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;

        temp = temp->next;
    }

    // Reset pointer
    temp = first;

    // Replace with 0
    while (count0 > 0)
    {
        temp->data = 0;
        temp = temp->next;
        count0--;
    }

    // Replace with 1
    while (count1 > 0)
    {
        temp->data = 1;
        temp = temp->next;
        count1--;
    }

    // Replace with 2
    while (count2 > 0)
    {
        temp->data = 2;
        temp = temp->next;
        count2--;
    }

    return first;
}
```

## Complexity Analysis

- Counting traversal: O(N)
- Replacing traversal: O(N)
- Total time: O(N)
- Auxiliary space: O(1)

## Important Interview Point

This approach modifies the data stored inside existing nodes.

If the interviewer requires rearranging actual nodes without modifying their data, use the three-chain approach:

- Create a chain for 0s.
- Create a chain for 1s.
- Create a chain for 2s.
- Connect all three chains.

That is another important linked-list pointer manipulation pattern.

## Second Aproach
Node *sortList(Node *first)
{
    if (first == nullptr || first->next == nullptr)
        return first;

    Node zeroDummy(-1);
    Node oneDummy(-1);
    Node twoDummy(-1);

    Node *zeroTail = &zeroDummy;
    Node *oneTail = &oneDummy;
    Node *twoTail = &twoDummy;

    Node *temp = first;

    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        temp->next = nullptr;

        if (temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = temp;
        }
        else
        {
            twoTail->next = temp;
            twoTail = temp;
        }

        temp = nextNode;
    }

    // Connect 0 chain to 1 chain or 2 chain
    zeroTail->next = (oneDummy.next != nullptr)
                         ? oneDummy.next
                         : twoDummy.next;

    // Connect 1 chain to 2 chain
    oneTail->next = twoDummy.next;

    return zeroDummy.next;
}