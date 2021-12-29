// ***
//
// Given an input string, reverse the string word by word.
//
// Example:
//
// Input: "the sky is blue",
// Output: "blue is sky the".
// Note:
//
// A word is defined as a sequence of non-space characters.
// Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or
// trailing spaces. You need to reduce multiple spaces between two words to a single space in the reversed string.
//
// ***
//
// The difference between this question and 186. Reverse Words in a String II is that in this question, there might be
// multiple spaces between words, and the string might contain leading and trailing spaces. Therefore you need to use
// istringstream.

string reverseWords(string &s) {
    istringstream stream(s);

    // Need to get first word separately because you don't want extra space before the first word.
    string word;
    stream >> word;
    string reversed = word;

    while (stream >> word) {
        reversed = word + " " + reversed;
    }

    return reversed;
}

// See 434. Number of Segments in a String, which uses same method to get rid of extra space.
class Solution {
public:
    string reverseWords(string &s) {
        string reversed;

        reverse(s.begin(), s.end());

        int startIdx = 0, endIdx = 0;  // startIdx and endIndx of a word (endIdx is either a space or end of s)
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else {
                startIdx = i;
                while (i < s.size() && s[i] != ' ') {
                    ++i;
                }
                endIdx = i;
                reverse(s.begin() + startIdx, s.begin() + endIdx);
                reversed = reversed + s.substr(startIdx, endIdx - startIdx) + " ";
            }
        }

        // Get rid of last space.
        if (reversed.back() == ' ') {
            reversed.pop_back();
        }

        return reversed;
    }
};
