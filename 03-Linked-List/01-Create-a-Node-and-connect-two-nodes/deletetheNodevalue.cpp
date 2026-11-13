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

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(10);
    Node *third = new Node(15);
    Node *fourth = new Node(20);

    first->next = second;
    second->next = third;
    third->next = fourth;

    int value = 10;

    Node *curr = first;
    Node *prev = nullptr;

    // Search for the value
    while (curr != nullptr && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    // Check whether value exists
    if (curr == nullptr)
    {
        cout << "Value not found" << endl;
    }
    else
    {
        // If the first node contains the value
        if (prev == nullptr)
        {
            first = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }

        delete curr;
    }
    // Traverse
    Node *temp1 = first;

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