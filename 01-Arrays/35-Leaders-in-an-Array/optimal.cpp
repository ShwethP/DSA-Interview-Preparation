#include <bits/stdc++.h>
using namespace std;

vector<int> leadersBrute(vector<int>& a) {

    vector<int> result;
    int n = a.size();
    int rightMax = INT_MIN;

    for(int i = n-1; i>=0; i--){
        if(a[i] > rightMax){
            result.push_back(a[i]);
            rightMax = a[i];
        }

    }
    reverse(result.begin(), result.end());

    return result;
}

int main(){
    vector<int> a = {6};
    vector<int> result = leadersBrute(a);

    for(int a : result){
        cout<< a <<endl;
    }
}