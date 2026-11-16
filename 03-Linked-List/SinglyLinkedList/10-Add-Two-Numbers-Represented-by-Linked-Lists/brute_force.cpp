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

// int addingList(Node *first)
// {
//     Node *temp = first;
//     int c = 0;
//     int res = 0;
//     while (temp != nullptr)
//     {
//         int mul = (c == 0) ? 1 : pow(10, c);
//         res = res + (mul * temp->data);
//         temp = temp->next;
//         c++;
//     }
//     return res;
// }

int addingList(Node *first)
{
    Node *temp = first;
    int multiplier = 1;
    int res = 0;

    while (temp != nullptr)
    {
        res += temp->data * multiplier;
        multiplier *= 10;
        temp = temp->next;
    }

    return res;
}

int main()
{
    Node *first = new Node(2);
    Node *second = new Node(4);
    Node *third = new Node(3);

    Node *first1 = new Node(5);
    Node *second1 = new Node(6);
    Node *third1 = new Node(4);

    first->next = second;
    second->next = third;

    first1->next = second1;
    second1->next = third1;

    Node *prev = nullptr;
    Node *curr = first;
    Node *nextNode = nullptr;

    int l1 = addingList(first);
    int l2 = addingList(first1);

    cout << l1 << "+" << l2 << "=" << l1 + l2 << endl;

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

    while (first1 != nullptr)
    {
        Node *nextNode = first1->next;
        delete first1;
        first1 = nextNode;
    }

    return 0;
}