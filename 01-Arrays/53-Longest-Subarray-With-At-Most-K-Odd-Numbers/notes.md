# Longest Subarray With At Most K Ones

## Problem

Given a binary array containing only `0` and `1`, find the length of the longest contiguous subarray containing **at most `k` ones**.

Example:

```text
a = [1, 1, 0, 1, 0, 0, 1, 1, 1]
k = 2
```

Answer:

```text
5
```

One valid window is:

```text
[1, 0, 1, 0, 0]
```

which contains exactly 2 ones.

---

# 1. Main Idea

This is a **sliding-window** problem.

Maintain:

```text
[left ........ right]
```

The window is valid when:

```text
number of 1s <= k
```

The window becomes invalid when:

```text
number of 1s > k
```

So:

```text
Expand right
     ↓
Add 1 if necessary
     ↓
onesCount > k ?
     ↓
    YES
     ↓
Shrink from left
     ↓
onesCount becomes <= k
     ↓
Update maximum length
```

---

# 2. Do We Need A Map?

No.

Because the array is binary:

```text
0 or 1
```

We only care about:

```text
How many 1s are currently inside the window?
```

So we can simply maintain:

```cpp
int onesCount = 0;
```

This is better than maintaining:

```cpp
unordered_map<int, int>
```

because the map would store information we don't actually need.

---

# 3. Expand The Window

For every `right`:

```cpp
for (int right = 0; right < a.size(); right++)
```

If the new element is `1`:

```cpp
if (a[right] == 1)
    onesCount++;
```

We don't care about zeros.

---

# 4. Detect Invalid Window

The window is invalid when:

```cpp
onesCount > k
```

Therefore:

```cpp
while (onesCount > k)
```

we need to shrink from the left.

---

# 5. Shrinking The Window

Look at the element leaving the window:

```cpp
if (a[left] == 1)
    onesCount--;
```

Then move `left`:

```cpp
left++;
```

Why only decrease `onesCount` when `a[left] == 1`?

Because zeros don't contribute to our constraint.

---

# 6. Update Maximum

Once:

```text
onesCount <= k
```

the window is valid.

Its length is:

```cpp
right - left + 1
```

So:

```cpp
maxlength = max(maxlength, right - left + 1);
```

---

# 7. Complete Optimized Code

```cpp
int lengthLongestSubArrAtmostOnes(vector<int>& a, int k) {

    int left = 0;
    int maxlength = 0;
    int onesCount = 0;

    for (int right = 0; right < a.size(); right++) {

        // Add right element to the window
        if (a[right] == 1) {
            onesCount++;
        }

        // Shrink while window has too many ones
        while (onesCount > k) {

            if (a[left] == 1) {
                onesCount--;
            }

            left++;
        }

        // Current window is valid
        maxlength = max(maxlength, right - left + 1);
    }

    return maxlength;
}
```

---

# 8. Dry Run

```text
a = [1, 1, 0, 1, 0, 0, 1, 1, 1]
k = 2
```

Initially:

```text
left = 0
onesCount = 0
maxlength = 0
```

### right = 0

Element:

```text
1
```

So:

```text
onesCount = 1
```

Window:

```text
[1]
```

Length:

```text
1
```

---

### right = 1

Element:

```text
1
```

Now:

```text
onesCount = 2
```

Window:

```text
[1, 1]
```

Still valid because:

```text
2 <= k
```

Length:

```text
2
```

---

### right = 2

Element:

```text
0
```

`onesCount` remains:

```text
2
```

Window:

```text
[1, 1, 0]
```

Length:

```text
3
```

---

### right = 3

Element:

```text
1
```

Now:

```text
onesCount = 3
```

Invalid:

```text
3 > 2
```

So shrink.

Remove `a[left]`:

```text
a[0] = 1
```

Therefore:

```text
onesCount = 2
left = 1
```

Current window:

```text
[1, 0, 1]
```

Length:

```text
3
```

---

### Continue...

Eventually we get:

```text
[1, 0, 1, 0, 0]
```

with:

```text
onesCount = 2
```

Length:

```text
5
```

So:

```text
maxlength = 5
```

---

# 9. Why Your Map Version Was Unnecessary

You wrote:

```cpp
unordered_map<int, int> window;
```

and tracked:

```text
0 → frequency
1 → frequency
```

That works conceptually, but the only information we actually need is:

```text
number of 1s
```

So:

```cpp
int onesCount = 0;
```

is enough.

This is an important optimization lesson:

> Don't maintain a data structure just because you can. Maintain exactly the information needed to determine whether the window is valid.

---

# 10. Bug In Your Map Version

You had:

```cpp
if(window[leftElement] == 0){
    window.erase(window[leftElement]);
}
```

Here:

```cpp
window[leftElement]
```

returns the **frequency**.

For example:

```text
leftElement = 1
window[1] = 0
```

So you effectively do:

```cpp
window.erase(0);
```

But the key you wanted to erase was:

```cpp
window.erase(1);
```

Correct version:

```cpp
if (window[leftElement] == 0) {
    window.erase(leftElement);
}
```

Again, however, the map isn't necessary for this particular problem.

---

# 11. Complexity

Each element enters the window once and leaves the window at most once.

Therefore:

```text
Time: O(N)
```

We only maintain a few integer variables:

```text
Space: O(1)
```

This is better than the map version's additional storage.

---

# 12. General Pattern

This problem follows:

```text
LONGEST VALID WINDOW
```

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
onesCount <= k

Invalid:
onesCount > k
```

---

# Key Takeaway

You've now seen several versions of the same sliding-window idea:

### Longest substring without repeating characters

```text
Invalid → duplicate exists
```

### Fruit Into Baskets

```text
Invalid → distinct values > k
```

### At Most K Ones

```text
Invalid → number of ones > k
```

The important skill is no longer memorizing the code.

The skill is:

> **Identify the window condition and maintain only the information needed to check it.**
