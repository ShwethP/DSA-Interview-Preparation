#include <bits/stdc++.h>
using namespace std;

int lengthLongestSubArrAtmostOnes(vector<int>& a, int k){

    unordered_map<int, int> window;
    int left = 0,  maxlength = 0;

    for(int right = 0; right<a.size(); right++){

        window[a[right]]++;

        while(window[1] > k){

            int leftElement = a[left];

            window[leftElement]--;

            if(window[leftElement] == 0){
                window.erase(window[leftElement]);
            }

            left++;

        }
        maxlength = max(maxlength, right-left+1);
    }
    return maxlength;
}

int main(){
    vector<int> a = {1, 1, 0, 1, 0, 0, 1, 1, 1};
    int k = 2;
    int result = lengthLongestSubArrAtmostOnes(a, k);//5
    cout<< result<< endl;
}