// ***
//
// Given an m x n board of characters and a list of strings words, return all words on the board.
// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or
// vertically neighboring. The same letter cell may not be used more than once in a word.
//
//
// Example 1:
//
// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words =
// ["oath","pea","eat","rain"] Output: ["eat","oath"]
//
//
// Example 2:
//
// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
//
//
// Constraints:
//
// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
//
// ***

// Very easy once you understand trie structure and how to use trie.
// Compare to 208. Implement Trie (Prefix Tree). This trie structure need to record the current string (str) stored in
// each node.
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string str;
    bool isWord = false;
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (not node->children.count(c)) {
                node->children[c] = new TrieNode();
                node->children[c]->str = word.substr(0, i + 1);
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (not node->children.count(c)) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string& word : words) {
            trie.insert(word);
        }

        vector<string> all;

        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = board[i][j];
                if (trie.startsWith(to_string(c))) {
                    _backtrack(board, trie.root->children[c], i, j, all);
                }
            }
        }

        return all;
    }

private:
    void _backtrack(vector<vector<char>>& board, TrieNode* node, int i, int j, vector<string>& all) {
        if (node->isWord) {
            all.push_back(node->str);
            node->isWord = false;  // remember to reset isWord (serve as "visited")
        }

        int m = board.size(), n = board[0].size();
        for (vector<int>& dir : _dirs) {
            int neighX = i + dir[0], neighY = j + dir[1];
            // Only keep traversing if trie has next prefix.
            if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and
                node->children.count(board[neighX][neighY])) {
                _backtrack(board, node->children[board[neighX][neighY]], neighX, neighY, all);
            }
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

