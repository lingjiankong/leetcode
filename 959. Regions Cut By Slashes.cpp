// ***
//
// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These
// characters divide the square into contiguous regions.
//
// Given the grid grid represented as a string array, return the number of regions.
//
// Note that backslash characters are escaped, so a '\' is represented as '\\'.
//
// Example:
//
// Input: grid = [" /","/ "]
// Output: 2
//
// ***

// Very easy using union-find.
// For each grid, divide it into four triangles (left, up, right, down).
// Based on ' ', '/', or '\', connect these parts accordingly.
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        UnionFind<string> uf;

        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                string left = to_string(i) + "," + to_string(j) + ",left";
                string up = to_string(i) + "," + to_string(j) + ",up";
                string right = to_string(i) + "," + to_string(j) + ",right";
                string down = to_string(i) + "," + to_string(j) + ",down";

                uf.add(left);
                uf.add(up);
                uf.add(right);
                uf.add(down);

                if (grid[i][j] == ' ') {
                    uf.connect(left, up);
                    uf.connect(up, right);
                    uf.connect(right, down);
                } else if (grid[i][j] == '/') {
                    uf.connect(left, up);
                    uf.connect(right, down);
                } else if (grid[i][j] == '\\') {
                    uf.connect(down, left);
                    uf.connect(up, right);
                }

                // Connect neighboring triangles. Because we are traversing the grid from top to bottom, left to right,
                // you only need to look at the up and left neighbor of current triangle.
                if (i > 0) {
                    string upNeigh = to_string(i - 1) + "," + to_string(j) + ",down";
                    uf.connect(up, upNeigh);
                }

                if (j > 0) {
                    string leftNeigh = to_string(i) + "," + to_string(j - 1) + ",right";
                    uf.connect(left, leftNeigh);
                }
            }
        }

        return uf.numClusters();
    }
};
