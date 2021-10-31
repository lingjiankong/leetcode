// ***
//
// Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed,
// and the character will be typed 1 or more times.
//
// You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with
// some characters (possibly none) being long pressed.
//
//
// Example 1:
//
// Input: name = "alex", typed = "aaleex"
// Output: true
// Explanation: 'a' and 'e' in 'alex' were long pressed.
//
//
// Example 2:
//
// Input: name = "saeed", typed = "ssaaedd"
// Output: false
// Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
//
//
// Example 3:
//
// Input: name = "leelee", typed = "lleeelee"
// Output: true
//
//
// Example 4:
//
// Input: name = "laiden", typed = "laiden"
// Output: true
// Explanation: It's not necessary to long press any character.
//
//
// Constraints:
//
// 1 <= name.length <= 1000
// 1 <= typed.length <= 1000
// name and typed contain only lowercase English letters.
//
// ***

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;

        for (int j = 0; j < typed.size(); ++j) {
            if (name[i] == typed[j]) {
                ++i;
                // if names[i] != names[j], then typed[j] must to be a long pressed letter (i.e. typed[j] == typed[j -
                // 1]). If that is not the case (including j == 0, meaning you are visiting the first letter of typed,
                // which is definitely not a long pressed letter), then return false.
            } else if (j == 0 or typed[j] != typed[j - 1]) {
                return false;
            }
        }

        return i == name.size();
    }
};
