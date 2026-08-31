#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveOnes(vector<int>& a, int k) {
//it is sliding windo technique so l is intialized to same as r 
    int zeros = 0, maxLen = 0 , l = 0;
    for(int r =0; r<a.size(); r++){
        //we check for anywher the r reached the inde where zeros stored and update the zeroes and check if zeros are inside limit and update th maxlen
        if(a[r] ==0){
            zeros++;
            // before that wee need to update the l pointer too  if the zeros have crossed the k limit we need to shrink the window from left and on the way if we find any zeros wee need to decrease the xeros number too
            while(zeros>k){
                if(a[l] == 0){
                   zeros--;
                }
                //this is shrinking line
                l++;
            }
        }
//after all we update maxlen updating should not be conditional here
        if(zeros<=k){
            maxLen = max(maxLen, r-l+1);
        }
    }
    return maxLen;
}


int main(){
    vector<int> a = {0,1,0,1,1,1,1};
    int k =1;
    int result = longestConsecutiveOnes(a,k);
    cout<< result <<endl; //4
    return 0;
}