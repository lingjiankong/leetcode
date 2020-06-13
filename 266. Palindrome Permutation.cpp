// ***
//
// Given a string, determine if a permutation of the string could form a palindrome.
//
// Example 1:
// Input: "code"
// Output: false
//
// Example 2:
// Input: "aab"
// Output: true
//
// Example 3:
// Input: "carerac"
// Output: true
//
// ***
//
// Just check that no more than one character appears an odd number of times.
// Because if there is one, then it must be in the middle of the palindrome.
// So we can not have more than one character that appears an odd number of times.

bool canPermutePalindrome(const string& s) {
    bitset<256> seen;

    for (char letter : s) {
        seen.flip(letter);
    }

    return seen.count() <= 1;
}
