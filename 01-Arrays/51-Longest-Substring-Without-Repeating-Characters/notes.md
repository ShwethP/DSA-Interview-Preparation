# Longest Substring Without Repeating Characters

## Problem

Given a string `s`, find the longest substring that contains **no repeated characters**.

Example:

```text
s = "abcabcbb"
```

Longest substring:

```text
"abc"
```

Answer:

```text
3
```

---

# 1. Brute Force Approach

Generate every possible substring and check whether it contains duplicate characters.

For every starting index `i`:

1. Start a new set.
2. Expand `j`.
3. If `s[j]` is already present, the substring is invalid.
4. Otherwise insert it and update the maximum length.

Typical complexity:

```text
Time: O(N²)
Space: O(K)
```

where `K` is the number of distinct characters.

---

# 2. Sliding Window Idea

Maintain:

```text
[left ........ right]
```

The window must always contain **unique characters**.

`right` expands the window.

If a duplicate appears, move `left` forward until the duplicate is removed.

Pattern:

```text
expand right
     ↓
duplicate?
  ↓       ↓
 NO      YES
  ↓        ↓
continue  shrink left
            ↓
       duplicate gone
            ↓
        update answer
```

---

# 3. Frequency Map

Use:

```cpp
unordered_map<char, int> window;
```

It stores the frequency of every character currently inside the window.

Example:

```text
window = "abc"
```

Map:

```text
a → 1
b → 1
c → 1
```

Now if another `b` enters:

```text
window = "abcb"
```

we get:

```text
b → 2
```

Therefore there is a duplicate.

---

# 4. Detecting a Duplicate

After adding:

```cpp
window[s[right]]++;
```

check:

```cpp
while (window[s[right]] > 1)
```

Why specifically `s[right]`?

Because the character that just entered the window is the one that caused the duplicate.

---

# 5. Removing From the Left

When the window is invalid:

```cpp
window[s[left]]--;
left++;
```

We remove the character currently at the left edge and move `left`.

Example:

```text
[a b c b]
  ↑
 left
```

The duplicate is `b`.

Move left:

```text
[b c b]
```

Still duplicate.

Move left again:

```text
[c b]
```

Now the window is valid.

---

# 6. Updating the Maximum

Once the window is valid:

```cpp
int currentLength = right - left + 1;
```

If this is larger than our previous answer:

```cpp
if (currentLength > maxLength) {
    maxLength = currentLength;
    start = left;
}
```

We store:

```text
maxLength → length of best substring
start     → starting index of best substring
```

This is important when the question asks for the **actual substring**, not just its length.

---

# 7. Returning The Actual Substring

If we only need the length:

```cpp
return maxLength;
```

If we need the actual substring:

```cpp
return s.substr(start, maxLength);
```

`substr(start, length)` means:

> Start at index `start` and take `length` characters.

---

# 8. Complete Code — Return Substring

```cpp
string longestUniqueSubstring(string s) {

    unordered_map<char, int> window;

    int left = 0;
    int maxLength = 0;
    int start = 0;

    for (int right = 0; right < s.size(); right++) {

        window[s[right]]++;

        while (window[s[right]] > 1) {

            window[s[left]]--;
            left++;
        }

        int currentLength = right - left + 1;

        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = left;
        }
    }

    return s.substr(start, maxLength);
}
```

---

# 9. Dry Run

```text
s = "abcabcbb"
```

### `right = 0`

```text
window = "a"
```

Length:

```text
1
```

Maximum:

```text
"a"
```

---

### `right = 1`

```text
window = "ab"
```

Length:

```text
2
```

Maximum:

```text
"ab"
```

---

### `right = 2`

```text
window = "abc"
```

Length:

```text
3
```

Maximum:

```text
"abc"
```

---

### `right = 3`

Add `a`:

```text
"abca"
```

Now:

```text
a → 2
```

Duplicate detected.

Shrink from left:

```text
"bca"
```

Now valid again.

Length:

```text
3
```

It isn't larger than our existing maximum, so we keep:

```text
start = 0
maxLength = 3
```

---

# 10. Important Bug To Avoid

Do NOT do this:

```cpp
start = left;
maxLength = max(maxLength, currentLength);
```

because `start` would change even when the current window isn't the best window.

Instead:

```cpp
if (currentLength > maxLength) {
    maxLength = currentLength;
    start = left;
}
```

Update `start` **only when the maximum changes**.

---

# 11. Complexity

Each character enters the window once and leaves the window at most once.

Therefore:

```text
Time: O(N)
```

The map stores characters in the current window:

```text
Space: O(K)
```

For a fixed character set such as ASCII, this is effectively:

```text
O(1)
```

---

# 12. Sliding Window Pattern Learned

This problem teaches another important variation:

### Longest valid window

```text
Expand right
    ↓
If invalid → shrink left
    ↓
When valid → maximize answer
```

For this problem:

```text
Invalid = duplicate character exists
```

So the key invariant is:

> **The current window always contains unique characters.**

---

# Important Takeaway

For substring problems, always ask:

1. What makes my window **valid**?
2. What makes my window **invalid**?
3. What information do I need to maintain that condition?
4. When invalid, how do I shrink?
5. Am I looking for the **longest** or **smallest** valid window?
6. Do I need the **length** or the **actual substring**?

These questions will help you recognize sliding-window problems much faster.
