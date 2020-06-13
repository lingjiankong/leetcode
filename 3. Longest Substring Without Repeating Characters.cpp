// ***
//
// Given a string, find the length of the longest substring without repeating characters.
//
// Example 1:
//
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
// Example 2:
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
// ***

// Keep a hashmap which stores the characters in string as keys and their positions as values,
// and keep two pointers which define the max non-repeating substring (the left pointer is `start` and the right pointer
// is `i`). Move the right pointer (i) to scan through the string, and meanwhile update the hashmap.
// 1. If the character is already in the hashmap, meaning we've seen a duplicated character,
// 2. AND, if current left pointer (start) is to the left of that duplicate letter,
//
// then move the left pointer (start) to the right of the same character last found, and update maxLength.
// Note that the two pointers can only move forward.
//
// Why do we need start = max(start, seen[s[i]] + 1) ?
// Suppose you have ZwhateverwhateverwhateverZ... Z occurs in the beginning and the end.
// If you do not check if where the current start position is, start will be set to the position after the first Z.
// This is not correct.
//
// Example:
// xyzabcdefghijklmna...
//	   ^			^
//	   start		i
//
// Therefore the length is i - start + 1
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> seen;

    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (seen.count(s[i])) {
            start = max(start, seen[s[i]] + 1);
        }

        maxLength = max(maxLength, i - start + 1);
        seen[s[i]] = i;
    }

    return maxLength;
}

// Same idea. Now, start is the index of last occurance of repeating character
// In previous solution, start is the index of the first non-repeating charater
//
// Example:
// _abcdefghijklmn...
// ^			 ^
// start = -1	 i
//
// xyzabcdefghijklmna...
//	  ^				^
//	  start			i
//
// Therefore the length is i - start
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> seen;

    int maxLength = 0;
    int start = -1;

    for (int i = 0; i < s.size(); ++i) {
        if (seen.count(s[i])) {
            start = max(start, seen[s[i]]);
        }

        maxLength = max(maxLength, i - start);
        seen[s[i]] = i;
    }

    return maxLength;
}
