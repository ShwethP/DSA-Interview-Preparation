#include <bits/stdc++.h>
using namespace std;
// optimal
int celebrityProblem(vector<vector<int>> &a)
{
    int n = a.size();
    if (n == 0)
        return -1;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();

        if (a[first][second] == 1)
        {
            st.push(second);
        }
        else
        {
            st.push(first);
        }
    }

    // Now top == bottom, representing our single potential candidate
    int candidate = st.top();

    // Step 2: Verify the candidate against both rules
    for (int i = 0; i < n; i++)
    {
        if (i == candidate)
            continue;

        // Candidate must know nobody, and everybody must know candidate
        if (a[candidate][i] == 1 || a[i][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}

int main()
{
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}};
    int result = celebrityProblem(M); // 6 4 4 4
    cout << result << endl;
    return 0;
}