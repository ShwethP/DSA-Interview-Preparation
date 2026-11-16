# Q10 – Add Two Numbers Represented by Linked Lists

## Problem

Two linked lists represent two numbers. Each node contains one digit, stored in reverse order.

Add the two numbers and return the result as a new linked list, also in reverse order.

**Example:**

Input:

- L1: `2 → 4 → 3` (342)
- L2: `5 → 6 → 4` (465)

Output:

`7 → 0 → 8` (807)

## Approach 1: Convert to Integer and Add

### Idea

1. Traverse each linked list.
2. Multiply each digit by its corresponding power of 10.
3. Construct the two integer values.
4. Add them.

### Complexity

- Time: O(N + M)
- Auxiliary space: O(1)

### Limitation

Normal integer types have a limited range. Large linked lists can represent numbers that overflow `int` or even `long long`.

This is not suitable for arbitrarily large numbers.

## Approach 2: Digit-by-Digit Addition (Optimal)

### Idea

Instead of converting the complete linked lists into integers, add corresponding digits directly.

Maintain:
- `temp`: Current node of the first list.
- `temp1`: Current node of the second list.
- `carry`: Carry from the previous addition.
- `dummy`: Temporary starting node of the result list.
- `tail`: Last node of the result list.

### Formula

```cpp
sum = val1 + val2 + carry;

digit = sum % 10;
carry = sum / 10;
```

### Algorithm

1. Create a dummy node and initialize `tail` to it.
2. Traverse while at least one input list has nodes.
3. Read each node's digit. If a list has ended, use zero.
4. Calculate the sum.
5. Calculate the new digit and carry.
6. Create a new node containing the digit.
7. Attach it to the result using `tail`.
8. Advance the input pointers safely.
9. After the loop, append any remaining carry.
10. Return `dummy.next`.

### C++ Code

```cpp
Node* addingList(Node* first, Node* first1)
{
    Node dummy(-1);
    Node* tail = &dummy;

    Node* temp = first;
    Node* temp1 = first1;

    int carry = 0;

    while (temp != nullptr || temp1 != nullptr)
    {
        int val1 = (temp != nullptr) ? temp->data : 0;
        int val2 = (temp1 != nullptr) ? temp1->data : 0;

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        int digit = sum % 10;

        Node* newNode = new Node(digit);

        tail->next = newNode;
        tail = tail->next;

        if (temp != nullptr)
            temp = temp->next;

        if (temp1 != nullptr)
            temp1 = temp1->next;
    }

    if (carry > 0)
    {
        Node* newNode = new Node(carry);
        tail->next = newNode;
    }

    return dummy.next;
}
```

## Complexity

Let N and M be the lengths of the two input lists.

- Time: O(max(N, M))
- Auxiliary space: O(1) excluding the output.
- Output space: O(max(N, M) + 1) in the worst case.

## Important Concepts

1. `% 10` extracts the last digit.
2. `/ 10` calculates the carry.
3. Use `||` in the loop condition because either list may be longer.
4. Treat a missing node as zero.
5. Always process the remaining carry.
6. Use a dummy node to simplify result-list construction.
7. Use `tail` to append new nodes efficiently.
8. Since digits are stored in reverse order, we can add from the head without reversing either list.

## Pattern Recognition

When a problem involves:
- Numbers represented as linked lists.
- Addition of individual digits.
- Carry propagation.

Think of digit-by-digit addition with a dummy node and tail pointer.

**Key takeaway:** We don't need to construct the complete integer. We can perform arithmetic directly on the linked-list nodes.
