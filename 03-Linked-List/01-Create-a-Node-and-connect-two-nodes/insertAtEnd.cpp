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

    // Insert 20 at ending
    Node *newNode = new Node(20);

    Node *temp = first;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;

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