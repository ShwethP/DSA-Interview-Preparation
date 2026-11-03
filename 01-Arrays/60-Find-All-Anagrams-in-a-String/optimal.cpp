// question is Pattern: Sliding Window + Frequency Counting
// Given two strings s and p, return all starting indices of p's anagrams in s.
// A permutation means the same characters with the same frequencies, but possibly in a different order.
#include <bits/stdc++.h>
using namespace std;

vector<int> checkInclusion(string s1, string s2)
{
    vector<int> result;
    int windowSize = s1.size();

    vector<int> targetFreq(26, 0);
    vector<int> windowFreq(26, 0);

    if (windowSize > s2.size())
        return result;

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
        result.push_back(0);
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
            result.push_back(left);
        }
    }

    return result;
}

int main()
{
    string p = "abc", s = "cbaebabacd";
    vector<int> result = checkInclusion(p, s);
    for (int a : result)
    {
        cout << a << endl;
    }
    return 0;
}
