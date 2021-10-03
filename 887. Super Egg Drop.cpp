// ***
//
// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
//
// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break,
// and any egg dropped at or below floor f will not break.
//
// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can
// no longer use it. However, if the egg does not break, you may reuse it in future moves.
//
// Return the minimum number of moves that you need to determine with certainty what the value of f is.
//
//
// Example 1:
//
// Input: k = 1, n = 2
// Output: 2
// Explanation:
// Drop the egg from floor 1. If it breaks, we know that f = 0.
// Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
// If it does not break, then we know f = 2.
// Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
//
//
// Example 2:
//
// Input: k = 2, n = 6
// Output: 3
//
//
// Example 3:
//
// Input: k = 3, n = 14
// Output: 4
//
// ***
//
// See labuladong book pp. 171.
// See huahua https://www.youtube.com/watch?v=aPY6sps_Q44. Great explanations.

// Intuitive, but TLE.
class Solution {
public:
    int superEggDrop(int k, int n) {
        // Only 1 drop available, must try all floors from bottom to top.
        if (k == 1) {
            return n;
        }

        // No more floor to test, we are done.
        if (n == 0) {
            return 0;
        }

        if (_memo.count(k) and _memo[k].count(n)) {
            return _memo[k][n];
        }

        // superEggDrop(k - 1, i - 1): if egg breaks on floor i,
        // In this case, we need to try floors [1, i - 1] (total of i - 1 floors)
        //
        // superEggDrop(k, n - i): if egg doesn't break on floor i.
        // In this case, we need to try floors [i + 1, n] (total of n - i floors)
        //
        // Since we want to consider the worst case, we take the max of the above two.
        // + 1 in the end because we are doing a drop on floor i.
        int minDrop = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            minDrop = min(minDrop, max(superEggDrop(k - 1, i - 1), superEggDrop(k, n - i)) + 1);
        }

        return _memo[k][n] = minDrop;
    }

private:
    unordered_map<int, unordered_map<int, int>> _memo;
};

// Optimized with binary search on the floor which we should try.
//
// We know that
// superEggDrop(k - 1, i - 1) (minDropsIfBroken) monotonically increases as i increases
// superEggDrop(k, n - i) (minDropsIfNotBroken) monotonically decreases as i increases
//
// In order to find
// minDrop = min(minDrop, max(superEggDrop(k - 1, i - 1), superEggDrop(k, n - i)) + 1);
//
// We can use binary search to find first i such that:
// superEggDrop(k - 1, i - 1) >= superEggDrop(k, n - i)
// (i.e. find first i such that minDropsIfBroken >= minDropsIfNotBroken)
class Solution {
public:
    int superEggDrop(int k, int n) {
        if (k == 1) {
            return n;
        }

        if (n == 0) {
            return 0;
        }

        if (_memo.count(k) and _memo[k].count(n)) {
            return _memo[k][n];
        }

        int left = 1, right = n + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            int minDropsIfBroken = superEggDrop(k - 1, mid - 1);
            int minDropsIfNotBroken = superEggDrop(k, n - mid);

            if (minDropsIfBroken == minDropsIfNotBroken) {
                right = mid;
            } else if (minDropsIfBroken < minDropsIfNotBroken) {
                left = mid + 1;
            } else if (minDropsIfBroken > minDropsIfNotBroken) {
                right = mid;
            }
        }

        // "right" is the first i such that superEggDrop(k - 1, i - 1) >= superEggDrop(k, n - i)
        int minDrop = max(superEggDrop(k, n - right), superEggDrop(k - 1, right - 1)) + 1;

        return _memo[k][n] = minDrop;
    }

private:
    unordered_map<int, unordered_map<int, int>> _memo;
};

// Not very intuitive to understand.
// Understanding the above solutions is sufficient.
//
// Faster definition of state:
// dp[m][k]: Given m moves and k eggs, what is the *maximum* number of floors we can check.
//
// Base case:
// dp[0][k] = 0. No moves can be performed. Nothing we can check.
// dp[m][0] = 0. No eggs. Nothing we can do.
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1));

        int m = 1;
        for (; m <= N; ++m) {
            for (int k = 1; k <= K; ++k) {
                // It takes 1 move to check a floor,
                // if egg breaks, then we can check dp[m - 1][k - 1] floors.
                // if egg doesn't breaks, then we can check dp[m - 1][k] floors.
                //
                // dp[m][k] is the *maximum* levels we can confirm with m moves and k eggs. When we look at floor
                // dp[m-1][k-1] + 1, the egg will either break, or not. If the egg breaks, it means we should find the
                // answer under this level. If the egg doesn't break, we can still use this egg, meaning we will use the
                // k eggs and m-1 moves to go to higher floor. So the maximum level we can reach at dp[m][k] is
                // dp[m-1][k-1] + 1 + dp[m-1][k].
                dp[m][k] = dp[m - 1][k - 1] + 1 + dp[m - 1][k];
            }

            // Return as soon as we've found number of moves m to check for at least N floors using K eggs.
            if (dp[m][K] >= N) {
                break;
            }
        }

        return m;
    }
};
