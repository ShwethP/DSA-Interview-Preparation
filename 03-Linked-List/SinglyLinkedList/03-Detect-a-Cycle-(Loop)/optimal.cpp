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

// Optimal using slow and fast pointers

bool hasCycle(Node *first)
{
    Node *slow = first;
    Node *fast = first;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(10);
    Node *third = new Node(15);
    Node *fourth = new Node(20);
    Node *fifth = new Node(25);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;
    bool loop = hasCycle(first);
    cout << loop;

    // Break the cycle before deleting nodes
    fifth->next = nullptr;

    Node *temp = first;

    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}