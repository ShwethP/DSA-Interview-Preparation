#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int arr[5];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    void push(int x)
    {
        if (topIndex == 4)
        {
            cout << "Stack Overflow\n";
            return;
        }

        topIndex++;
        arr[topIndex] = x;
    }

    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        topIndex--;
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[topIndex];
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool isFull()
    {
        return topIndex == 4;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30

    st.pop();

    cout << st.top() << endl; // 20

    cout << st.isEmpty() << endl; // 0
    cout << st.isFull() << endl;  // 0

    return 0;
}