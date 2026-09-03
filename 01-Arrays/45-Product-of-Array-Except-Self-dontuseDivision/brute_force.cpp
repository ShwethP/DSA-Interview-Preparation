#include <bits/stdc++.h>
using namespace std;

vector<int> arrayProductExceptSelf(vector<int>& a){
    vector<int> result;
    int n = a.size();
    for(int i = 0; i<n; i++){
        int l =1, r=1;
        for(int j =0; j<i; j++){
            l *= a[j];
        }
        for(int k =i+1;k<n; k++){
            r *= a[k];
        }
        result.push_back(l*r);
    }
    return result;
}


int main(){
    vector<int> a = {1, 2, 0, 4};
    vector<int> result = arrayProductExceptSelf(a);

    for(int a : result){
        cout<< a <<endl;
    }
    return 0;

}