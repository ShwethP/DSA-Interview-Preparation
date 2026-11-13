
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

Node *removeNthFromLast(Node *first, int n)
{
    if (first == nullptr || n <= 0)
        return first;

    // Step 1: Count the nodes
    int length = 0;
    Node *temp = first;

    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }

    // Invalid n
    if (n > length)
        return first;

    // Step 2: Find the position from the beginning
    int position = length - n;

    // Step 3: Handle deleting the first node
    if (position == 0)
    {
        Node *removeNode = first;
        first = first->next;
        delete removeNode;
        return first;
    }

    // Step 4: Reach the node before the target
    Node *prev = first;

    for (int i = 0; i < position - 1; i++)
    {
        prev = prev->next;
    }

    // Step 5: Delete the target node
    Node *removeNode = prev->next;
    prev->next = removeNode->next;
    delete removeNode;

    return first;
}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(10);
    Node *third = new Node(15);
    Node *fourth = new Node(20);
    Node *fifth = new Node(25);
    Node *sixth = new Node(30);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    int n = 4;

    Node *result = removeNthFromLast(first, n);

    // Traverse and print
    Node *temp = result;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // Delete remaining nodes
    while (result != nullptr)
    {
        Node *nextNode = result->next;
        delete result;
        result = nextNode;
    }

    return 0;
}
