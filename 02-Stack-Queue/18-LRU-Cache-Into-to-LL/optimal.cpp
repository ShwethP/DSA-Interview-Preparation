#include <iostream>
#include <unordered_map>

using namespace std;

// Each node stores a key, value and two pointers.
struct Node
{
    int key, value;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache
{
private:
    int capacity;

    // Key -> address of its linked-list node
    unordered_map<int, Node *> cache;

    Node *head;
    Node *tail;

    // Remove a node from its current position
    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert a node immediately after HEAD
    void insertAfterHead(Node *node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap)
    {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        // Key doesn't exist
        if (cache.find(key) == cache.end())
            return -1;

        // Get the node directly using the map
        Node *node = cache[key];

        // Make it the most recently used
        removeNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value)
    {
        // Case 1: Key already exists
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];

            node->value = value;

            removeNode(node);
            insertAfterHead(node);

            return;
        }

        // Case 2: New key
        Node *newNode = new Node(key, value);

        insertAfterHead(newNode);
        cache[key] = newNode;

        // Check if capacity is exceeded
        if (cache.size() > capacity)
        {
            Node *lru = tail->prev;

            // Remove its key from the map
            cache.erase(lru->key);

            // Remove it from the linked list
            removeNode(lru);

            delete lru;
        }
    }

    ~LRUCache()
    {
        Node *current = head;

        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    // Initialize an LRU Cache with capacity 2
    LRUCache lru(2);

    lru.put(1, 10); // Cache: [1:10]
    lru.put(2, 20); // Cache: [2:20, 1:10]

    cout << "get(1): " << lru.get(1) << endl; // Returns 10. Cache: [1:10, 2:20]

    lru.put(3, 30); // Capacity exceeded -> Evicts key 2. Cache: [3:30, 1:10]

    cout << "get(2): " << lru.get(2) << endl; // Returns -1 (evicted)
    cout << "get(3): " << lru.get(3) << endl; // Returns 30. Cache: [3:30, 1:10]

    lru.put(4, 40); // Capacity exceeded -> Evicts key 1. Cache: [4:40, 3:30]

    cout << "get(1): " << lru.get(1) << endl; // Returns -1 (evicted)
    cout << "get(3): " << lru.get(3) << endl; // Returns 30
    cout << "get(4): " << lru.get(4) << endl; // Returns 40

    return 0;
}
