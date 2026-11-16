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

Node *addingList(Node *first, Node *first1)
{
    Node dummy(-1);
    Node *tail = &dummy;

    Node *temp = first;
    Node *temp1 = first1;

    int carry = 0;

    while (temp != nullptr || temp1 != nullptr)
    {
        // Get values from both lists.
        // If a list is exhausted, use 0.

        int val1 = (temp != nullptr) ? temp->data : 0;
        int val2 = (temp1 != nullptr) ? temp1->data : 0;

        // Calculate sum.
        int sum = val1 + val2 + carry;

        // Calculate carry and digit.
        carry = sum / 10;
        int digit = sum % 10;

        // Create a new node containing digit.
        Node *newNode = new Node(digit);

        // Attach it to tail.
        tail->next = newNode;

        // Move tail forward.
        tail = tail->next;

        // Advance temp and temp1 safely.
        if (temp != nullptr)
        {
            temp = temp->next;
        }
        if (temp1 != nullptr)
        {
            temp1 = temp1->next;
        }
    }

    // Handle any remaining carry.
    if (carry > 0)
    {
        Node *newNode = new Node(carry);
        tail->next = newNode;
    }

    return dummy.next;
}

int main()
{
    Node *first = new Node(8);
    Node *second = new Node(9);
    Node *third = new Node(7);

    Node *first1 = new Node(9);
    Node *second1 = new Node(6);
    Node *third1 = new Node(8);
    Node *fourth1 = new Node(4);

    first->next = second;
    second->next = third;

    first1->next = second1;
    second1->next = third1;
    third1->next = fourth1;

    Node *res = addingList(first, first1);

    cout << res << endl;

    // Traverse
    Node *temp1 = res;

    while (temp1 != nullptr)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    // Delete all nodes
    while (first != nullptr)
    {
        Node *nextNode = first->next;
        delete first;
        first = nextNode;
    }

    while (first1 != nullptr)
    {
        Node *nextNode = first1->next;
        delete first1;
        first1 = nextNode;
    }

    return 0;
}