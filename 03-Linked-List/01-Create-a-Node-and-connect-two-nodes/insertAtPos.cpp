
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
    Node *third = new Node(20);

    first->next = second;
    second->next = third;

    int pos = 2;
    int value = 14;

    if (pos < 0)
    {
        cout << "Invalid position" << endl;
    }
    else if (pos == 0)
    {
        Node *newNode = new Node(value);
        newNode->next = first;
        first = newNode;
    }
    else
    {
        Node *temp = first;

        // Reach the node just before the required position
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        // Check whether the position is valid
        if (temp == nullptr)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            Node *newNode = new Node(value);

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Traverse and print
    Node *temp1 = first;

    while (temp1 != nullptr)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    cout << endl;

    // Delete all nodes
    while (first != nullptr)
    {
        Node *nextNode = first->next;
        delete first;
        first = nextNode;
    }

    return 0;
}
