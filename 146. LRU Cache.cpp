// ***
//
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following
// operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it
// should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
//
// ***

// See also 460. LFU Cache
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        if (not keyToVal.count(key)) {
            return -1;
        }

        makeMostRecently(key);

        return keyToVal[key];
    }

    void put(int key, int value) {
        // Key already exists
        if (keyToVal.count(key)) {
            keyToVal[key] = value;
            makeMostRecently(key);
            return;
        }

        // Reached the capacity. Remove the oldest entry.
        if (_list.size() == _capacity) {
            removeLeastRecently();
        }

        // Insert the key to the end of the linked list and update mapping.
        keyToVal[key] = value;
        _list.push_back(key);
        _hash[key] = --_list.end();
    }

    void makeMostRecently(int key) {
        // Move this entry to the back of the linked list
        // (back of the linked list stores the most recently used element).
        // _hash[key] is iterator of type list<int>::iterator, i.e. points to the element in the linked list
        auto itr = _hash[key];
        _list.splice(_list.end(), _list, itr);
    }

    void removeLeastRecently() {
        int key = _list.front();
        keyToVal.erase(key);
        _hash.erase(key);
        _list.pop_front();
    }

private:
    int _capacity;

    unordered_map<int, int> keyToVal;

    // LinkedHashSet
    // Stores (key : pointer to the key in the linked list).
    unordered_map<int, list<int>::iterator> _hash;

    list<int> _list;
};

