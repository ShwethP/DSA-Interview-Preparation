#include <bits/stdc++.h>
using namespace std;

int numOfSubarrayswithKDifInt(vector<int>& a, int k) {
    int count = 0;
    for(int i = 0; i<a.size();i++){
        unordered_set<int> s;
        for(int j = i; j<a.size(); j++){
            s.insert(a[j]);
            if(s.size()==k){
                count ++;
            }
        }
    }

    return count;
}


int main(){
    vector<int> a = {1, 2, 1, 3, 4};
    int k =3;
    int result = numOfSubarrayswithKDifInt(a,k);
    cout<< result <<endl; //7
    return 0;
}