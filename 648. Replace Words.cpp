// ***
//
// In English, we have a concept called root, which can be followed by some other word to form another longer word -
// let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can
// form a new word "another".
//
// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the
// successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it
// with the root that has the shortest length.
//
// Return the sentence after the replacement.
//
//
//
// Example 1:
// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
//
// Example 2:
// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"
//
// Example 3:
// Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
// Output: "a a a a a a a a bbb baba a"
//
// Example 4:
// Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
//
// Example 5:
// Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
// Output: "it is ab that this solution is ac"
//
// ***

// Vanilla application of trie. Very easy. Nothing fancy.
// (The problem should have made sentence a vector instead of a string).
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;

        for (string& word : dictionary) {
            trie.insert(word);
        }

        istringstream iss(sentence);
        string word;
        string ans;
        while (iss >> word) {
            if (not ans.empty()) {
                ans += " ";
            }

            bool foundRoot = false;
            for (int i = 1; i <= word.size(); ++i) {
                if (trie.search(word.substr(0, i))) {
                    ans += word.substr(0, i);
                    foundRoot = true;
                    break;
                }
            }

            if (not foundRoot) {
                ans += word;
            }
        }

        return ans;
    }
};
