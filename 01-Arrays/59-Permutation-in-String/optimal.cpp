// question is Pattern: Sliding Window + Frequency Counting
// Given two strings s1 and s2, return true if s2 contains a permutation of s1; otherwise, return false.
// A permutation means the same characters with the same frequencies, but possibly in a different order.
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int windowSize = s1.size();

    if (windowSize > s2.size())
    {
        return false;
    }

    vector<int> targetFreq(26, 0);
    vector<int> windowFreq(26, 0);

    // Step 1: Count characters in s1.
    for (char c : s1)
    {
        targetFreq[c - 'a']++;
    }

    // Step 2: Build the first window in s2.
    int left = 0;

    for (int i = 0; i < windowSize; i++)
    {
        windowFreq[s2[i] - 'a']++;
    }

    // Step 3: Check first window.
    if (windowFreq == targetFreq)
    {
        return true;
    }

    // Step 4: Slide the fixed-size window.
    for (int right = windowSize; right < s2.size(); right++)
    {
        // Add new character.
        windowFreq[s2[right] - 'a']++;

        // Remove old character.
        windowFreq[s2[left] - 'a']--;

        left++;

        // Compare frequencies.
        if (windowFreq == targetFreq)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s1 = "xy", s2 = "eidbaooo";
    bool result = checkInclusion(s1, s2);
    cout << result << endl; // Output: 12
    return 0;
}
