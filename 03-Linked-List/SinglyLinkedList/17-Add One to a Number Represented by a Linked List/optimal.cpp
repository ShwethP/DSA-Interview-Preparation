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
    Node *nextNode = nullptr;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *addOnetoLL(Node *first)
{
    if (first == nullptr)
        return new Node(1);

    // Step 1: Reverse the listresult
    Node *reversed = reverseList(first);

    Node *temp = reversed;
    int carry = 1;

    // Step 2: Add one and propagate carry
    while (temp != nullptr && carry != 0)
    {
        int sum = temp->data + carry;

        temp->data = sum % 10;
        carry = sum / 10;

        if (carry != 0 && temp->next == nullptr)
        {
            temp->next = new Node(carry);
            carry = 0;
            break;
        }

        temp = temp->next;
    }

    // Step 3: Reverse back
    return reverseList(reversed);
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(9);

    first->next = second;
    second->next = third;

    Node *result = addOnetoLL(first);

    // Traverse
    Node *temp1 = result;

    while (temp1 != nullptr)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    // Delete all nodes
    while (result != nullptr)
    {
        Node *nextNode = result->next;
        delete result;
        result = nextNode;
    }

    return 0;
}