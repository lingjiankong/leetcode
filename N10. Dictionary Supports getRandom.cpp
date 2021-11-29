// ***
//
// Design a data structure that supports insert, delete, search and getRandom in constant time O(1).
// The data structure should support key-value pairs preferably of any type and the following operations:
//
//   insert(key, value): Inserts a key-value pair to the data structure
//   remove(key): Removes value by the key.
//   find(key): Searches a value by the key in the data structure.
//   getRandom(): Returns a random element from current set of elements.
//
// You can use any standard C/C++ libraries and containers.
//
// Use cases to check:
// insert("a", 1);
// insert("b", 2);
// insert("c", 3);
// insert("d", 4);
//
// getRandom();
// remove("b");
// find("d");
//
// ***

template <class KeyT, class ValueT>
class Structure {
public:
    void insert(const KeyT& key, const ValueT& val) {
        m[key] = {val, v.size()};
        v.push_back(key);
    }

    void remove(const KeyT& key) {
        if (!m.count(key)) {
            return;
        }

        pair<ValueT, int> e = m[key];

        ValueT val = e.first;
        int idx = e.second;

        // remove from map
        m.erase(key);

        // remove from vector
        swap(v[idx], v[v.size() - 1]);
        m[v[idx]].second = idx;
        v.pop_back();
    }

    ValueT find(const KeyT& key) const {
        if (m.count(key)) {
            return m[key].first;
        }

        return ValueT();
    }

    ValueT getRandom() const {
        int randIdx = rand() % v.size();
        return m[v[randIdx]].first;
    }

private:
    unordered_map<KeyT, pair<ValueT, int>> m;
    vector<KeyT> v;
};
