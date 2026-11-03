#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transfer()
    {
        if (outputStack.empty())
        {
            while (!inputStack.empty())
            {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    void push(int x)
    {
        inputStack.push(x);
    }

    void pop()
    {
        transfer();

        if (outputStack.empty())
        {
            cout << "Queue is empty\n";
            return;
        }

        outputStack.pop();
    }

    int front()
    {
        transfer();

        if (outputStack.empty())
            return -1;

        return outputStack.top();
    }

    bool empty()
    {
        return inputStack.empty() && outputStack.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << q.front() << endl; // 10

    q.pop();

    cout << q.front() << endl; // 20
    q.pop();
    q.pop();
    q.pop();

    cout << q.empty() << endl; // 0

    return 0;
}