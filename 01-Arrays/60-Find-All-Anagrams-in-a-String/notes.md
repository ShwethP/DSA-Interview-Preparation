# Q60 — Find All Anagrams in a String

**Pattern:** Fixed-Size Sliding Window + Frequency Counting

## 1. Problem

Given two strings `s` and `p`, return all starting indices in `s` where an anagram of `p` appears.

An anagram has exactly the same characters and frequencies, but possibly a different order.

Example:

```cpp
s = "cbaebabacd";
p = "abc";

// Output: [0, 6]
```

## 2. Brute Force Approach

- Generate every substring of length `p.size()`.
- Sort each substring and sort `p`.
- Compare the sorted strings.
- If equal, store the starting index.

**Time:** O((N-M+1) × M log M)  
**Space:** O(M) for temporary strings.

This repeats sorting for every window.

## 3. Optimal Approach — Fixed-Size Sliding Window

### Intuition

An anagram has the same character frequencies, regardless of character order.

Instead of sorting every substring, maintain two frequency arrays:

- `targetFreq`: character frequencies in `p`.
- `windowFreq`: character frequencies in the current window of `s`.

Since every valid window has exactly `p.size()` characters, we use a fixed-size sliding window.

### Steps

1. Count the frequencies of characters in `p`.
2. Build the first window of size `p.size()` in `s`.
3. Compare the two frequency arrays.
4. If they match, store the window's starting index.
5. Slide the window:
   - Add the incoming character.
   - Remove the outgoing character.
   - Move `left` forward.
6. Compare frequencies again.
7. Return all matching starting indices.

### Complete C++ Code

```cpp
vector<int> findAnagrams(string s, string p)
{
    vector<int> result;

    int windowSize = p.size();

    if (windowSize > s.size())
        return result;

    vector<int> targetFreq(26, 0);
    vector<int> windowFreq(26, 0);

    // Count characters in p.
    for (char c : p)
        targetFreq[c - 'a']++;

    int left = 0;

    // Build first window.
    for (int i = 0; i < windowSize; i++)
        windowFreq[s[i] - 'a']++;

    // Check first window.
    if (windowFreq == targetFreq)
        result.push_back(0);

    // Slide the window.
    for (int right = windowSize; right < s.size(); right++)
    {
        // Add incoming character.
        windowFreq[s[right] - 'a']++;

        // Remove outgoing character.
        windowFreq[s[left] - 'a']--;

        left++;

        // Check current window.
        if (windowFreq == targetFreq)
            result.push_back(left);
    }

    return result;
}
```

## 4. Dry Run

```cpp
s = "cbaebabacd";
p = "abc";
```

Window size = 3.

| Window | Anagram? | Starting index |
|---|---|---:|
| cba | Yes | 0 |
| bae | No | — |
| aeb | No | — |
| eba | No | — |
| bab | No | — |
| aba | No | — |
| bac | Yes | 6 |
| acd | No | — |

Result: `[0, 6]`

## 5. Complexity

Let N = length of `s`, M = length of `p`.

- **Time:** O(N + M). Each character is added and removed at most once. Comparing two arrays of 26 entries takes constant time.
- **Auxiliary space:** O(1), because both frequency arrays have a fixed size of 26. Output space is excluded.
- Assumption: lowercase English letters (`a`–`z`).

## 6. Remember This

**Fixed-size sliding window + frequency arrays**

- Permutation in String: return `true` if any matching window exists.
- Find All Anagrams: collect every matching window's starting index.

The underlying logic is almost identical. The main difference is what you do when the frequency arrays match.