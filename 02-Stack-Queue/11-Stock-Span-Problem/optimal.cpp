// we apply next greater logic th only diffrence is we apply it left to right and we keep track of indices
#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> &prices)
{
    int n = prices.size();
    vector<int> result(n);
    stack<int> st; // Stores indices

    for (int i = 0; i < n; i++)
    {
        // Remove previous prices <= current price
        while (!st.empty() && prices[st.top()] <= prices[i])
        {
            st.pop();
        }

        // Calculate span
        if (st.empty())
            result[i] = i + 1;
        else
            result[i] = i - st.top();

        // Store current index
        st.push(i);
    }

    return result;
}

int main()
{

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = stockSpan(arr); // 1, 1, 1, 2, 1, 4, 6

    for (int n : result)
    {
        cout << n << endl;
    }
    return 0;
}