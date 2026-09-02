#include <bits/stdc++.h>
using namespace std;

int numberofsubarrays(vector<int>& a, int k) {

    unordered_map<int, int> m;

    //Before processing any elements, we've already seen prefix sum 0 once.here we are storing frequencies not indexes
    m[0] = 1;

    int currentSum = 0;
    int answer = 0;

    for (int i = 0; i < a.size(); i++) {

        currentSum += a[i];

        int required = currentSum - k;

        // Have we seen the required prefix sum?
        if (m.find(required) != m.end()) {

            answer += m[required];
        }

        // store every occurrence/frequency:
        if (m.find(currentSum) == m.end()) {
            m[currentSum]++;
        }
    }

    return answer;
}


int main(){
    vector<int> a = {1, 2, 3};
    int k = 5;
    int result = numberofsubarrays(a, k);
    cout<< result <<endl; //1

    return 0;
    
}