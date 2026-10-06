# Subarray XOR Equals K

## Problem

Given an array and an integer `k`, count the number of subarrays whose XOR is equal to `k`.

Example:

```text
a = [4, 2, 2, 6, 4]
k = 6

Answer = 4
```

## Brute Force

Generate every possible subarray and maintain its XOR.

```cpp
int countSubarraysXorK(vector<int>& a, int k) {
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        int currentXor = 0;

        for (int j = i; j < a.size(); j++) {
            currentXor ^= a[j];

            if (currentXor == k) {
                count++;
            }
        }
    }

    return count;
}
```

### Complexity

```text
Time:  O(N²)
Space: O(1)
```

## Optimal — Prefix XOR + Hashmap

Key relationship:

```text
currentXor ^ previousXor = k
```

Therefore:

```text
previousXor = currentXor ^ k
```

So for every current prefix XOR, look for:

```cpp
needed = currentXor ^ k;
```

Store:

```text
prefixXOR → frequency
```

### Code

```cpp
int countSubarraysXorK(vector<int>& a, int k) {
    unordered_map<int, int> freq;
    freq[0] = 1;

    int currentXor = 0;
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        currentXor ^= a[i];

        int needed = currentXor ^ k;

        if (freq.find(needed) != freq.end()) {
            count += freq[needed];
        }

        freq[currentXor]++;
    }

    return count;
}
```

### Why `freq[0] = 1`?

It represents the empty prefix before the array starts.

This allows subarrays beginning at index `0` to be counted.

### Why frequency instead of just an index?

Because the same prefix XOR can occur multiple times, and every occurrence can form a different valid subarray.

### Complexity

```text
Time:  O(N) average
Space: O(N)
```

## Memory Trick

For Sum:

```text
previousSum = currentSum - k
```

For XOR:

```text
previousXor = currentXor ^ k
```

Both use the same prefix-hashmap pattern.

**Sum:** subtraction finds the required previous prefix.

**XOR:** XOR with `k` finds the required previous prefix.
