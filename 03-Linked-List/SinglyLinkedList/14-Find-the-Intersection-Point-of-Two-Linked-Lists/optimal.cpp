// Given the heads of two singly linked lists, find the node where they intersect.
// Important: Intersection means they share the same physical node in memory, not merely a node containing the same value.

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

// 1. Start one pointer at each list's head.
// 2. Move both pointers one step at a time.
// 3. When p1 reaches the end, redirect it to l2.
// 4. When p2 reaches the end, redirect it to l1.
// 5. They eventually meet at the intersection, or both become nullptr if there is no intersection.
// - Time: O(N + M)
// - Auxiliary space: O(1)

Node *findIntersection(Node *l1, Node *l2)
{
    Node *p1 = l1;
    Node *p2 = l2;

    while (p1 != p2)
    {
        p1 = (p1 == nullptr) ? l2 : p1->next;
        p2 = (p2 == nullptr) ? l1 : p2->next;
    }

    return p1;
}

int main()
{
    Node *l1first = new Node(1);
    Node *l1second = new Node(3);
    Node *l1third = new Node(6);
    Node *l1fourth = new Node(8);
    Node *l1fifth = new Node(10);

    Node *l2first = new Node(2);
    Node *l2second = new Node(5);
    Node *l2third = new Node(7);

    l1first->next = l1second;
    l1second->next = l1third;
    l1third->next = l1fourth;
    l1fourth->next = l1fifth;

    l2first->next = l2second;
    l2second->next = l2third;
    l2third->next = l1fourth;

    Node *result = findIntersection(l1first, l2first);

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
