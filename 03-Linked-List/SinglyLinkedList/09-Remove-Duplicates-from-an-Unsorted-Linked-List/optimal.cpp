
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

Node *removeDuplicatesunSorted(Node *first)
{
    unordered_set<int> seen;

    Node *temp = first;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        if (seen.find(temp->data) != seen.end())
        {
            Node *duplicate = temp;

            prev->next = temp->next;
            temp = temp->next;

            delete duplicate;
        }
        else
        {
            seen.insert(temp->data);

            prev = temp;
            temp = temp->next;
        }
    }

    return first;
}

int main()
{
    Node *first = new Node(8);
    Node *second = new Node(6);
    Node *third = new Node(4);
    Node *fourth = new Node(6);
    Node *fifth = new Node(1);
    Node *sixth = new Node(4);
    Node *seventh = new Node(2);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    Node *result = removeDuplicatesunSorted(first);

    // Traverse
    Node *temp1 = result;

    while (temp1 != nullptr)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    // Delete all nodes
    while (result != nullptr)
    {
        Node *nextNode = first->next;
        delete result;
        result = nextNode;
    }

    return 0;
}