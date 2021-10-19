// ***
//
// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.
//
// ***

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { _backtrack(board, 0, 0); }

    bool _backtrack(vector<vector<char>>& board, int i, int j) {
        // Finished the entire board. Found a valid solution. Return true.
        if (i == 9) {
            return true;
        }

        // Finished current row. go to column 0 of next row.
        if (j >= 9) {
            return _backtrack(board, i + 1, 0);
        }

        // Not empty cell, keep looking at next row.
        if (board[i][j] != '.') {
            return _backtrack(board, i, j + 1);
        }

        // Empty cell, see which number we can use.
        for (char c = '1'; c <= '9'; ++c) {
            if (isValid(board, i, j, c)) {
                board[i][j] = c;
                if (_backtrack(board, i, j + 1)) {
                    return true;
                }
                board[i][j] = '.';
            }
        }

        return false;
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char val) {
        for (int x = 0; x < 9; ++x) {
            if (board[x][j] == val) {
                return false;
            }
        }

        for (int y = 0; y < 9; ++y) {
            if (board[i][y] == val) {
                return false;
            }
        }

        int row = i - i % 3, col = j - j % 3;
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (board[x + row][y + col] == val) {
                    return false;
                }
            }
        }

        return true;
    }
};
