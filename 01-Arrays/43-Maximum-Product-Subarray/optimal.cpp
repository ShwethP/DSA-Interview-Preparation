#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& a) {
    if (a.empty()) return 0;
    
    int maxProd = a[0];
    int minProd = a[0];
    int answer = a[0];

    // Start loop from index 1 because index 0 is already initialized above
    for (int i = 1; i < a.size(); i++) {
        int current = a[i];
        int oldmax = maxProd;
        int oldmin = minProd;

        // Use braces {} inside max/min to allow 3-way comparisons in C++
        maxProd = max({current, current * oldmax, current * oldmin});
        minProd = min({current, current * oldmax, current * oldmin});

        answer = max(answer, maxProd);
    }
    
    return answer;
}


int main(){
    vector<int> a = {2, 0, -10, -2};
    int result = maxProductSubarray(a);
    cout<< result <<endl; //6

    return 0;
}