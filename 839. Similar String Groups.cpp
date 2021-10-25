// ***
//
// Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also
// two strings X and Y are similar if they are equal.
//
// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but
// "star" is not similar to "tars", "rats", or "arts".
//
// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars"
// and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in
// the group if and only if it is similar to at least one other word in the group.
//
// We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many
// groups are there?
//
//
// Example 1:
//
// Input: strs = ["tars","rats","arts","star"]
// Output: 2
//
//
// Example 2:
//
// Input: strs = ["omv","ovm"]
// Output: 1
//
//
// Constraints:
//
// 1 <= strs.length <= 300
// 1 <= strs[i].length <= 300
// strs[i] consists of lowercase letters only.
// All words in strs have the same length and are anagrams of each other.
//
// ***

// Note that we are told that all words in strs have the same length and are anagrams of each other.
// Union-find
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        UnionFind<string> uf;
        for (int i = 0; i < strs.size(); ++i) {
            uf.add(strs[i]);
        }

        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i + 1; j < strs.size(); ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    uf.connect(strs[i], strs[j]);
                }
            }
        }

        return uf.numClusters();
    }

private:
    // Note that we are told that all words have the same length and are anagrams,
    // therefore if diff = 0 or diff = 2 then they are anagrams.
    bool isSimilar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (++diff > 2) {
                    return false;
                }
            }
        }
        return diff == 0 or diff == 2;
    }
};

// DFS
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        unordered_set<string> visited;

        int numClusters = 0;
        for (string word : strs) {
            if (visited.count(word)) {
                continue;
            }

            // All similar strings will be marked visited during one traversal.
            dfs(strs, word, visited);
            ++numClusters;
        }

        return numClusters;
    }

private:
    void dfs(const vector<string>& words, const string& curWord, unordered_set<string>& visited) {
        if (visited.count(curWord)) {
            return;
        }

        visited.insert(curWord);

        for (string word : words) {
            if (isSimilar(curWord, word)) {
                dfs(words, word, visited);
            }
        }
    }

    bool isSimilar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (++diff > 2) {
                    return false;
                }
            }
        }
        return diff == 0 or diff == 2;
    }
};

