# Two Sum

## Problem

Given an array and a target, find two different
elements whose sum equals the target.

Return their indices.

---

# Approach 1 — Brute Force

Check every possible pair.

For every i:

    for every j > i:

        if nums[i] + nums[j] == target
            return {i, j}

### Complexity

Time: O(n²)

Space: O(1) auxiliary space

---

# Approach 2 — Hash Map

For every element:

    needed = target - nums[i]

Check whether `needed` already exists in the map.

Map stores:

    number → index

If found:

    return {map[needed], i}

Otherwise:

    map[nums[i]] = i

### Why check before inserting?

Prevents using the same element twice.

Example:

    nums = [3,3]
    target = 6

First 3 is stored.

Second 3 finds the first 3.

---

## Complexity

Average Time: O(n)

Space: O(n)

---

## Important Pattern

When looking for a pair satisfying:

    a + b = target

Think:

    b = target - a

Then use a Hash Map to remember
previously seen values.

---

## Interview Trade-off

Brute Force:

    O(n²) time
    O(1) space

Hash Map:

    O(n) average time
    O(n) space

We use extra memory to reduce time.

---

## Edge Cases

1. Duplicate values

   [3,3], target = 6

2. Negative numbers

   [-3,4,3,90], target = 0

3. No solution

4. Negative target

5. Single element

   No pair possible.