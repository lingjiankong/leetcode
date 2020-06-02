// ***
//
// Given an input string, reverse the string word by word.
//
// Example:
//
// Input: "the sky is blue",
// Output: "blue is sky the".
// Note:
//
// A word is defined as a sequence of non-space characters.
// Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or
// trailing spaces. You need to reduce multiple spaces between two words to a single space in the reversed string.
//
// ***
//
// The difference between this question and 186. Reverse Words in a String II is that in this question, there might be
// multiple spaces between words, and the string might contain leading and trailing spaces. Therefore you need to use
// istringstream.

string reverseWords(string &s) {
    istringstream stream(s);

    // Need to get first word separately because there should not be any space in front of the first word.
    string word;
    stream >> word;
    string toReturn = word;

    while (stream >> word) {
        toReturn = " " + word;
    }

    return toReturn;
}
