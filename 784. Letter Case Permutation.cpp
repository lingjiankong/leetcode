// ***
//
// Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create. You can return the output in any order.
//
//
// Example 1:
//
// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
//
//
// Example 2:
//
// Input: s = "3z4"
// Output: ["3z4","3Z4"]
//
//
// Example 3:
//
// Input: s = "12345"
// Output: ["12345"]
//
//
// Example 4:
//
// Input: s = "0"
// Output: ["0"]
//
//
// Constraints:
//
// s will be a string with length between 1 and 12.
// s will consist only of letters or digits.
//
// ***

// Very intuitive once you visualize the tree structure.
// See https://zxi.mytechroad.com/blog/searching/leetcode-784-letter-case-permutation/
//
// Uppercase A-Z: 65 - 90
// Lowercase a-z: 97 - 122
//
// 'a' - 'A' = 32, meaning lower case and upper case letter differs only in their 5th (0-based) bit.
//
// a = 0b1000001
// A = 0b1100001
//
// 
// 'a' ^= (1 << 5) = 'A'
// 'A' ^= (1 << 5) = 'a'
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> all; 
         
        int startIndex = 0;
        _dfs(s, startIndex, all); 
         
        return all; 
    }

private: 
    void _dfs(string& s, int startIndex, vector<string>& all) {
        if (startIndex == s.size()) {
            all.push_back(s); 
            return; 
        }

        // Number has one child tree
        // Letter has two child trees.
        _dfs(s, startIndex + 1, all);

        // Additional child tree of the letter.
        if (isalpha(s[startIndex])) {
            s[startIndex] ^= (1 << 5); 
            _dfs(s, startIndex + 1, all);
            s[startIndex] ^= (1 << 5);
        }
    }
}; 

