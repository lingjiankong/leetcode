// ***
//
// You are given a m x n 2D grid initialized with these three possible values.
//
// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
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
class Solution
{

	public:

		void wallsAndGates(vector<vector<int>>& rooms)
		{
			if (rooms.empty() || rooms[0].empty())
			{
				return;
			}

			for (int i = 0; i < rooms.size(); ++i)
			{
				for (int j = 0; j < rooms[0].size(); ++j)
				{
					if (rooms[i][j] == 0)
					{
						int distance = 0;
						dfs(i, j, distance, rooms);
					}
				}
			}
		}
	
	private:

		void dfs(int i, int j, int distance, vector<vector<int>>& rooms)
		{
			// When rooms[i][j] < distance, either the cell is an obstacle, a gate,
			// or we've found a gate distance that is smaller for current distance, therefore return.
			if (i < 0 || j < 0 || i >= rooms.size() || j >= rooms[0].size() || rooms[i][j] < distance)	
			{
				return;
			}

			rooms[i][j] = distance;

			dfs(i + 1, j, distance + 1, rooms);
			dfs(i - 1, j, distance + 1, rooms);
			dfs(i, j + 1, distance + 1, rooms);
			dfs(i, j - 1, distance + 1, rooms);
		}

};
