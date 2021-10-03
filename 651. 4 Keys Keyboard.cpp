// ***
//
// Imagine you have a special keyboard with the following keys:
//
// Key 1: (A): Print one 'A' on screen.
//
// Key 2: (Ctrl-A): Select the whole screen.
//
// Key 3: (Ctrl-C): Copy selection to buffer.
//
// Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
//
// Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you
// can print on screen.
//
// Example 1:
// Input: N = 3
// Output: 3
// Explanation:
// We can at most get 3 A's on screen by pressing following key sequence:
// A, A, A
//
// Example 2:
// Input: N = 7
// Output: 9
// Explanation:
// We can at most get 9 A's on screen by pressing following key sequence:
// A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
//
// Note:
// 1 <= N <= 50
// Answers will be in the range of 32-bit signed integer.
//
// ***

// See labuladong book pp. 166.
// dp[i]: Max numbers of 'A's on screen after i times of operations.
// base condition: dp[0] = 0 'A's on screen with 0 number of operations.
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            // Choice 1: Print another 'A'
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j <= i; ++j) {
                // Choice 2: Ctrl-V whatever in the clipboard.
                // If we Ctrl-A and Ctrl-C dp[j - 2], and then Ctrl-V (i - j) times,
                // then there are total of dp[j - 2] * (i - j + 1) 'A's currently on the screen.
                // (We Ctrl-V (i - j) times, plus dp[j - 2] itself)
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
            }
        }

        return dp[N];
    }
};
