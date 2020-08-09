// ***
//
// Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space
// characters.
//
// Please note that the string does not contain any non-printable characters.
//
// Example:
//
// Input: "Hello, my name is John"
// Output: 5
//
// ***

class Solution {
public:
    int countSegments(string s) {
        int wordCount = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else {
                // If we see a non-space, we've found a word, ++wordCount.
                // Now we need to find the next s[i] which is non-space.
                ++wordCount;
                while (i < s.length() && s[i] != ' ') {
                    ++i;
                }
            }

        }

        return wordCount;
    }
};
