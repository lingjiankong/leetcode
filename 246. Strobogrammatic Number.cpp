// ***
//
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//
// Example 1:
//
// Input:  "69"
// Output: true
// Example 2:
//
// Input:  "88"
// Output: true
// Example 3:
//
// Input:  "962"
// Output: false
//
// ***

bool isStrobogrammatic(string num) {
    unordered_map<char, char> hash = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    int i = 0, j = num.size() - 1;

    while (i <= j) {
        if (hash.count(num[i]) && num[j] == hash[num[i]]) {
            ++i, --j;
        } else {
            return false;
        }
    }

    return true;
}
