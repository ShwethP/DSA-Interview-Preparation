# Minimum Window Substring

## Problem

Given two strings `s` and `t`, find the **smallest substring of `s` that contains all characters of `t`**, including duplicates.

Example:

```text
s = "ADOBECODEBANC"
t = "ABC"

Answer = "BANC"
```

---

# 1. Main Idea

We use **Sliding Window + Frequency Maps**.

We maintain:

```text
[left ........ right]
```

`right` expands the window.

Once the window contains everything required by `t`, we shrink from the left to find the smallest valid window.

The overall pattern is:

```text
Expand right
     ↓
Is window valid?
     ↓
   YES
     ↓
Save answer
     ↓
Shrink left
     ↓
Still valid?
  ↓       ↓
 YES      NO
  ↓        ↓
shrink   stop
           ↓
       expand right
```

---

# 2. What Do We Store?

We use two frequency maps.

### `required`

Stores what `t` needs.

For:

```text
t = "ABC"
```

we have:

```text
A → 1
B → 1
C → 1
```

For:

```text
t = "AABC"
```

we have:

```text
A → 2
B → 1
C → 1
```

This is important because characters can repeat.

---

### `window`

Stores what the current sliding window contains.

For:

```text
window = "ADOBEC"
```

we have:

```text
A → 1
B → 1
C → 1
```

---

# 3. `formed`

We maintain:

```cpp
int formed = 0;
```

`formed` means:

> How many distinct required characters currently have their required frequency satisfied?

Example:

```text
t = "AABC"
```

Requirements:

```text
A → 2
B → 1
C → 1
```

There are 3 distinct required characters:

```text
A, B, C
```

Suppose current window has:

```text
A → 2
B → 1
C → 0
```

Then:

```text
formed = 2
```

because A and B are satisfied.

When:

```text
A → 2
B → 1
C → 1
```

we have:

```text
formed = 3
```

Now the window is valid.

---

# 4. When Is The Window Valid?

The number of distinct required characters is:

```cpp
required.size()
```

Therefore:

```cpp
formed == required.size()
```

means:

> Every character required by `t` has been satisfied.

So:

```cpp
while (formed == required.size())
```

means:

> The current window is valid, so try shrinking it.

---

# 5. Expanding the Window

Move `right` through `s`:

```cpp
for (int right = 0; right < s.size(); right++)
```

Take the current character:

```cpp
char c = s[right];
```

Add it to the window:

```cpp
window[c]++;
```

If it is a required character and its required frequency has just been reached:

```cpp
if (required.find(c) != required.end() &&
    window[c] == required[c]) {

    formed++;
}
```

### Why `==`?

Suppose:

```text
required[A] = 2
```

When the window has:

```text
A → 1
```

A is not satisfied.

When it becomes:

```text
A → 2
```

A is satisfied:

```text
formed++;
```

If it becomes:

```text
A → 3
```

we do NOT increase `formed` again.

A was already satisfied.

---

# 6. When The Window Becomes Valid

Suppose:

```text
s = "ADOBEC"
t = "ABC"
```

Current window:

```text
ADOBEC
```

Frequencies:

```text
A → 1
B → 1
C → 1
```

Therefore:

```text
formed = 3
required.size() = 3
```

The window is valid.

Now we want the **smallest** valid window.

So we start moving `left`.

---

# 7. Shrinking the Window

First save the current window if it is the smallest:

```cpp
if (right - left + 1 < minLength) {

    minLength = right - left + 1;
    minStart = left;
}
```

Then remove the character at `left`:

```cpp
char leftChar = s[left];

window[leftChar]--;

left++;
```

Important:

```cpp
window[s[left]]--;
```

because the character leaving the window is at `left`.

---

# 8. When Does `formed` Decrease?

Suppose:

```text
required[A] = 1
```

and the current window has:

```text
A → 1
```

Now we remove A.

The window becomes:

```text
A → 0
```

A is no longer satisfied.

Therefore:

```cpp
formed--;
```

Code:

```cpp
if (required.find(leftChar) != required.end() &&
    window[leftChar] < required[leftChar]) {

    formed--;
}
```

Now the window is invalid, so we stop shrinking.

---

# 9. Complete Code

```cpp
string minWindow(string s, string t) {

    unordered_map<char, int> required;
    unordered_map<char, int> window;

    // Build required frequency map
    for (char c : t) {
        required[c]++;
    }

    int left = 0;

    // Number of satisfied distinct characters
    int formed = 0;

    // Best window information
    int minLength = INT_MAX;
    int minStart = 0;

    for (int right = 0; right < s.size(); right++) {

        char c = s[right];

        // Add character to current window
        window[c]++;

        // Check whether this requirement is now satisfied
        if (required.find(c) != required.end() &&
            window[c] == required[c]) {

            formed++;
        }

        // Current window contains everything required
        while (formed == required.size()) {

            // Update smallest window
            if (right - left + 1 < minLength) {

                minLength = right - left + 1;
                minStart = left;
            }

            // Remove leftmost character
            char leftChar = s[left];

            window[leftChar]--;

            // Did removing it break a requirement?
            if (required.find(leftChar) != required.end() &&
                window[leftChar] < required[leftChar]) {

                formed--;
            }

            left++;
        }
    }

    // No valid window found
    if (minLength == INT_MAX) {
        return "";
    }

    return s.substr(minStart, minLength);
}
```

---

# 10. Dry Run

```text
s = "ADOBECODEBANC"
t = "ABC"
```

Initially:

```text
required:
A → 1
B → 1
C → 1

formed = 0
```

Expand `right`.

### Window = `"A"`

```text
A → 1
formed = 1
```

Not valid.

---

### Window = `"ADOB"`

B is now satisfied:

```text
formed = 2
```

Still missing C.

---

### Window = `"ADOBEC"`

C is satisfied:

```text
formed = 3
```

Now:

```text
formed == required.size()
```

Valid.

Record:

```text
"ADOBEC"
length = 6
```

Shrink.

Remove A:

```text
"DOBEC"
```

A is missing:

```text
formed = 2
```

Invalid.

Stop shrinking.

---

Continue expanding `right`.

Eventually:

```text
"ADOBECODEBANC"
```

becomes valid again.

Shrink repeatedly.

Eventually:

```text
"BANC"
```

is valid:

```text
B → 1
A → 1
C → 1
```

Length:

```text
4
```

Try removing B:

```text
"ANC"
```

B becomes missing.

So the window becomes invalid.

Therefore:

```text
"BANC"
```

is the smallest valid window found.

---

# 11. Why This Is O(N)

Although we have a `for` loop and a `while` loop, it is still:

```text
O(N)
```

because:

* `right` moves from left → right once.
* `left` also moves from left → right once.
* Neither pointer moves backward.

Therefore total pointer movements are approximately:

```text
N + N = 2N
```

which is:

```text
O(N)
```

Hashmap operations are average `O(1)`.

Space:

```text
O(K)
```

where `K` is the number of distinct characters being tracked.

---

# 12. Important Sliding Window Pattern

There are two different goals we've now seen.

## Longest Valid Window

Example:

**Longest Repeating Character Replacement**

When valid:

```text
update answer
expand right
```

When invalid:

```text
shrink left
```

Pattern:

```text
expand → invalid → shrink
```

---

## Smallest Valid Window

Example:

**Minimum Window Substring**

When invalid:

```text
expand right
```

When valid:

```text
update answer
shrink left
```

Pattern:

```text
expand → valid → shrink as much as possible
```

This distinction is extremely important.

---

# 13. Interview Memory Trick

For **LONGEST**:

```text
Make window valid
→ keep it
→ maximize length
```

For **SMALLEST**:

```text
Make window valid
→ shrink it
→ minimize length
```

### Core idea for Minimum Window Substring

```text
RIGHT = find a valid window

LEFT = make that valid window as small as possible
```

---

# Complexity

```text
Time:  O(N)
Space: O(K)
```

For ASCII characters, `K` is effectively bounded by the character set.
