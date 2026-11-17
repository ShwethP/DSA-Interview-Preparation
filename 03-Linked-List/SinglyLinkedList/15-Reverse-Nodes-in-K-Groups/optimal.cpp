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
Node *reverseNodesinKgroups(Node *first, int k)
{
    if (first == nullptr || k <= 1)
        return first;

    // Dummy node simplifies head handling
    Node dummy(0);
    dummy.next = first;

    Node *groupPrev = &dummy;

    while (true)
    {
        // STEP 1: Find the kth node
        Node *kth = groupPrev;

        for (int i = 0; i < k && kth != nullptr; i++)
        {
            kth = kth->next;
        }

        // Not enough nodes remaining
        if (kth == nullptr)
            break;

        // STEP 2: Save the node after this group
        Node *groupNext = kth->next;

        // STEP 3: Reverse the current group
        Node *prev = groupNext;
        Node *curr = groupPrev->next;

        while (curr != groupNext)
        {
            Node *nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // STEP 4: Connect the reversed group
        Node *oldGroupStart = groupPrev->next;

        groupPrev->next = kth;

        // Prepare for the next group
        groupPrev = oldGroupStart;
    }

    return dummy.next;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    int k = 3;

    Node *result = reverseNodesinKgroups(first, k);

    // Traverse
    Node *temp1 = result;

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

    return 0;
}