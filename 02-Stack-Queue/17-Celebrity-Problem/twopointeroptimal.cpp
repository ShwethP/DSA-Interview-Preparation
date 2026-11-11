#include <bits/stdc++.h>
using namespace std;
// optimal
int celebrityProblem(vector<vector<int>> &a)
{
    int n = a.size(), top = 0, bottom = n - 1;
    while (top < bottom)
    {
        if (a[top][bottom] == 1)
        {
            top++;
        }
        else
            bottom--;
    }

    // Now top == bottom, representing our single potential candidate
    int candidate = top;

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