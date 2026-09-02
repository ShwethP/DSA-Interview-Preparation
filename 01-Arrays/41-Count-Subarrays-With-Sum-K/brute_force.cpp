#include <bits/stdc++.h>
using namespace std;

int numberofsubarrays(vector<int>& a, int k){
    int subArray=0;

    for(int i = 0; i<a.size(); i++){
        int currentSum = 0;
        for(int j = i; j< a.size(); j++){
            currentSum += a[j];

            if(currentSum == k){
                subArray++;

            }
        }
    }
    return subArray;
}


int main(){
    vector<int> a = {1, 2, 3, 5, 4, 1, 3, 2};
    int k = 5;
    int result = numberofsubarrays(a, k);
    cout<< result <<endl; //4

    return 0;
    // for(int a : result){
    //     cout<< a <<endl;
    // }
}