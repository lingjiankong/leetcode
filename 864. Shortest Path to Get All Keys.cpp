// ***
//
// You are given an m x n grid grid where:
//
// '.' is an empty cell.
// '#' is a wall.
// '@' is the starting point.
// Lowercase letters represent keys.
// Uppercase letters represent locks.
// You start at the starting point and one move consists of walking one space in one of the four cardinal directions.
// You cannot walk outside the grid, or walk into a wall.
//
// If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.
//
// For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English
// alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also
// that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
//
// Return the lowest number of moves to acquire all keys. If it is impossible, return -1.
//
//
//
// Example 1:
//
//
// Input: grid = ["@.a.#","###.#","b.A.B"]
// Output: 8
// Explanation: Note that the goal is to obtain all the keys not to open all the locks.
// Example 2:
//
//
// Input: grid = ["@..aA","..B#.","....b"]
// Output: 6
// Example 3:
//
//
// Input: grid = ["@Aa"]
// Output: -1
//
//
// Constraints:
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 30
// grid[i][j] is either an English letter, '.', '#', or '@'.
// The number of keys in the grid is in the range [1, 6].
// Each key in the grid is unique.
// Each key in the grid has a matching lock.
//
// ***

// The idea is intuitive once you understand it.
// The thinking process is the same as 847. Shortest Path VIsiting All Nodes.
// Basically, instead of treating the problem as 2D BFS (x, y), you treat it like 3D BFS (x, y, keys)
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        struct nodeState {
            int x;
            int y;
            int keys;  // keys you have collected so far
        };

        int m = grid.size(), n = grid[0].size();

        queue<nodeState> q;
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> visited;

        int allKeys = 0;  // goal is to collect all keys
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0});  // push start position to queue
                    visited[i][j][0] = true;
                }
                if ('a' <= grid[i][j] and grid[i][j] <= 'f') {
                    allKeys |= (1 << (grid[i][j] - 'a'));  // add current key to goal
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int steps = 0;
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                nodeState cur = q.front();
                q.pop();

                int curX = cur.x, curY = cur.y, curKeys = cur.keys;
                if (curKeys == allKeys) {  // reached goal
                    return steps;
                }

                for (vector<int>& dir : dirs) {
                    int neighX = curX + dir[0];
                    int neighY = curY + dir[1];
                    int neighKeys = curKeys;

                    if (neighX < 0 or neighX >= m or neighY < 0 or neighY >= n) {
                        continue;
                    }

                    if (visited[neighX][neighY][neighKeys]) {
                        continue;
                    }

                    if (grid[neighX][neighY] == '#') {  // wall
                        continue;
                    }

                    if ('A' <= grid[neighX][neighY] and grid[neighX][neighY] <= 'F') {  // lock
                        if (!(neighKeys & (1 << grid[neighX][neighY] - 'A'))) {  // cannot open lock with keys you have
                            continue;
                        }
                    }

                    if ('a' <= grid[neighX][neighY] and grid[neighX][neighY] <= 'f') {  // key
                        neighKeys |= (1 << (grid[neighX][neighY] - 'a'));  // pickup key and add to current keys
                    }

                    q.push({neighX, neighY, neighKeys});
                    visited[neighX][neighY][neighKeys] = true;
                }
            }
            ++steps;
        }

        return -1;
    }
};
