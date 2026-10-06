# Fruit Into Baskets — Sliding Window

## Problem

Given an array of fruit types and `k` baskets, find the longest contiguous subarray containing **at most `k` distinct fruit types**.

For the standard problem:

```text
k = 2
```

Example:

```text
fruits = [1, 2, 1, 2, 3, 4, 5]
```

Longest valid window:

```text
[1, 2, 1, 2]
```

Answer:

```text
4
```

---

# 1. Key Observation

This is the same pattern as:

**Longest Substring With At Most K Distinct Characters**

The only difference is that we're working with integers instead of characters.

The window must satisfy:

```text
number of distinct fruit types <= k
```

---

# 2. Data Structure

We use:

```cpp
unordered_map<int, int> window;
```

The map stores:

```text
fruit type → frequency inside current window
```

Example:

```text
window = [1, 2, 1, 2]
```

Map:

```text
1 → 2
2 → 2
```

Therefore:

```cpp
window.size() == 2
```

There are 2 distinct fruit types.

---

# 3. Sliding Window

Maintain:

```text
[left ........ right]
```

`right` expands the window.

When:

```cpp
window.size() > k
```

the window is invalid.

So we shrink from the left.

Pattern:

```text
expand right
     ↓
distinct types > k?
     ↓
    YES
     ↓
shrink left
     ↓
erase zero-frequency types
     ↓
window becomes valid
     ↓
update maximum
```

---

# 4. Adding a Fruit

```cpp
window[fruits[right]]++;
```

This adds the fruit entering the window.

---

# 5. Checking Validity

```cpp
while (window.size() > k)
```

`window.size()` represents the number of **distinct fruit types**, not the total number of fruits.

Example:

```text
[1, 1, 1, 2, 2]
```

Map:

```text
1 → 3
2 → 2
```

So:

```text
window.size() = 2
```

Even though there are 5 fruits.

---

# 6. Removing From The Left

When the window has too many distinct types:

```cpp
window[fruits[left]]--;
```

Then check whether that fruit completely disappeared:

```cpp
if (window[fruits[left]] == 0) {
    window.erase(fruits[left]);
}
```

Then:

```cpp
left++;
```

### Why erase?

Suppose:

```text
window:
1 → 3
2 → 2
3 → 1
```

We remove the only `3`.

After decrement:

```text
3 → 0
```

If we don't erase it:

```text
window.size() = 3
```

even though fruit type `3` is no longer in the window.

Therefore:

```cpp
window.erase(fruits[left]);
```

is essential.

---

# 7. Updating The Answer

Once the window is valid:

```cpp
maxLength = max(maxLength, right - left + 1);
```

The current window is:

```text
[left ... right]
```

Therefore its length is:

```text
right - left + 1
```

---

# 8. Complete Code

```cpp
int totalFruit(vector<int>& fruits, int k) {

    int left = 0;
    int maxLength = 0;

    unordered_map<int, int> window;

    for (int right = 0; right < fruits.size(); right++) {

        window[fruits[right]]++;

        while (window.size() > k) {

            window[fruits[left]]--;

            if (window[fruits[left]] == 0) {
                window.erase(fruits[left]);
            }

            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
```

---

# 9. Complexity

Each element is:

* Added once by `right`
* Removed at most once by `left`

Therefore:

```text
Time: O(N)
```

The map stores at most `K` distinct values:

```text
Space: O(K)
```

---

# 10. Pattern To Remember

This is a **Longest Valid Sliding Window** problem.

General structure:

```cpp
for (right...) {

    // Add right element

    while (window is invalid) {

        // Remove left element
        // Move left
    }

    // Update maximum
}
```

Here:

```text
Valid:
distinct values <= k

Invalid:
distinct values > k
```

This same pattern applies to many problems involving:

* At most K distinct characters
* At most K distinct numbers
* Fruits into baskets
* Longest substring with constraints
* Longest subarray with constraints

The important thing is to identify **what makes the window invalid**.
