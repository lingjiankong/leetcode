// ***
//
// Return all unique paths from top left to bottom right.
//
// ***
//
// Note: vector<string> current is NOT a reference.
// Side note: It seems in C++ backtracking problems, if you only have one operation in between
// current.push_back() and current.pop_back(), then parameter `current` can be a reference vector<string>& current.
// If you have two operations like this question does, then parameter `current` must be a non-reference value.
// This is because in the first _dfs, current has changed, but in the second _dfs we actually want the unchanged current.

class Solution {
public:
    vector<vector<int>> uniquePaths(int m, int n) {
        vector<string> current;
        vector<vector<string>> all;

        _dfs(0, 0, m, n, current, all);

        return all;
    }

private:
    void _dfs(int i, int j, int m, int n, vector<string> current, vector<vector<string>>& all) {
        if (i == m || j == n) {
            return;
        }

        if (i == m - 1 && j == n - 1) {
            current.emplace_back("(" + to_string(i) + ", " + to_string(j) + ")");
            all.push_back(current);
            return;
        }

        current.emplace_back("(" + to_string(i) + ", " + to_string(j) + ")");
        _dfs(i + 1, j, m, n, current, all);
        _dfs(i, j + 1, m, n, current, all);
        current.pop_back();
    }
};
