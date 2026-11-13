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

    Node *temp = first;

    while (temp != nullptr)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
    cout << first << endl;

    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}