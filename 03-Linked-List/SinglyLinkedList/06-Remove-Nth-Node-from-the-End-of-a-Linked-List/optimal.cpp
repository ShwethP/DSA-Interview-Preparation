
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

    // Dummy node helps us handle deleting the head
    Node *dummy = new Node(0);
    dummy->next = first;

    Node *slow = dummy;
    Node *fast = dummy;

    // Step 1: Move fast exactly n + 1 steps
    for (int i = 0; i < n + 1; i++)
    {
        if (fast == nullptr)
        {
            delete dummy;
            return first;
        }

        fast = fast->next;
    }

    // Step 2: Move both pointers together
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Delete the node after slow
    Node *removeNode = slow->next;
    slow->next = removeNode->next;

    delete removeNode;

    // Step 4: Update head
    Node *newHead = dummy->next;

    delete dummy;

    return newHead;
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

    int n = 6;

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
