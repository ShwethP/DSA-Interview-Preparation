#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creating an integer queue
    queue<int> q;

    // 1. Push elements onto the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // 2. Check the top element
    cout << "front();     // " << q.front() << "\n"; // Outputs 10
    // 4. Inspect the queue after back
    cout << "back();     // " << q.back() << "\n"; // Outputs 30

    // 3. Pop the top element
    q.pop();

    cout << "\n";

    // 4. Inspect the queue after front
    cout << "front();     // " << q.front() << "\n"; // Outputs 20
    cout << "size();    // " << q.size() << "\n";    // Outputs 2

    // std::stack uses empty(), which returns a boolean
    cout << "isEmpty(); // " << (q.empty() ? "true" : "false") << "\n";

    return 0;
}
