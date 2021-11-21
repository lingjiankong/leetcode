// ***
//
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.
//
//
// Example 1:
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
//
//
// Example 2:
// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
//
//
// Constraints:
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 10^4
// 1 <= m * n <= 10^4
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.
//
// ***

// BFS can be written in different ways, but the basic idea is the same.
// Push all 0s to the queue, then ripple outwards.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        queue<vector<int>> q;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));  // ans serves as "visited". No need for another "visited"

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (not q.empty()) {
            vector<int> cur = q.front();
            q.pop();

            int i = cur[0], j = cur[1];
            for (vector<int>& dir : dirs) {
                int neighX = i + dir[0], neighY = j + dir[1];
                if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and ans[neighX][neighY] == INT_MAX) {
                    ans[neighX][neighY] = ans[i][j] + 1;
                    q.push({neighX, neighY});
                }
            }
        }

        return ans;
    }
};

