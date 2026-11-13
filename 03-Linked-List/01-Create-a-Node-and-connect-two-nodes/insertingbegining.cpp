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

    first->next = second;
    second->next = third;

    // Insert 2 at beginning
    Node *newNode = new Node(2);

    newNode->next = first;
    first = newNode;

    // Traverse
    Node *temp = first;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
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