#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            // Stack cannot be empty if we encounter a closing bracket
            if (st.empty())
                return false;

            char top = st.top();
            // Check if the current closing bracket matches the top opening bracket
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '['))
            {
                st.pop(); // Valid match, remove the opening bracket
            }
            else
            {
                return false; // Mismatched brackets
            }
        }
    }
    // If the stack is empty, all brackets were matched correctly
    return st.empty();
}

int main()
{
    string s = "()(])";
    cout << isValid(s) << endl;
}