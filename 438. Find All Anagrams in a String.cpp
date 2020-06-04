// ***
//
// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than
// 20,100. The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
//
// Input:
// s: "abab" p: "ab"
//
// Output:
// [0, 1, 2]
//
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
//
// ***
//
// Read the code. Very intuitive. Idea is similar to 438. Find All Anagrams in a String.
//
// Maintain a sliding window (sHashWindow) of size p in s, slide it to the right and check
// if sHashWindow == pHash, if so then there's a valid anagram. add index to result.

vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
        return {};
    }

    vector<int> sHashWindow(256, 0);
    vector<int> pHash(256, 0);
    vector<int> toReturn;

    for (int i = 0; i < p.size(); ++i) {
        ++pHash[p[i]];
        ++sHashWindow[s[i]];  // Initial sliding window
    }

    // Check if initial windows match
    if (pHash == sHashWindow) {
        toReturn.push_back(0);
    }

    // i is the index of the last element in the *new* window to be moved
    for (int i = p.size(); i < s.size(); ++i) {
        // Move window to the right
        ++sHashWindow[s[i]];
        --sHashWindow[s[i - p.size()]];

        if (sHashWindow == pHash) {
            // Since i is the index (not the right most bound) of the last element in the window, the beginning index of
            // the window is just i - p.size() + 1
            toReturn.push_back(i - p.size() + 1);
        }
    }

    return toReturn;
}

