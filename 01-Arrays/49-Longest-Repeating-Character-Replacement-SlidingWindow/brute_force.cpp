#include <bits/stdc++.h>
using namespace std;

int longestRepeatingChareplacement(string s, int k) {

    vector<int> freq(26, 0);

    int left = 0;
    int maxFreq = 0;
    int maxlength = 0;

    for (int right = 0; right < s.size(); right++) {

        // 1. Add s[right] to the frequency table
        freq[s[right] - 'A']++;

        // 2. Update maxFreq
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // int needed = (right-left+1) - maxFreq; directly calculating this in while loop is necessary
        // 3. If window is invalid,
        while((right-left+1) - maxFreq > k){
        //    shrink from the left before that remove that from the frequency count array
        freq[s[left] -'A']--;
        left++;
        }

        // 4. Update maxlength
        maxlength = max(maxlength, right - left + 1);
    }

    return maxlength;
}

int main(){
    string s = "AABABBA";
    int k = 1;
    int result = longestRepeatingChareplacement(s, k);
    cout<< result <<endl; //4

    return 0;
    
}