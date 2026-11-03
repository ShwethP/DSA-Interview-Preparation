#include <bits/stdc++.h>
using namespace std;
// Circular queue needs count extra to distinguish from full and empty queue
class Queue
{
private:
    int arr[5];
    int front;
    int rear;
    int count, capacity;

public:
    Queue()
    {
        front = 0;
        rear = -1;
        count = 0;
        capacity = 5;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        front = (front + 1) % capacity;
        count--;
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
        return count == 0;
    }

    bool isFull()
    {
        return count == 5;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.getFront() << endl; // 10

    q.dequeue();

    cout << q.getFront() << endl; // 20

    cout << q.getRear() << endl; // 50

    q.enqueue(60);
    cout << q.getFront() << endl; // 20

    cout << q.getRear() << endl; // 60
    cout << q.isEmpty() << endl; // 0
    cout << q.isFull() << endl;  // 0

    return 0;
}