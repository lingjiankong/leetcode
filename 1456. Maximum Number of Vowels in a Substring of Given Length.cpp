// ***
//
// Given a string s and an integer k.
// Return the maximum number of vowel letters in any substring of s with length k.
// Vowel letters in English are (a, e, i, o, u).
//
//
// Example 1:
//
// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
//
//
// Example 2:
//
// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
//
//
// Example 3:
//
// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
//
// ***

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxNumVowel = 0, curNumVowel = 0;
        int left = 0, right = 0;

        while (right < s.size()) {
            char c = s[right++];
            if (vowels.count(c)) {
                ++curNumVowel;
            }

            while (right - left == k) {
                maxNumVowel = max(maxNumVowel, curNumVowel);
                char c = s[left++];
                if (vowels.count(c)) {
                    --curNumVowel;
                }
            }
        }

        return maxNumVowel;
    }
};
