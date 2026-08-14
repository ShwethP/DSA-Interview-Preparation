#include <bits/stdc++.h>
using namespace std;

int main(){
     vector<int> a = {1,2,3,4,5,6};
    int givenk = 3;

    if (a.empty()) return 0;
    
// if k is equal to size of the array given teh it would come back to original position after all the roatations by rhat logic if the k is biggg number we can just devide it by the zsize of array and make it samller that size it self the same result comes so i am getting the modulus of it and rotating that times

    int k = givenk % a.size();

    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());
    for (int num : a){
        cout<<num<<endl;
    }

}