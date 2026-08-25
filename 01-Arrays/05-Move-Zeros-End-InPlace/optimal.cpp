#include <bits/stdc++.h>
using namespace std;
//  the same problem can be done by using another array by pushing the no zero elements onto new array and thenpuishing zeros at the end until the size equals so that would be more space problem  cause that need O(n) auxilary space
int main(){

    vector <int> a = {0,0, 0,1,0,0,2,0,3,0,5};
    int i = 0;

    for(int j = 0; j < a.size(); j++) {

        cout<< a[j] << " "<< a[i] << endl;

        if(a[j] != 0) {
           swap(a[i], a[j]);
           i++;
        }
    }

    for (int num : a){
        cout<<num<<endl;
    }
}