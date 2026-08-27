#include <bits/stdc++.h>
using namespace std;

int longestCons(vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
//traverse in the set as the duplicates removed in above step
//mainly using set or map is in this case best cause we can look up the values easily and check the before and after values
    int longest = 0;
    for(int num : s){
        // the main thing in this problem is to find the first elemt that starts a sequesnce untill we need to skip everything that starts and ends immediately once we find the starting point of a sequence the while loop make sure that we get the longest of it
        if(!s.contains(num-1)){
            int current = num;
            int length = 1;
            
            while(s.contains(current+1)){
                current++;
                length++;
            }
        longest = max(longest, length);
        }
    }
    return longest;

}

// Only start counting when num - 1 doesn't exist; then keep checking num + 1.

int main() {
    vector<int> a = {100, 4, 200, 2, 11, 3, 20, 1};
    cout << "Longest sequence length: " << longestCons(a) << endl; // Outputs 4 (1, 2, 3, 4)
    return 0;
}