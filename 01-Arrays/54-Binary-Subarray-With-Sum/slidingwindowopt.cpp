#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> a, int k){
    if (k <= 0) return 0;
    int count = 0, left = 0;
        int ones = 0;


    for(int right = 0; right<a.size(); right++){

        if(a[right] == 1) ones ++;

        while(ones > k){
            if(a[left] == 1) ones --;
            left ++;
        }
        count += right - left + 1;
    }
    return count;

}

int binarySubArrywithSum(vector<int>& a, int k){
    int result = atMost(a,k)- atMost(a,k-1);
    return result;
}

int main(){
    vector<int> a = {1, 0, 1, 0, 1};
    int k = 2;
    int result = binarySubArrywithSum(a, k);//4
    cout<< result<< endl;
}