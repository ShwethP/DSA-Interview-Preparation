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

    int pos = 2;

    Node *temp = first;

    if (pos < 0 || first == nullptr)
    {
        cout << "Invalid position" << endl;
    }
    else if (pos == 0)
    {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
    else
    {
        Node *temp = first;

        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            Node *deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
        }
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