# Koko Eating Bananas — Binary Search on Answer

## Problem

Given piles of bananas and h hours, find the minimum eating speed k
such that all bananas can be eaten within h hours.

Example:

piles = [3,6,7,11]
h = 8

Answer = 4

---

## Key Idea

We are NOT binary searching the array.

We are binary searching the possible ANSWERS.

Possible speeds:

1 ... max(piles)

Minimum possible speed = 1

Maximum possible speed = max(piles)

---

## Feasibility Check

For a given speed k, calculate how many hours are required.

For each pile:

hours += ceil(pile / k)

Using integer arithmetic:

hours += (pile + k - 1) / k

---

## Binary Search

If:

hours <= h

The speed works.

But we want the minimum working speed.

Therefore:

right = mid - 1

If:

hours > h

The speed is too slow.

Therefore:

left = mid + 1

---

## Final Answer

When Binary Search finishes:

left

is the minimum valid speed.

---

## Pattern

1 2 3 4 5 6 7 ... max

❌ ❌ ❌ ✅ ✅ ✅

             ↑
       first valid answer

This is Binary Search on Answer.

---

## Complexity

Let:

n = number of piles

M = maximum pile size

Binary Search has:

O(log M)

iterations.

Each iteration checks all n piles:

O(n)

Therefore:

Time = O(n log M)

Space = O(1)

---

## Important Concept

Binary Search does NOT require an array to be searched.

If the answer space is ordered and the feasibility condition is monotonic,
we can binary search the answer.

Example:

speed:
too slow → too slow → works → works → works

We find the first speed that works.

## Ceiling Division for Positive Integers

To calculate:

ceil(a / b)

using integer arithmetic:

(a + b - 1) / b

Example:

ceil(7 / 6)

= (7 + 6 - 1) / 6
= 12 / 6
= 2

Do NOT write:

ceil(a / b)

when a and b are integers, because a / b performs integer division first.

Example:

7 / 6 = 1

so:

ceil(7 / 6)

would effectively become:

ceil(1) = 1

which is incorrect.