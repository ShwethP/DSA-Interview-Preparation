#include <bits/stdc++.h>
using namespace std;
int main(){

    vector <int> a = {1,2,3,4,5};
    int i = 0;

    for(int j = 1; j < a.size(); j++) {
           swap(a[i], a[j]);
           i++;
        
    }

    for (int num : a){
        cout<<num<<endl;
    }
}