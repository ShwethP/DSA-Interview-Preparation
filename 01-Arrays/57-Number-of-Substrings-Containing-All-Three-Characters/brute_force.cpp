#include <bits/stdc++.h>
using namespace std;

int subarrayswithallThree(string s) {
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        unordered_set<char> st;
        for (int j = i; j < s.size(); j++) {
            st.insert(s[j]);
            if (st.size() == 3) {
                // If a valid substring is found up to index j,
                // all remaining substrings starting at i up to the end of the string are also valid.
                count += (s.size() - j);
                break; 
            }
        }
    }
    return count;
}



int main(){
    string s = "abcabc";
    int result = subarrayswithallThree(s);
    cout<< result <<endl; 
    return 0;
}