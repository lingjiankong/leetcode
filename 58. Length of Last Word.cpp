// ***
//
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last
// word in the string. If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
// Example:
//
// Input: "Hello World"
// Output: 5
//
// ***

// Just brute force solution
int lengthOfLastWord(string s) {
    int length = 0;
    int lastWordEnd = 0;

    // First, from right to left, find the index of first non-space character,
    // this is the end of last word.
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != ' ') {
            lastWordEnd = i;
            ++length;
            break;
        }
    }

    // Then, from right to left, find the start of that word.
    // Before the start, there can either be a space,
    // or there could be no space in front (i.e. the word just start at index 0)
    for (int i = lastWordEnd - 1; i >= 0; --i) {
        if (s[i] == ' ') {
            break;
        }
        ++length;
    }

    return length;
}
