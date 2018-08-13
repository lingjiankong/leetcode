class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = m ? board[0].size() : 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int lives = 0;
                //  see how many total lives we have in a 3 by 3 window. Because board[x][y] is binary, we can sum all board[x][y] bitwise & 0b00000001 in this 3 by 3 window to get the total number of live cells.
                for (int x = max(0, i-1); x < min(m, i+2); ++x) {
                    for (int y = max(0, j-1); y < min(n, j+2); ++y) {
                        lives += board[x][y] & 0b00000001;
                    }
                }
                // the four rules on LeetCode can be summarized as if (lives == 3 || lives - board[i][j] == 3) then board[i][j] is live. We store whether board[i][j] is live using bitwise | with 0b00000010 and store the status in the second right most bit. After we've processed all cells, we right shift every board[i][j] to get its current status
                if (lives == 3 || lives - board[i][j] == 3) {
                    board[i][j] |= 0b00000010;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
