#include <bits/stdc++.h>
using namespace std;
int main(){

    vector <int> a = {1,2,3,4,5};

    if(a.empty()) return 0;
    
    int first = a[0];

    for (int i =0; i< a.size()-1; i++){
        a[i] = a[i+1];
    }
    a[a.size()-1] = first;

    for (int num : a){
        cout<<num<<endl;
    }
}