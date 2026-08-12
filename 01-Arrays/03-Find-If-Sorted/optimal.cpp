#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> a  = {1,2,3,4, 4,5,6,6};
    bool sorted = true;

    for(int i = 0; i < a.size()-1; i++){
        if(a[i] > a[i+1]){
            sorted= false;
            break;
        }
    }
    cout<< sorted << endl;
  
}