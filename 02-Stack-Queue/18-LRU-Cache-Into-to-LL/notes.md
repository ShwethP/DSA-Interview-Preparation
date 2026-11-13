# Problem 18 — LRU Cache

## Problem
Design a Least Recently Used (LRU) Cache with a fixed capacity.

Operations:
- `get(key)`: Return the value if the key exists, otherwise -1. Accessing a key makes it most recently used.
- `put(key, value)`: Insert or update a key. If capacity is exceeded, remove the least recently used key.

Both operations should take O(1) average time.

## Data Structures Used

### 1. unordered_map
- Stores `key -> Node*`.
- Provides O(1) average lookup.
- Directly gives us the address of the corresponding linked-list node.

### 2. Doubly Linked List
- Maintains the order of usage.
- Head represents most recently used.
- Tail represents least recently used.
- Each node has `prev` and `next` pointers.
- Allows removal and insertion at a known position in O(1).

## Important Operations

### removeNode(node)
Reconnect the previous and next nodes to remove the given node from the list.

### insertAfterHead(node)
Insert the given node immediately after the dummy head. This makes it the most recently used.

### get(key)
1. Check whether the key exists in the map.
2. If missing, return -1.
3. Find its node using the map.
4. Remove it from its current position.
5. Insert it after head.
6. Return its value.

### put(key, value)
1. If the key already exists:
   - Update its value.
   - Move its node to the front.
2. Otherwise:
   - Create a new node.
   - Insert it after head.
   - Store its pointer in the map.
3. If map size exceeds capacity:
   - Select `tail->prev`.
   - Erase its key from the map.
   - Remove it from the linked list.
   - Delete the node.

## Example

Capacity = 2

Operations:
- put(5, 50)
- put(6, 60)
- get(5)
- put(7, 70)

List order:
- After put(5): 5
- After put(6): 6 → 5
- After get(5): 5 → 6
- After put(7): 7 → 5

Key 6 is evicted because it is least recently used.

## Complexity

| Operation | Complexity |
|---|---|
| get | O(1) average |
| put | O(1) average |
| Remove node | O(1) |
| Insert at front | O(1) |
| Space | O(capacity) |

## Interview Takeaway

LRU Cache is a classic example of combining two data structures:
- Hash map for fast lookup.
- Doubly linked list for fast ordering updates.

A normal queue is insufficient because an arbitrary accessed element must be moved to the most-recently-used position.

**Pattern to remember:** Hash Map + Doubly Linked List.