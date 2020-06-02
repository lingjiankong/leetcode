// ***
//
// Implement strStr().
//
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2
//
// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
//
// Clarification:
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr()
// and Java's indexOf().
//
// ***
//
// This question is just saying find the index of a substring in a string.
// haystack: string, needle: substring.

int strStr(string haystack, string needle) {
    for (int i = 0;; ++i) {
        for (int j = 0;; ++j) {
            // Sequence of the if statement matters.
            if (j == needle.size()) {
                return i;
            }
            if (i + j == haystack.size()) {
                return -1;
            }
            if (needle[j] != haystack[i + j]) {
                break;
            }
        }
    }
    return -1;
}
