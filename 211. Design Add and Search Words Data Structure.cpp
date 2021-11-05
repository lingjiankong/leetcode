// ***
//
// Design a data structure that supports adding new words and finding if a string matches any previously added string.
//
// Implement the WordDictionary class:
//
// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
// word may contain dots '.' where dots can be matched with any letter.
//
//
// Example:
//
// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]
//
// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
//
//
// Constraints:
//
// 1 <= word.length <= 500
// word in addWord consists lower-case English letters.
// word in search consist of  '.' or lower-case English letters.
// At most 50000 calls will be made to addWord and search.
//
// ***

struct TrieNode {
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode *node = root;
        for (char c : word) {
            if (not node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    bool search(string word, int start, TrieNode *root) {
        if (start == word.size()) {
            return root->isWord;
        }

        if (word[start] == '.') {
            for (auto &child : root->children) {
                // Return true if *any* of the search returns true.
                // You cannot just "return search(word, start + 1, child.second)"
                // because in this case you will only consider the first child (wrong)
                if (search(word, start + 1, child.second)) {
                    return true;
                }
            }
        } else if (root->children.count(word[start])) {
            return search(word, start + 1, root->children[word[start]]);
        }

        return false;
    }

    TrieNode *root;
};

class WordDictionary {
public:
    WordDictionary() {}

    void addWord(string word) { _trie.insert(word); }

    bool search(string word) { return _trie.search(word, 0, _trie.root); }

private:
    Trie _trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
