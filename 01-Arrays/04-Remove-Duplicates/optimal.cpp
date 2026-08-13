#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> a = {1,1,1,2,2,2,3,3,4,5,6,6};

    if(a.empty()) return 0;

    int i = 0;

    for(int j=1; j<a.size(); j++){
        if(a[j] != a[i]){
            i++;
            a[i] = a[j];
        }
    }
    //at the end of the loop the i+1 number of elements will be remained as final and unique array 
    cout<<i+1<<endl;
    //lets resize the resultant array
    a.resize(i+1);
    for (int num : a){
        cout<<num<<endl;
    }
}