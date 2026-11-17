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

Node *rotateLLbyKnodes(Node *first, int k)
{
    if (first == nullptr || k <= 1)
        return first;

    // first we need to fnd the length also the last node of LL
    Node *tail = first;
    int len = 1;
    while (tail->next != nullptr)
    {
        len++;
        tail = tail->next;
    }
    // we found out lengh cause we need to find precise number for rotation
    // if bigger number is given if we keep rotaing the LL we will eventually get answer but time taken will be so much
    //  so we need to rotate the LL bt k%len still we end up with the same result cause if we rotate k time hen the the LL size it k the resulting LL is same as original one

    k = k % len;

    if (k == 0)
        return first;

    // since we found out last node we can just attatch that to first and keep rotating untill we len-k times
    tail->next = first;

    int nodestopushback = len - k;

    while (nodestopushback > 0)
    {
        nodestopushback--;
        tail = tail->next;
    }
    // finally out tail next ponts to new head of the new LL and we need to detatch the tail by assigning nullptr
    Node *newHead = tail->next;
    tail->next = nullptr;

    return newHead;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    int k = 3;

    Node *result = rotateLLbyKnodes(first, k);

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