
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

bool isPalindrome(Node *first)
{
    if (first == nullptr || first->next == nullptr)
    {
        return true;
    }
    vector<int> arr;

    Node *temp = first;

    while (temp != nullptr)
    {
        // Store current node's data
        arr.push_back(temp->data);

        // Move temp forward
        temp = temp->next;
    }

    // Next step: compare from both ends

    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        // Compare arr[left] and arr[right]
        if (arr[left] != arr[right])
        {
            // If they differ, return false
            return false;
        }

        // Move left forward and right backward
        left++;
        right--;
    }

    return true;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(3);
    Node *third = new Node(3);
    Node *fourth = new Node(5);
    Node *fifth = new Node(3);
    Node *sixth = new Node(2);
    Node *seventh = new Node(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    bool result = isPalindrome(first);

    cout << result << endl;
    // Delete all nodes
    while (first != nullptr)
    {
        Node *nextNode = first->next;
        delete first;
        first = nextNode;
    }

    return 0;
}