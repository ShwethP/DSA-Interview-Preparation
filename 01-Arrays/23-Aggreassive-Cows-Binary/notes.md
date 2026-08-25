# Aggressive Cows

## Pattern

Binary Search on Answer
+
Greedy Feasibility Check

---

## Problem

Given sorted stall positions and k cows,
place the cows such that the minimum distance
between any two cows is as large as possible.

Return the maximum possible minimum distance.

Example:

stalls = [1,2,4,8,9]
k = 3

Answer = 3

One valid placement:

1, 4, 8

Distances:

4 - 1 = 3
8 - 4 = 4

Minimum distance = 3

---

## Important Idea

We don't binary search the stalls.

We binary search the ANSWER:

minimum possible distance → maximum possible distance

For a candidate distance D, ask:

"Can I place k cows such that every two
consecutive cows are at least D apart?"

---

## Greedy Feasibility Check

Place the first cow at the first stall.

Then scan from left to right.

If:

stall[i] - lastPosition >= distance

place another cow.

Update:

lastPosition = stall[i]

Continue until:

count >= k

If we can place k cows:

return true

Otherwise:

return false

---

## Why Greedy Works

Always choose the earliest possible stall.

This leaves the maximum amount of space
for the remaining cows.

---

## Binary Search

We want the MAXIMUM valid distance.

If distance works:

    try a larger distance

    left = mid + 1

If distance doesn't work:

    try a smaller distance

    right = mid - 1

At the end:

return right

---

## Monotonic Property

distance:

1 2 3 4 5 6 ...

    ✅ ✅ ✅ ❌ ❌ ❌
          ↑
    maximum valid answer

If distance D is impossible,
every larger distance is also impossible.

If distance D is possible,
every smaller distance is also possible.

---

## Search Space

left = 0

right = max(stalls) - min(stalls)

---

## Complexity

Let:

n = number of stalls

D = max(stall) - min(stall)

Each feasibility check:

O(n)

Binary Search:

O(log D)

Total:

O(n log D)

Space:

O(1)

---

## Important Pattern

Minimum answer problems:

❌ ❌ ❌ ✅ ✅ ✅

usually return:

left

Maximum answer problems:

✅ ✅ ✅ ❌ ❌ ❌

usually return:

right