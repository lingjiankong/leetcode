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

// See labuladong book pp. 162.
// Easy to understand, TLE.
class Solution {
public:
    int maxA(int N) { return _dp(N, 0, 0); }

private:
    // n: remaining ops
    // nums_A_screen: current number of A on the screen
    // nums_A_clipboard: current number of A on the clipboard
    int _dp(int n, int nums_A_screen, int nums_A_clipboard) {
        if (n <= 0) {
            return nums_A_screen;
        }

        string key = to_string(n) + "," + to_string(nums_A_screen) + "," + to_string(nums_A_clipboard);
        if (_memo.count(key)) {
            return _memo[key];
        }

        // Cases:
        // 1. Print one 'A' on screen (A: 1 ops)
        // 2. Append clipboard content to current screen (Ctrl-V: 1 ops)
        // 3. Select current screen, then copy selected to clipboard (Ctrl-A, then Ctrl-C: 2 ops)
        return _memo[key] = max({_dp(n - 1, nums_A_screen + 1, nums_A_clipboard),
                                 _dp(n - 1, nums_A_screen + nums_A_clipboard, nums_A_clipboard),
                                 _dp(n - 2, nums_A_screen, nums_A_screen)});
    }

    unordered_map<string, int> _memo;
};

// See labuladong book pp. 166.
// dp[i]: Max numbers of 'A's on screen after i times of operations.
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            // If we print another 'A'
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i; ++j) {
                // If we Ctrl-A and Ctrl-C dp[j - 2], and then Ctrl-V (i - j) times,
                // then there are total of dp[j - 2] * (i - j + 1) 'A's currently on the screen.
                // (We Ctrl-V (i - j) times, plus dp[j - 2] itself)
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
            }
        }

        return dp[N];
    }
};
