
#include <bits/stdc++.h>
using namespace std;

// Step 1: Largest Rectangle in Histogram
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;

    stack<int> st;

    for (int i = 0; i <= n; i++)
    {
        int current = (i == n) ? 0 : heights[i];

        while (!st.empty() && current <= heights[st.top()])
        {
            int height = heights[st.top()];
            st.pop();

            int width;

            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            int area = height * width;
            maxArea = max(maxArea, area);
        }

        if (i < n)
            st.push(i);
    }

    return maxArea;
}

// Step 2: Maximal Rectangle in Binary Matrix
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);

    int maxArea = 0;

    for (int i = 0; i < rows; i++)
    {
        // Update histogram for current row
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        // Apply histogram algorithm after every row
        int area = largestRectangleArea(heights);

        maxArea = max(maxArea, area);
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

    cout << maximalRectangle(matrix);

    return 0;
}
