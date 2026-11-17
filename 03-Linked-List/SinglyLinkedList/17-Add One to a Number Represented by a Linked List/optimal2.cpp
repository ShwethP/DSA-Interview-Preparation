
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
Node *addOneOptimal(Node *first)
{
    Node dummy(0);
    dummy.next = first;

    Node *lastNonNine = &dummy;
    Node *temp = first;

    // Find the last digit that is not 9
    while (temp != nullptr)
    {
        if (temp->data != 9)
            lastNonNine = temp;

        temp = temp->next;
    }

    // Increment it
    lastNonNine->data++;

    // Set all following digits to zero
    temp = lastNonNine->next;

    while (temp != nullptr)
    {
        temp->data = 0;
        temp = temp->next;
    }

    // If all digits were 9, create a new head
    if (dummy.data == 1)
    {
        Node *newHead = new Node(1);
        newHead->next = first;
        return newHead;
    }

    return first;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(9);

    first->next = second;
    second->next = third;

    Node *result = addOneOptimal(first);

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
