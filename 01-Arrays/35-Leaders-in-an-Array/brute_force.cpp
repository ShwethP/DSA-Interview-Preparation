#include <bits/stdc++.h>
using namespace std;

vector<int> leadersBrute(vector<int>& a) {

    vector<int> result;

    for (int i = 0; i < a.size(); i++) {

        bool isLeader = true;

        for (int j = i + 1; j < a.size(); j++) {

            if (a[j] >= a[i]) {
                isLeader = false;
                break;
            }
        }

        if (isLeader) {
            result.push_back(a[i]);
        }
    }

    return result;
}

int main(){
    vector<int> a = {6, 20, 0, 20, 10, 4, 6};
    vector<int> result = leadersBrute(a);

    for(int a : result){
        cout<< a <<endl;
    }
}