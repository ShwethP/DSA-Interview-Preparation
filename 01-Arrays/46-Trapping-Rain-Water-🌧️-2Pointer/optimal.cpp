#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& a) {
    int totalWater = 0;
    int n= a.size();

    int left = 0, right = n-1;
    int leftMax = 0, rightMax = 0;

    while(left<right){

        if(a[left]<= a[right]){
            if(a[left]> leftMax){
                leftMax = a[left];
            }
            else{
                totalWater += leftMax - a[left];
            }
            left++;
        }

        else{

            if(a[right]>rightMax){
                rightMax = a[right];
            }
            else{
                totalWater += rightMax - a[right];
            }
            right--;
        }

    }
    return totalWater;
}


int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(a);
    cout<< result<< endl; //6
    return 0;

}