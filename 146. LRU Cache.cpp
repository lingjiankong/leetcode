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
        auto itr = _hash.find(key);

        // If key does not exist, simply return -1.
        if (itr == _hash.end()) {
            return -1;
        }

        // Else if the key exists, move this key to the back of the linked list.
        _list.splice(_list.end(), _list, itr->second);

        // Return the value of the key.
        return itr->second->second;
    }

    void put(int key, int value) {
        auto itr = _hash.find(key);

        // Key already exists
        if (itr != _hash.end()) {
            // Update the value
            itr->second->second = value;

            // Move this entry to the back of the LinkedList (back of the linked list stores the most recently used
            // element). itr->second is iterator of type pair<int, int>::iterator, i.e. of element in the linked list
            _list.splice(_list.end(), _list, itr->second);
        } else {
            // Reached the capacity. Remove the oldest entry.
            if (_list.size() == _capacity) {
                auto node = _list.front();

                _hash.erase(node.first);
                _list.pop_front();
            }

            // Insert the entry to the end of the LinkedList and update mapping.
            _list.push_back({key, value});
            _hash[key] = --_list.end();
        }
    }

private:
    int _capacity;

    // LinkedHashMap
    // Stores (key : pointer to key value pair in the linked list).
    unordered_map<int, list<pair<int, int>>::iterator> _hash;

    list<pair<int, int>> _list;
};
