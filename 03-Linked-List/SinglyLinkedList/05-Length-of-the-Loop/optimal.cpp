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
int loopLength(Node *first)
{
    Node *slow = first;
    Node *fast = first;

    // Phase 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Phase 2: Count cycle length
            int count = 1;
            fast = fast->next;

            while (fast != slow)
            {
                count++;
                fast = fast->next;
            }

            return count;
        }
    }

    return 0;
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

    int loopStart = loopLength(first);

    // Fix 4: Check for nullptr before accessing data

    cout << loopStart;
    // if (loopStart != nullptr)
    // {
    //     cout << loopStart->data << endl;
    // }
    // else
    // {
    //     cout << "No loop found" << endl;
    // }

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
