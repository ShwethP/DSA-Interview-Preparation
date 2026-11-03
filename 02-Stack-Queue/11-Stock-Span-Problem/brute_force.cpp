#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> &prices)
{
    int n = prices.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
        int count = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (prices[j] <= prices[i])
                count++;
            else
                break;
        }

        result[i] = count;
    }

    return result;
}

int main()
{

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = stockSpan(arr); // 5, 10, 10, -1, -1

    for (int n : result)
    {
        cout << n << endl;
    }
    return 0;
}