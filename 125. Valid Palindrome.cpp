// ***
//
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
// Example 2:
//
// Input: "race a car"
// Output: false
//
// ***
//
// A palindrom is a sequence that reads the same backward as forward, e.g., madam or nurses run.

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        if (not isalnum(s[i])) {
            ++i;
        } else if (not isalnum(s[j])) {
            --j;
        } else {
            if (tolower(s[i++]) != tolower(s[j--])) {
                return false;
            }
        }
    }

    return true;
}
