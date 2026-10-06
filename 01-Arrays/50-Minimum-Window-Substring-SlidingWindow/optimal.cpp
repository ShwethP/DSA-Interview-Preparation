#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {

    unordered_map<char, int> required;
    unordered_map<char, int> window;

    // Store what characters t requires
    for (char c : t) {
        required[c]++;
    }

    int left = 0;

    // Number of required characters currently satisfied
    int formed = 0;

    int minLength = INT_MAX;
    int minStart = 0;

    for (int right = 0; right < s.size(); right++) {

        char c = s[right];

        // Add current character to the window
        window[c]++;

        // If this character is required
        // and we have now reached its required frequency
        if (required.find(c) != required.end() &&
            window[c] == required[c]) {

            formed++;
        }

        // Current window contains everything required
        while (formed == required.size()) {

            // Check whether this is the smallest window
            if (right - left + 1 < minLength) {

                minLength = right - left + 1;
                minStart = left;
            }

            // Character that is about to leave
            char leftChar = s[left];

            window[leftChar]--;

            // If removing it makes this requirement unsatisfied
            if (required.find(leftChar) != required.end() &&
                window[leftChar] < required[leftChar]) {

                formed--;
            }

            left++;
        }
    }

    if (minLength == INT_MAX) {
        return "";
    }

    return s.substr(minStart, minLength);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = minWindow(s, t);
    cout<< result <<endl; //BANC

    return 0;
    
}