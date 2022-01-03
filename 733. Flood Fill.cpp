// ***
//
// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
//
// You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from
// the pixel image[sr][sc].
//
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel
// of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the
// same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
//
// Return the modified image after performing the flood fill.
//
// ***

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();

        // You still need visited array here because srcColor and newColor might be the same.
        // If srcColor and newColor are guaranteed to be not the same, then you do not need visited array
        // (in this the image itself serves as the visitied array).
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int srcColor = image[sr][sc];
        _dfs(sr, sc, srcColor, newColor, image, visited);
        return image;
    }

private:
    void _dfs(int x, int y, int& srcColor, int& newColor, vector<vector<int>>& image, vector<vector<bool>>& visited) {
        if (x < 0 or y < 0 or x >= image.size() or y >= image[0].size() or image[x][y] != srcColor or visited[x][y]) {
            return;
        }

        visited[x][y] = true;
        image[x][y] = newColor;

        for (vector<int>& dir : _dirs) {
            int neighX = x + dir[0], neighY = y + dir[1];
            _dfs(neighX, neighY, srcColor, newColor, image, visited);
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

