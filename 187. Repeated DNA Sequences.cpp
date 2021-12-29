// ***
//
// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
// When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
// Example:
//
// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//
// Output: ["AAAAACCCCC", "CCCCCAAAAA"]
//
// ***
//
// The idea is very simple:
// Move a sliding window of size 10 (i.e. substring = s.substr(i, 10)), if the substring has never been seen before, add
// it to firstSeen. If we have seen the substring before (i.e. firstSeen.count(substring)), then add this substring to
// repeated. Note here that repeated is also an unordered_map because we don't want duplicate in our result. Finally,
// return the substrings in repeated.

vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> firstSeen;
    unordered_set<string> repeated;

    for (int i = 0; i + 9 < s.size(); ++i) {
        string substring = s.substr(i, 10);

        if (firstSeen.count(substring)) {
            repeated.insert(substring);
        } else {
            firstSeen.insert(substring);
        }
    }

    return vector<string>(repeated.begin(), repeated.end());
}

// Sliding window template.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> firstSeen;
        unordered_set<string> repeated;

        string window;
        int left = 0, right = 0;
        while (right < s.size()) {
            char c = s[right++];
            window += c;

            while (right - left == 10) {
                if (firstSeen.count(window)) {
                    repeated.insert(window);
                } else {
                    firstSeen.insert(window);
                }

                ++left;
                window.erase(0, 1);  // erase the first element from window.
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};
