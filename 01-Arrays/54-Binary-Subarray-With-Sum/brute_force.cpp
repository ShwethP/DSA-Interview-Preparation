#include <bits/stdc++.h>
using namespace std;

int binarySubArrywithSum(vector<int>& a, int k){
    int count = 0;
    for (int i = 0; i<a.size(); i++){
        int sum = 0;
        for (int j = i; j<a.size(); j++){
            sum += a[j];
            if (sum == k){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> a = {1, 0, 1, 0, 1};
    int k = 2;
    int result = binarySubArrywithSum(a, k);//4
    cout<< result<< endl;
}