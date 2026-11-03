# Q59. Permutation in String

## Problem

Given two strings `s1` and `s2`, determine whether `s2` contains a contiguous substring that is a permutation of `s1`.

Example:

```cpp
s1 = "ab";
s2 = "eidbaooo";

// Output: true
```

Because `"ba"` is a permutation of `"ab"`.

## 1. Brute Force Idea

Generate every substring of `s2` having length `s1.size()`, sort it, and compare it with sorted `s1`.

This is inefficient because sorting is repeated for every window.

Approximate complexity: `O((N-M+1) * M log M)`, where `M = s1.size()` and `N = s2.size()`.

## 2. Optimal — Fixed-Size Sliding Window + Frequency Array

### Intuition

A permutation has:
- The same characters.
- The same character frequencies.
- A potentially different order.

Since every permutation has the same length as `s1`, our window size is fixed:

```cpp
int windowSize = s1.size();
```

Use two frequency arrays:

```cpp
vector<int> targetFreq(26, 0);
vector<int> windowFreq(26, 0);
```

- `targetFreq`: frequencies of characters in `s1`.
- `windowFreq`: frequencies of characters in the current window of `s2`.

For lowercase English letters, 26 positions are enough.

### Character indexing

```cpp
freq[c - 'a']++;
```

For example:
- `'a' - 'a' = 0`
- `'b' - 'a' = 1`
- `'z' - 'a' = 25`

### Complete Code

```cpp
bool checkInclusion(string s1, string s2)
{
    int windowSize = s1.size();

    if (windowSize > s2.size())
        return false;

    vector<int> targetFreq(26, 0);
    vector<int> windowFreq(26, 0);

    for (char c : s1)
        targetFreq[c - 'a']++;

    int left = 0;

    // Build first window.
    for (int i = 0; i < windowSize; i++)
        windowFreq[s2[i] - 'a']++;

    if (windowFreq == targetFreq)
        return true;

    // Slide window.
    for (int right = windowSize; right < s2.size(); right++)
    {
        windowFreq[s2[right] - 'a']++;

        windowFreq[s2[left] - 'a']--;

        left++;

        if (windowFreq == targetFreq)
            return true;
    }

    return false;
}
```

## 3. Dry Run

```text
s1 = "ab"
s2 = "eidbaooo"
```

Target frequencies:

```text
a = 1
b = 1
```

Window size = 2.

| Window | Result |
|---|---|
| ei | No |
| id | No |
| db | No |
| ba | Yes |

Return `true`.

## 4. Complexity

Let:
- N = length of `s2`
- M = length of `s1`

Time:
- Build target frequency: `O(M)`
- Build first window: `O(M)`
- Slide through `s2`: `O(N-M)`
- Each frequency comparison checks 26 positions: `O(26) = O(1)`.

Overall: `O(N + M)` time.

Space: `O(26) = O(1)`.

## 5. Memory Trick

When you see:

**Find a permutation of one string inside another string**

Think:

```text
Permutation
    ↓
Same character frequencies
    ↓
Fixed window size = s1.size()
    ↓
Frequency array of 26
    ↓
Slide one character at a time
    ↓
Compare frequencies
```

Important: Add the new right character, remove the old left character, then increment `left`.

Assumption: Input contains lowercase English letters.