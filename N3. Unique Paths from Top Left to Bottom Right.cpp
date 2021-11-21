// ***
//
// Return all unique paths from top left to bottom right.
//
// ***

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> uniquePaths(int m, int n) {
        vector<string> current;
        vector<vector<string>> all;

        _dfs(0, 0, m, n, current, all);

        return all;
    }

private:
    void _dfs(int i, int j, int m, int n, vector<string> current, vector<vector<string>>& all) {
        current.emplace_back("(" + to_string(i) + ", " + to_string(j) + ")");

        if (i == m - 1 and j == n - 1) {
            all.push_back(current);
            return;
        }

        for (vector<int>& dir : _dirs) {
            int neighX = i + dir[0], neighY = j + dir[1];

            if (neighX < m and neighY < n) {
                _dfs(neighX, neighY, m, n, current, all);
            }
        }
    }

    vector<vector<int>> _dirs = {{0, 1}, {1, 0}};
};

int main() {
    Solution soln;

    vector<vector<string>> path = soln.uniquePaths(2, 3);

    for (int i = 0; i < path.size(); ++i) {
        for (string& cell : path[i]) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
