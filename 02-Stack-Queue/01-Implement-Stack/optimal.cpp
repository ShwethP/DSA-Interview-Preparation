#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creating an integer stack
    stack<int> s;

    // 1. Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // 2. Check the top element
    std::cout << "top();     // " << s.top() << "\n"; // Outputs 30

    // 3. Pop the top element
    s.pop();

    std::cout << "\n";

    // 4. Inspect the stack after pop
    std::cout << "top();     // " << s.top() << "\n";  // Outputs 20
    std::cout << "size();    // " << s.size() << "\n"; // Outputs 2

    // std::stack uses empty(), which returns a boolean
    std::cout << "isEmpty(); // " << (s.empty() ? "true" : "false") << "\n";

    return 0;
}
