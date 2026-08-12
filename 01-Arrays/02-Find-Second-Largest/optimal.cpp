#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> a ={10, 10, 10, 5};

    int largest = INT_MIN, secondlargest = INT_MIN;
    bool foundSecondLargest = false;

    for(int num : a){
        if(num>largest){
            secondlargest = largest;
            largest = num;
        }
        else if(num>secondlargest && num !=largest){
            secondlargest = num;
            foundSecondLargest = true;
        }
    }
    if (foundSecondLargest)
        cout << secondlargest;
    else
        cout << "No second largest element";


}