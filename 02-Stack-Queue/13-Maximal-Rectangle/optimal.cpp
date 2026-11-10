// for this we are use the largest rectangle in histogram algo again by aading comumns together and making an array out of it
#include <bits/stdc++.h>
using namespace std;

vector<int> addColumns(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix.empty() ? 0 : matrix[0].size();
    vector<int> heights(cols, 0);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
                heights[j]++;
        }
    }
    return heights;
}

int largestRectangleArea(vector<vector<char>> &matrix)
{
    vector<int> a = addColumns(matrix);
    int n = a.size();
    int maxArea = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++)
    {
        int current = (i == n) ? 0 : a[i];

        while ((!st.empty()) && current <= a[st.top()])
        {
            int height = a[st.top()];
            st.pop();

            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }

            int area = height * width;
            maxArea = max(maxArea, area);
        }
        if (i < n)
        {
            st.push(i);
        }
    }

    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << largestRectangleArea(matrix);

    return 0;
}