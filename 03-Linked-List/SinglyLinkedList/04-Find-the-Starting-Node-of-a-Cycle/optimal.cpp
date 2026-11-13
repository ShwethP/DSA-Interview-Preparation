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

// Optimal using slow and fast pointers
Node *StartingOfLoop(Node *first)
{
    if (first == nullptr || first->next == nullptr)
        return nullptr;

    Node *slow = first;
    Node *fast = first;

    // Step 1: Detect if a loop exists
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break; // Fix 1: Exit the loop once they meet
        }
    }

    // Fix 2: If no loop was found, return nullptr
    if (slow != fast)
    {
        return nullptr;
    }

    // Step 2: Find the starting node of the loop
    slow = first;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(10);
    Node *third = new Node(15);
    Node *fourth = new Node(20);
    Node *fifth = new Node(25);
    Node *six = new Node(30);
    Node *seven = new Node(35);
    Node *eight = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = fourth;

    Node *loopStart = StartingOfLoop(first);

    // Fix 4: Check for nullptr before accessing data
    if (loopStart != nullptr)
    {
        cout << loopStart->data << endl;
    }
    else
    {
        cout << "No loop found" << endl;
    }

    // Fix 3: Break the cycle at the actual tail node ('eight')
    eight->next = nullptr;

    Node *temp = first;
    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
