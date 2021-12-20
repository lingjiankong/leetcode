// ***
//
// Design a map that allows you to do the following:
//
// Maps a string key to a given value.
// Returns the sum of the values that have a key with a prefix equal to a given string.
// Implement the MapSum class:
//
// MapSum() Initializes the MapSum object.
// void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original
// key-value pair will be overridden to the new one. int sum(string prefix) Returns the sum of all the pairs' value
// whose key starts with the prefix.
//
//
// Example 1:
//
// Input
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
// Output
// [null, null, 3, null, 5]
//
// Explanation
// MapSum mapSum = new MapSum();
// mapSum.insert("apple", 3);
// mapSum.sum("ap");           // return 3 (apple = 3)
// mapSum.insert("app", 2);
// mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
//
//
// Constraints:
//
// 1 <= key.length, prefix.length <= 50
// key and prefix consist of only lowercase English letters.
// 1 <= val <= 1000
// At most 50 calls will be made to insert and sum.
//
// ***

// Using hash table
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {}

    void insert(const string &key, int val) {
        // This is needed because we might update key with different val.
        // originalVal will be updated. So the net effect to the prefixes are inc -= originalVal.
        int inc = val;
        if (word2val_.count(key)) {
            inc -= word2val_[key];
        }

        word2val_[key] = val;
        for (int i = 1; i <= key.length(); ++i) {
            prefix2sum_[key.substr(0, i)] += inc;
        }
    }

    int sum(const string &prefix) { return prefix2sum_[prefix]; }

private:
    unordered_map<string, int> word2val_;
    unordered_map<string, int> prefix2sum_;
};

// Using Trie
struct TrieNode {
    unordered_map<char, TrieNode *> children;
    int sum = 0;
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    void insert(string word, int value) {
        TrieNode *node = root;
        for (char c : word) {
            if (not node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->sum += value;
        }
    }

    // Get the value from prefix.
    int getVal(string prefix) {
        TrieNode *node = root;
        for (char c : prefix) {
            if (not node->children.count(c)) {
                return 0;
            }
            node = node->children[c];
        }
        return node->sum;
    }

private:
    TrieNode *root;
};

class MapSum {
public:
    MapSum() {}

    void insert(string key, int val) {
        // This is needed because we might update key with different val.
        int inc = val;
        if (hash.count(key)) {
            inc -= hash[key];
        }
        hash[key] = val;
        trie.insert(key, inc);
    }

    int sum(string prefix) { return trie.getVal(prefix); }

private:
    Trie trie;
    unordered_map<string, int> hash;
};

