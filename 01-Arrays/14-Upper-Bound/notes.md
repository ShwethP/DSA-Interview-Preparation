# Upper Bound

## Problem

Given a sorted array and a target, find the first index where:

a[index] > target

This is called the Upper Bound.

---

## Example

Array:

[1,2,2,2,4,5]

target = 2

Upper Bound = 4

Because index 4 contains the first element strictly greater than 2.

---

## Binary Search Logic

If:

a[mid] > target

Then mid is a possible answer.

Save/search further left:

right = mid - 1

If:

a[mid] <= target

Then mid cannot be the answer.

Search right:

left = mid + 1

---

## Implementation

```cpp
int upperBound(const vector<int>& a, int target) {
    int left = 0;
    int right = a.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}