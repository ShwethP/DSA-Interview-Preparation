# Minimum Days to Make M Bouquets

## Problem

Given:

bloomDay[i] = day on which flower i blooms

We need:

m = number of bouquets
k = flowers required per bouquet

Flowers used in a bouquet must be ADJACENT.

Find the minimum day on which we can make m bouquets.

If impossible, return -1.

---

## Important Observation

For a fixed day, each flower is either:

bloomDay[i] <= day → bloomed
bloomDay[i] > day  → not bloomed

We scan the array and count consecutive bloomed flowers.

When consecutive == k:

    create one bouquet
    bouquets++
    consecutive = 0

If we encounter an unbloomed flower:

    consecutive = 0

because adjacency has been broken.

---

## Feasibility Function

canMakeBouquets(day)

returns:

true  → can make at least m bouquets
false → cannot make m bouquets

---

## Binary Search on Answer

Possible answers are days between:

min(bloomDay)
and
max(bloomDay)

Example:

1 2 3 4 5 ... 10

The result has a monotonic property:

❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌ ✅
                               ↑
                         first valid day

If a certain day works, every later day also works.

Therefore Binary Search can find the first valid day.

---

## Binary Search

if canMakeBouquets(mid):

    mid works
    try an earlier day

    right = mid - 1

else:

    mid doesn't work
    need more days

    left = mid + 1

At the end:

return left

---

## Important Edge Case

Each bouquet requires k flowers.

We need:

m * k

flowers total.

If:

m * k > n

where n = number of flowers,

it is impossible.

Return:

-1

Use long long for the multiplication:

(long long)m * k

to avoid integer overflow.

---

## Complexity

Let:

n = number of flowers

D = range of possible days

Feasibility check:

O(n)

Binary Search:

O(log D)

Total:

O(n log D)

Space:

O(1)

---

## Pattern

This is:

Binary Search on Answer
+
Greedy/Linear Feasibility Check

Flow:

Binary Search
     ↓
candidate day
     ↓
scan flowers
     ↓
count consecutive flowers
     ↓
count bouquets
     ↓
true / false
     ↓
move left or right