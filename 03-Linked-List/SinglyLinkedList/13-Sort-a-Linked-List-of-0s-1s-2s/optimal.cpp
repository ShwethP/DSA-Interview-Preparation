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

Node *sortZeroOneTwo(Node *first)
{
    if (first == nullptr || first->next == nullptr)
        return first;

    // so my idea is to traverse throgh LL and keep count of 1s 0s and 2s and later in the same LL replace the elements accordingly so acc to me the time complexty ofr travesring O(N) + replacing O(n) total O(n) and O(1) space complexity

    Node *temp = first;
    int count0 = 0, count1 = 0, count2 = 0;

    while (temp != nullptr)
    {
        if (temp->data == 0)
            count0++;

        else if (temp->data == 1)
            count1++;

        else
            count2++;
        temp = temp->next;
    }
    temp = first;

    while (count0 > 0)
    {
        temp->data = 0;
        temp = temp->next;
        count0--;
    }

    while (count1 > 0)
    {
        temp->data = 1;
        temp = temp->next;
        count1--;
    }

    while (count2 > 0)
    {
        temp->data = 2;
        temp = temp->next;
        count2--;
    }

    return first;
}

int main()
{
    Node *first = new Node(2);
    Node *second = new Node(1);
    Node *third = new Node(0);
    Node *fourth = new Node(1);
    Node *fifth = new Node(0);
    Node *sixth = new Node(2);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    Node *result = sortZeroOneTwo(first);

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