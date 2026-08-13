#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> a = {1, 2, 3, 1, 2, 4, 2, 6, 7};
    vector<int> b;

    for (int i = 0; i < a.size(); i++){
        // If b is empty OR the last element in b doesn't match a[i], add it
        if(b.empty() || a[i] != b.back()){ 
            b.push_back(a[i]);
        }
    }
    
    for(int c : b){
        cout << c << endl;
    }
    return 0; // Good practice to explicitly return
}
