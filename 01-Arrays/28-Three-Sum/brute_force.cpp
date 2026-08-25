#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(const vector<int>& a){

    for (int i = 0; i< a.size(); i++){
        for(int j=i+1; j< a.size(); j++){
            for(int k =j+1; k< a.size(); k ++){
                if(a[i]+a[j]+a[k] == 0){
                    cout<< a[i] <<" "<< a[j] << " "<< a[k] <<endl;
                }
            }
        }
    }
    return {};
}


int main(){
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    threeSum(a);
    // vector<int> result = threeSum(a);

    // if (!result.empty()) {
    //     cout << "[" << result[0][0] << ", " << result[0][1] << ", " << result[0][2] <<"]" << endl;
    // } else {
    //     cout << "No solution found." << endl;
    // }

    return 0;
}