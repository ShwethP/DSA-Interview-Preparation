#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& a){
    int maxProd = 0;

    for(int i = 0; i<a.size(); i++){
        int currentProd = 1;
        for(int j = i; j< a.size(); j++){
            currentProd *= a[j];
            maxProd = max(maxProd, currentProd);     
        }
    }
    return maxProd;
}


int main(){
    vector<int> a = {2, 0, -10, -2};
    int result = maxProductSubarray(a);
    cout<< result <<endl; //6

    return 0;
}