#include <bits/stdc++.h>
using namespace std;

string longestUniqueSubstring(string s) {

    unordered_map<char, int> window;

    int left = 0;
    int maxLength = 0;
    int start = 0;

    for (int right = 0; right < s.size(); right++) {

        // Add current character
        window[s[right]]++;

        // Shrink until duplicate is removed
        while (window[s[right]] > 1) {

            window[s[left]]--;
            left++;
        }

        // Current window is valid
        int currentLength = right - left + 1;

        // Update only when we found a longer substring
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = left;
        }
    }

    return s.substr(start, maxLength);
}

int main(){
    string s = "abcbcaabcde";
    string result = longestUniqueSubstring(s);
    cout<< result <<endl; //abcde
    return 0;
    
}