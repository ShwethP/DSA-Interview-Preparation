#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;

    stack<int> st; // Stores indices

    for (int i = 0; i <= n; i++)
    {
        // Virtual zero-height bar at the end
        // 1. Unprocessed Elements: Any bars left in the stack at the end of the loop (because they were continually increasing, like the 2, 3 at the end of your example) will never get their areas calculated.
        // 1. The "Flush" Mechanism: By introducing a virtual bar of height 0 at index n, you ensure that every remaining bar in the stack is strictly taller than this virtual bar. This triggers the while loop to pop everything and calculate their final areas using n as the right boundary.

        int currentHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > currentHeight)
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

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(heights);

    return 0;
}