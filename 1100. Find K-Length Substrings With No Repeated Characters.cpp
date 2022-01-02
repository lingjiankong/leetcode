// ***
//
// Given a string S, return the number of substrings of length K with no repeated characters.
// All characters of S are lowercase English letters.
//
// Example 1:
//
// Input: S = "havefunonleetcode", K = 5
// Output: 6
// Explanation:
// There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.
//
//
// Example 2:
//
// Input: S = "home", K = 5
// Output: 0
// Explanation:
// Notice K can be larger than the length of S. In this case is not possible to find any substring.
//
// ***

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        vector<int> window(26, 0);
        int left = 0, right = 0, count = 0;

        while (right < S.size()) {
            char c = S[right++];
            ++window[c - 'a'];

            while (right - left > K or window[c - 'a'] > 1) {
                char c = S[left++];
                --window[c - 'a'];
            }

            if (right - left == K) {
                ++count;
            }
        }

        return count;
    }
};

