#include <bits/stdc++.h>
using namespace std;

vector<int> reArranged(vector<int>& a){
    int n = a.size();
    int posIndex = 0;
    int negIndex = 1;
    vector<int> result(n); // Allocates a vector of size n filled with 0s
    for(int i =0; i<n; i++){
        if(a[i]>0){
            result[posIndex] = a[i];
            posIndex += 2;
        }
        else{
            result[negIndex] = a[i];
            negIndex += 2;
        }}
    return result;
}

int main(){
    vector<int> a = {3,2,4,-1,-4,-5, 6, -7,8,-9};
    vector<int> result = reArranged(a);

    for(int a : result){
        cout<< a <<endl;
    }
}