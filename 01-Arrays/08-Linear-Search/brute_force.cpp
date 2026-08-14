#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int> &a, int k){
    for (int i=0; i<a.size(); i++){
        if(a[i]==k){
            return i;
        }
    }
    return -1;

}

int main(){
    vector<int> a = {1,3,4,6,7,8,9};
    int k = 100;
    cout<<linearSearch(a,k)<<endl;

}