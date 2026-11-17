# Q17 – Add One to a Number Represented by Linked List

## Problem
Each node represents one digit. Add 1 to the number.

Example:
- Input: `1 → 2 → 9`
- Output: `1 → 3 → 0`

## Approach 1: Reverse and add
1. Reverse the linked list.
2. Add 1 to the first digit.
3. Propagate carry while necessary.
4. If carry remains after the final node, append a new node.
5. Reverse the list back.

Complexity: O(N) time, O(1) auxiliary space.

## Approach 2: Last non-9 node (optimal alternative)
1. Create a dummy node with value 0 pointing to the original head.
2. Track the last node whose value is not 9.
3. Increment that node.
4. Set every subsequent node to 0.
5. If the dummy was incremented, create a new head containing 1.

Complexity: O(N) time, O(1) auxiliary space.

## Key observation
Only the trailing 9s need to become 0 when adding one. The last non-9 digit is the only existing digit that needs to be incremented.

## Important test cases
- `1 → 2 → 3` becomes `1 → 2 → 4`
- `1 → 2 → 9` becomes `1 → 3 → 0`
- `9 → 9 → 9` becomes `1 → 0 → 0 → 0`
- `9` becomes `1 → 0`
- `0 → 0 → 9` becomes `0 → 1 → 0`