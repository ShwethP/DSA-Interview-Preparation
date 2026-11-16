# Q11 – Palindrome Linked List

## Problem

Determine whether a singly linked list reads the same forward and backward.

Examples:

- `1 → 2 → 2 → 1` → true
- `1 → 2 → 3 → 2 → 1` → true
- `1 → 2 → 3 → 4` → false

## Approach 1: Brute Force – Vector + Two Pointers

### Idea

1. Traverse the linked list.
2. Store all node values in a vector.
3. Initialize `left = 0` and `right = n - 1`.
4. Compare values from both ends.
5. If any pair differs, return false.
6. If all pairs match, return true.

### C++ Code

```cpp
bool isPalindrome(Node *first)
{
    if (first == nullptr || first->next == nullptr)
        return true;

    vector<int> arr;
    Node *temp = first;

    while (temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        if (arr[left] != arr[right])
            return false;

        left++;
        right--;
    }

    return true;
}
```

### Complexity

- Time: O(N)
- Auxiliary space: O(N)

## Approach 2: Optimal – Reverse the Second Half

### Idea

Avoid storing all values in an additional array.

Use:
1. Slow-fast pointers to find the middle.
2. Reverse the second half.
3. Compare the first half with the reversed second half.
4. Restore the original linked list.

### Step 1: Find the end of the first half

```cpp
Node *slow = first;
Node *fast = first;

while (fast->next != nullptr && fast->next->next != nullptr)
{
    slow = slow->next;
    fast = fast->next->next;
}
```

This places `slow`:
- At the middle node for odd-length lists.
- At the first middle node for even-length lists.

### Step 2: Reverse the second half

```cpp
Node *second = reverseList(slow->next);
```

### Step 3: Compare both halves

```cpp
Node *p1 = first;
Node *p2 = second;

bool palindrome = true;

while (p2 != nullptr)
{
    if (p1->data != p2->data)
    {
        palindrome = false;
        break;
    }

    p1 = p1->next;
    p2 = p2->next;
}
```

### Step 4: Restore the original list

```cpp
slow->next = reverseList(second);
```

Always restore the list before returning, including when a mismatch is found.

## Helper Function – Reverse Linked List

```cpp
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
```

## Complexity

- Time: O(N)
- Auxiliary space: O(1)

## Important Concepts

1. A palindrome reads the same forward and backward.
2. Slow-fast pointers help locate the middle.
3. Reversing only the second half avoids extra array storage.
4. Compare the first half against the reversed second half.
5. The second half is shorter than or equal to the first half.
6. Restore the original list after comparison.
7. Handle empty and single-node lists as palindromes.

## Pattern Recognition

When a linked-list problem asks about symmetry or checking values from both ends:

Think about:
- Finding the middle with slow-fast pointers.
- Reversing the second half.
- Comparing corresponding nodes.

**Key takeaway:** We can use linked-list pointer manipulation to achieve O(1) auxiliary space instead of storing all values in an array.
