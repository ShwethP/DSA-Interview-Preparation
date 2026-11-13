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

    if (first == nullptr)
    {
        cout << "List is empty";
    }
    else if (first->next == nullptr)
    {
        // Only one node exists
        delete first;
        first = nullptr;
    }
    else
    {
        Node *temp = first;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        Node *lastNode = temp->next;
        temp->next = nullptr;
        delete lastNode;
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