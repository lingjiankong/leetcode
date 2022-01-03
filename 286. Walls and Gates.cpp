// ***
//
// You are given a m x n 2D grid initialized with these three possible values.
//
// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that
// the distance to a gate is less than 2147483647. Fill each empty room with the distance to its nearest gate. If it is
// impossible to reach a gate, it should be filled with INF.
//
// Example:
//
// Given the 2D grid:
//
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
//
// After running your function, the 2D grid should be:
//
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4
//
//  ***

// BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }

        int m = rooms.size(), n = rooms[0].size();

        queue<vector<int>> q;  // {x, y, distance}
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all gates to queue.
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[0].size(); ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                vector<int> cur = q.front();
                q.pop();

                int i = cur[0], j = cur[1];
                for (vector<int>& dir : dirs) {
                    int neighX = i + dir[0], neighY = j + dir[1];
                    if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and not visited[neighX][neighY] and
                        rooms[neighX][neighY] != -1) {
                        int dist = rooms[i][j] + 1;

                        if (rooms[neighX][neighY] == INT_MAX) {  // update empty room with distance
                            rooms[neighX][neighY] = dist;
                        }

                        visited[neighX][neighY] = true;
                        q.push({neighX, neighY, dist});
                    }
                }
            }
        }
    }
};
