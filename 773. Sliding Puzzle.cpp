// ***
//
// On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of
// choosing 0 and a 4-directionally adjacent number and swapping it.
//
// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//
// Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If
// it is impossible for the state of the board to be solved, return -1.
//
// Example 1:
//
// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.
//
// Example 2:
//
// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.
//
// ***

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // We are given a 2 by 3 board. We can treat it as a 1D board and hardcode each positions neightboring index. If
        // we are given a board of different sizes, this can also be done dynamically.
        //
        // Stores where can a given 0 be moved. For example, if your 0 is at position 5 (lower right, (1, 2)),
        // then you can only swap with position 2 (0, 2) and 4 (1, 1)
        _neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

        int m = board.size(), n = board[0].size();

        string start;
        string target = "123450";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += to_string(board[i][j]);
            }
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int moves = 0;
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                string curBoard = q.front();
                q.pop();

                if (curBoard == target) {
                    return moves;
                }

                for (int i = 0; i < m * n; ++i) {
                    if (curBoard[i] == '0') {
                        for (int j : _neighbors[i]) {
                            string newBoard = curBoard;
                            swap(newBoard[i], newBoard[j]);

                            if (not visited.count(newBoard)) {
                                q.push(newBoard);
                                visited.insert(newBoard);
                            }
                        }
                    }
                }
            }
            ++moves;
        }

        return -1;
    }

private:
    vector<vector<int>> _neighbors;
};

