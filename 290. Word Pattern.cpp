// ***
//
// Given a pattern and a string str, find if str follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in
// str.
//
// Example 1:
// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
//
// Example 2:
// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
//
// Example 3:
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
//
// Example 4:
// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
//
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single
// space.
//
// ***

// This one uses the same idea as 205. Isomorphic Strings.
// See that question for intuition on this one.
// Especially the comments in the second implementation.
bool wordPattern(string pattern, string str) {
    unordered_map<char, int> charToInt;
    unordered_map<string, int> stringToInt;

    // Use istringstream so we can get individual word from a string of space separated words
    istringstream stream(str);

    int i = 0;
    for (string word; stream >> word; ++i) {
        if (charToInt.count(pattern[i]) && stringToInt.count(word)) {
            if (charToInt[pattern[i]] != stringToInt[word]) {
                return false;
            }
        } else if (charToInt.count(pattern[i]) || stringToInt.count(word)) {
            return false;
        } else {
            charToInt[pattern[i]] = stringToInt[word] = i;
        }
    }

    // In this case, we've finished all words in str but still have char in pattern left.
    // This is the case where lengthOf(pattern) != numberOfWords(str), must return false.
    if (i != pattern.size()) {
        return false;
    }

    return true;
}
