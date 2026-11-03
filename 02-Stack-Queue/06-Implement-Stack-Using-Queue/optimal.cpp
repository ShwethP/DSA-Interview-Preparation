#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    queue<int> q;

public:
    void push(int x)
    {
        int size = q.size();

        q.push(x);

        // Move all previous elements behind the new element.
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty\n";
            return;
        }

        q.pop();
    }

    int top()
    {
        if (q.empty())
            return -1;

        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30

    st.pop();

    cout << st.top() << endl; // 20

    cout << st.empty() << endl; // 0

    return 0;
}