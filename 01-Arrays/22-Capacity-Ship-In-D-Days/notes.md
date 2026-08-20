# Capacity to Ship Packages Within D Days

## Pattern

Binary Search on Answer
+
Greedy feasibility check

---

## Problem

Given packages with weights.

Packages must be shipped in their original order.

Find the minimum ship capacity that allows all packages
to be shipped within D days.

---

## Search Space

Minimum capacity:

max(weights)

Why?

The ship must be able to carry the heaviest individual package.

Maximum capacity:

sum(weights)

Why?

With this capacity, all packages can be shipped in one day.

Therefore:

left = max(weights)
right = sum(weights)

---

## Feasibility Check

For a candidate capacity:

Scan packages from left to right.

Maintain:

currentLoad
daysNeeded

If:

currentLoad + weight <= capacity

add package to current day.

Otherwise:

start a new day.

daysNeeded++
currentLoad = weight

At the end:

daysNeeded <= allowedDays

means the capacity works.

---

## Binary Search

If candidate capacity works:

    try smaller capacity

    right = mid - 1

If candidate capacity doesn't work:

    capacity is too small

    left = mid + 1

Final answer:

left

---

## Monotonic Property

Capacity:

small → large

❌ ❌ ❌ ❌ ❌ ✅ ✅ ✅

❌ = requires more than D days

✅ = can ship within D days

We need the first valid capacity.

---

## Complexity

Let:

n = number of packages

S = sum of all weights

Each feasibility check:

O(n)

Binary Search:

O(log S)

Total:

O(n log S)

Space:

O(1)

---

## Important Observations

1. Packages cannot be reordered.

2. A package that doesn't fit on the current day
   must start the next day.

3. The current package is NOT discarded:

   currentLoad = weight

4. The answer is not necessarily one of the package weights.

5. Binary Search works because feasibility is monotonic.