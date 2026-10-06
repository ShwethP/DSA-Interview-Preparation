# Longest Repeating Character Replacement

## Problem

Given a string `s` and an integer `k`, find the length of the longest substring that can be converted into a substring containing only the same character by replacing at most `k` characters.

### Example

```text
s = "AABABBA"
k = 1

Answer = 4
```

One valid window:

```text
"AABA"
```

Replace `B` with `A`:

```text
"AAAA"
```

---

# 1. Brute Force Idea

Consider every possible substring.

For each substring:

1. Count the frequency of every character.
2. Find the most frequent character.
3. All other characters need to be replaced.
4. If the number of replacements is `<= k`, the window is valid.

The important formula is:

```text
replacements needed
=
window length - highest character frequency
```

Therefore:

```text
window length - maxFrequency <= k
```

means the window is valid.

---

# 2. Sliding Window

Instead of generating every substring, maintain a window:

```text
[left ........ right]
```

`right` expands the window.

`left` moves forward whenever the window becomes invalid.

We maintain:

```cpp
vector<int> freq(26, 0);
```

because the string contains uppercase English letters.

---

# 3. Frequency

When `right` enters the window:

```cpp
freq[s[right] - 'A']++;
```

Then update the highest frequency:

```cpp
maxFreq = max(maxFreq, freq[s[right] - 'A']);
```

`maxFreq` tells us the frequency of the character we would keep.

All other characters would be replaced.

---

# 4. Checking the Window

Suppose:

```text
window = "AABAB"
```

Frequencies:

```text
A → 3
B → 2
```

Therefore:

```text
window length = 5
maxFreq = 3
```

Characters that need replacement:

```text
5 - 3 = 2
```

If:

```text
k = 2
```

the window is valid.

If:

```text
k = 1
```

the window is invalid.

The condition is:

```cpp
while ((right - left + 1) - maxFreq > k)
```

---

# 5. Shrinking the Window

If the window is invalid, remove the character at `left`:

```cpp
freq[s[left] - 'A']--;
left++;
```

Important:

```cpp
freq[s[left] - 'A']--;
```

NOT:

```cpp
freq[s[right] - 'A']--;
```

because `left` is the character leaving the window.

---

# 6. Optimal Code

```cpp
int longestRepeatingCharacterReplacement(string s, int k) {

    vector<int> freq(26, 0);

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++) {

        freq[s[right] - 'A']++;

        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        while ((right - left + 1) - maxFreq > k) {

            freq[s[left] - 'A']--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
```

---

# 7. Dry Run

```text
s = "AABABBA"
k = 1
```

Consider:

```text
"AABA"
```

Frequency:

```text
A = 3
B = 1
```

Window length:

```text
4
```

Replacements:

```text
4 - 3 = 1
```

Since:

```text
1 <= k
```

the window is valid.

Length:

```text
4
```

Now consider:

```text
"AABAB"
```

Frequency:

```text
A = 3
B = 2
```

Replacements:

```text
5 - 3 = 2
```

But:

```text
k = 1
```

so:

```text
2 > 1
```

The window is invalid.

Shrink from the left until it becomes valid again.

---

# 8. Why Sliding Window Works

We don't need to test every possible substring.

We maintain the largest valid window while moving through the string:

```text
right → expand

if invalid:
    left → shrink

if valid:
    update maximum length
```

This reduces the problem from checking many substrings to a single pass.

---

# 9. Complexity

```text
Time:  O(N)
Space: O(1)
```

Why `O(1)` space?

Because the frequency array always contains only 26 entries.

---

# Memory Trick

For this problem, remember:

```text
WINDOW
    ↓
window length - max frequency
    ↓
number of replacements needed
    ↓
must be <= k
```

So:

```text
If valid:
    expand / record answer

If invalid:
    shrink from left
```

### Core condition

```cpp
(right - left + 1) - maxFreq > k
```

### Pattern

**Sliding Window + Frequency Array**
