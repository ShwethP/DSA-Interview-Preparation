
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
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
bool isPalindromeOptimal(Node *first)
{
    if (first == nullptr || first->next == nullptr)
        return true;

    // STEP 1: Find the end of the first half
    Node *slow = first;
    Node *fast = first;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // STEP 2: Reverse the second half
    Node *second = reverseList(slow->next);

    // STEP 3: Compare both halves
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

    // STEP 4: Restore the original list
    slow->next = reverseList(second);

    return palindrome;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(2);
    Node *fifth = new Node(3);
    Node *sixth = new Node(2);
    Node *seventh = new Node(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    bool result = isPalindromeOptimal(first);

    cout << result << endl;
    // Delete all nodes
    while (first != nullptr)
    {
        Node *nextNode = first->next;
        delete first;
        first = nextNode;
    }

    return 0;
}