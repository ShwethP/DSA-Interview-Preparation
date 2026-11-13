
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

Node *mergeInSorted(Node *l1, Node *l2)
{
    // Dummy node acts as a safe starting anchor
    Node dummy(-1);
    Node *tail = &dummy;

    // Loop only while BOTH lists have nodes left
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
        tail = tail->next; // Advance the tail pointer
    }

    // Attach whatever remains of the non-empty list
    if (l1 != nullptr)
    {
        tail->next = l1;
    }
    else
    {
        tail->next = l2;
    }

    // Return the actual head (skipping the dummy node)
    return dummy.next;
}

int main()
{
    Node *l1first = new Node(1);
    Node *l1second = new Node(3);
    Node *l1third = new Node(6);
    Node *l2first = new Node(2);
    Node *l2second = new Node(5);
    Node *l2third = new Node(7);

    l1first->next = l1second;
    l1second->next = l1third;
    l2first->next = l2second;
    l2second->next = l2third;

    Node *result = mergeInSorted(l1first, l2first);

    // Traverse and print
    Node *temp = result;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // Delete remaining nodes
    while (result != nullptr)
    {
        Node *nextNode = result->next;
        delete result;
        result = nextNode;
    }

    return 0;
}
