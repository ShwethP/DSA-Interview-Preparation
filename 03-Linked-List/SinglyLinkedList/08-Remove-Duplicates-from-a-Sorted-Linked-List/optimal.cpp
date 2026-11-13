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

Node *removeDuplicates(Node *first)
{
    Node *temp = first;

    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->data == temp->next->data)
        {
            // TODO: Store the duplicate node
            Node *duplicate = temp->next;

            // TODO: Skip the duplicate node
            temp->next = duplicate->next;

            // TODO: Delete the duplicate node
            delete duplicate;
        }
        else
        {
            // TODO: Move temp forward
            temp = temp->next;
        }
    }

    return first;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(1);
    Node *third = new Node(2);
    Node *fourth = new Node(3);
    Node *fifth = new Node(3);
    Node *sixth = new Node(4);
    Node *seventh = new Node(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    Node *result = removeDuplicates(first);

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