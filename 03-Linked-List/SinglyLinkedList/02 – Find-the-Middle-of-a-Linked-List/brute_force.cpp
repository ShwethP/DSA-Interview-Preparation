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

// brute force

Node *findMiddle(Node *first)
{
    // Your code here
    Node *temp = first;
    // just to count
    int count = 0;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2, pos = 0;
    Node *middle = first;

    while (pos < mid && middle != nullptr)
    {
        middle = middle->next;
        pos++;
    }
    return middle;
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
    Node *middle = findMiddle(first);
    cout << middle->data;

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