#include <bits/stdc++.h>
using namespace std;

int binarySubArrywithSum(vector<int>& a, int k){
    unordered_map<int, int> m;
    m[0] = 1;
    int currentsum = 0, count = 0;

    for(int i = 0; i<a.size(); i++){
        currentsum += a[i];

        int needed = currentsum-k;

        if(m.find(needed)!=m.end()){
            count += m[needed];
        }
        m[currentsum]++;
    }
    return count;
}

int main(){
    vector<int> a = {1, 0, 1, 0, 1};
    int k = 2;
    int result = binarySubArrywithSum(a, k);//4
    cout<< result<< endl;
}