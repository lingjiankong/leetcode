// ***
//
// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
// Example 1:
//
// Input: 1
// Output: "1"
// Example 2:
//
// Input: 4
// Output: "1211"
//
// ***
//
// This is kind of a stupid question, nothing too much about certain algorithm.
// Maybe it tests how you use a mix up of for loop and while loop. Still worth look at it.
//
// Explaination about description on the website:
// 4.     1211
// 5.     111221 -> one 1, one 2, two 1s.
string countAndSay(int n) {
    if (n == 0) {
        return "";
    }

    string countAndSay = "1";

    // To calculate the "count and say" of every row.
    // (while(--n) will be executed n-2 times)
    while (--n) {
        string current = "";

        // Look at every digit in previous countAndSay,
        // and construct current countAndSay.
        for (int i = 0; i < countAndSay.size(); i++) {
            int count = 1;
            while (i < countAndSay.size() - 1 && countAndSay[i] == countAndSay[i + 1]) {
                ++count;
                ++i;
            }
            current += to_string(count) + countAndSay[i];
        }

        countAndSay = current;
    }

    return countAndSay;
}
