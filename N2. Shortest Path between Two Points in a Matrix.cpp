// ***
//
// Given a matrix of size m by n, find the shortest path from a source cell to a goal cell.
// You can only move up, down, left and right.
//
// If there's no path between start and goal, return -1.
//
// 's' represents source
// 'd' represents goal
// '1' represents cell you can travel
// '0' represents obstacles
//
// ***
//
// The same logic as N1. Shortest Distance between Two Cells in a Matirx.
// Depending whether you want to return the shortest distance or the shortest path, you should either:
//
// 1. Maintain a vector<vector<int>> distance, which stores the distance from goal to start for every (x, y)
// if the want the minimum distance between start and goal, OR
//
// 2. Maintain a vector<vector<pair<int, int>>> from, which from[i][j] stores which cell you came from to reach (x, y)
// You later use this matrix to reconstruct the path. If you store vector<vector<pair<int, int>>> from,
// then there's no need for distance matrix, because distance can be implicitly computed from the path.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int>> shortestPath(const pair<int, int>& start, const pair<int, int>& goal, const vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<pair<int, int>>> from(m, vector<pair<int, int>>(n, {INT_MAX, INT_MAX}));
    vector<vector<bool>> visited(m, vector<bool>(n));

    // Applying BFS on matrix cells starting from start 
    queue<pair<int, int>> cellQueue;
    cellQueue.push(start);
    visited[start.first][start.second] = true;

    while (!cellQueue.empty())
    {
        pair<int, int> cell = cellQueue.front(); cellQueue.pop();
        int x = cell.first, y = cell.second;

        // Found the goal.
        if (pair<int, int>(x, y) == goal)
        {
			break;
        }

        // Moving up 
        if (x - 1 >= 0 && grid[x - 1][y] != '0' && !visited[x - 1][y])
        {
            cellQueue.push({x - 1, y});
            from[x - 1][y] = {x, y};
            visited[x - 1][y] = true;
        }

		// Moving down 
		if (x + 1 < m && grid[x + 1][y] != '0' && !visited[x + 1][y])
        {
            cellQueue.push({x + 1, y});
            from[x + 1][y] = {x, y};
            visited[x + 1][y] = true;
        }

        // Moving left 
        if (y - 1 >= 0 && grid[x][y - 1] != '0' && !visited[x][y - 1])
        {
            cellQueue.push({x, y - 1});
            from[x][y - 1] = {x, y};
            visited[x][y - 1] = true;
        }

        // Moving right 
        if (y + 1 < n && grid[x][y + 1] != '0' && !visited[x][y + 1])
        {
            cellQueue.push({x, y + 1});
            from[x][y + 1] = {x, y};
            visited[x][y + 1] = true;
        }
    }

	// Reconstruct path (from goal to start)
	vector<pair<int, int>> toReturn;
	pair<int, int> cell = goal;
    while (cell != pair<int, int>(INT_MAX, INT_MAX))
    {
		toReturn.push_back({cell.first, cell.second});
		cell = from[cell.first][cell.second]; 
    }

	// Reverse the path (so it is from start to goal)
	reverse(toReturn.begin(), toReturn.end());
	cout << "Shortest path to goal is: " << endl;
	for (auto cell : toReturn)
	{
		cout << "(" << cell.first << ", " << cell.second << ") " << endl;
	}
	cout << "Distance to goal is: " << toReturn.size() - 1 << endl;

    return toReturn;
}

int main()
{
    vector<vector<char>> grid = {
        { '0', '1', '0', '1' },
        { '1', '0', '1', '1' },
        { '0', '1', '1', '1' },
        { '1', '1', '1', '1' }};

	pair<int, int> start = {0, 3};
	pair<int, int> goal = {3, 0};

    vector<pair<int, int>> path = shortestPath(start, goal, grid);

    return 0;
}
