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

    int value = 20;

    first->next = second;
    second->next = third;
    third->next = fourth;

    Node *temp = first;
    int count = 0;

    // just to count
    // int count = 0;

    // while (temp != nullptr)
    // {
    //     count++;
    //     temp = temp->next;
    // }
    // cout << count << endl;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            cout << "found at position " << count << endl;
            break;
        }
        count++;
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "element not there" << endl;
    }

    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}