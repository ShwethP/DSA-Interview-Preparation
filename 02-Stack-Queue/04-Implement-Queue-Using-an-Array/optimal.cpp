#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int arr[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }

        rear++;
        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        front++;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty()
    {
        return front > rear;
    }

    bool isFull()
    {
        return rear == 4;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.getFront() << endl; // 10

    q.dequeue();

    cout << q.getFront() << endl; // 20

    cout << q.getRear() << endl; // 30

    cout << q.isEmpty() << endl; // 0
    cout << q.isFull() << endl;  // 0

    return 0;
}