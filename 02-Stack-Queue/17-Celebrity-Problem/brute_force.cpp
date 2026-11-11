#include <bits/stdc++.h>
using namespace std;
// brute force
int celebrityProblem(vector<vector<int>> &a)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        bool knowsnobody = true, everybodyknows = true;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (a[i][j] == 1)
            {
                knowsnobody = false;
                break;
            }
            if (a[j][i] == 0)
            {
                everybodyknows = false;
                break;
            }
        }
        if (knowsnobody && everybodyknows)
            return i;
    }
    return -1;
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