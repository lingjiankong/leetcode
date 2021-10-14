// ***
//
// You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2
// indices(0-indexed) of the string.
//
// You can swap the characters at any pair of indices in the given pairs any number of times.
//
// Return the lexicographically smallest string that s can be changed to after using the swaps.
//
//
// Example 1:
//
// Input: s = "dcab", pairs = [[0,3],[1,2]]
// Output: "bacd"
// Explaination:
// Swap s[0] and s[3], s = "bcad"
// Swap s[1] and s[2], s = "bacd"
//
//
// Example 2:
//
// Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
// Output: "abcd"
// Explaination:
// Swap s[0] and s[3], s = "bcad"
// Swap s[0] and s[2], s = "acbd"
// Swap s[1] and s[2], s = "abcd"
//
//
// Example 3:
//
// Input: s = "cba", pairs = [[0,1],[1,2]]
// Output: "abc"
// Explaination:
// Swap s[0] and s[1], s = "bca"
// Swap s[1] and s[2], s = "bac"
// Swap s[0] and s[1], s = "abc"
//
// ***

// Treat all indices as node in a graph. Those that can be swapped are connected component.
// You can individually sort each component lexicographically,
// and then put each sorted compenent back to the original string.
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // Note: Must connect indices instead of chars, because there might be duplicate chars.
        UnionFind<int> uf;
        for (int i = 0; i < s.size(); ++i) {
            uf.add(i);
        }

        for (auto& e : pairs) {
            uf.connect(e[0], e[1]);
        }

        unordered_map<int, string> root2Chars;
        unordered_map<int, vector<int>> root2Indices;
        for (int i = 0; i < s.size(); ++i) {
            int root = uf.findRoot(i);
            root2Chars[root].push_back(s[i]);
            root2Indices[root].push_back(i);
        }

        for (auto& e : root2Chars) {
            sort(e.second.begin(), e.second.end());
        }

        for (auto& e : root2Indices) {
            int root = e.first;
            vector<int> indices = e.second;
            for (int i = 0; i < indices.size(); ++i) {
                s[indices[i]] = root2Chars[root][i];
            }
        }

        return s;
    }
};
