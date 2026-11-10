#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &a)
{
    int n = a.size();

    vector<int> r(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        // while loop will check oif top in st is less that current element if yes we pop
        while (!st.empty() && st.top() <= a[i])
        {
            st.pop();
        }
        // if we find stack empty means no greater element present in future else we use the top one as it is the next greater to current element
        if (st.empty())
            r[i] = -1;

        else
            r[i] = st.top();
        st.push(a[i]);
    }
    return r;
}

int main()
{

    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(arr); // 5, 10, 10, -1, -1

    for (int n : result)
    {
        cout << n << endl;
    }
    return 0;
}