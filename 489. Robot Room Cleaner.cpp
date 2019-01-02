// ***
//
// Given a robot cleaner in a room modeled as a grid.
// Each cell in the grid can be empty or blocked.
// The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.
// When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.
// Design an algorithm to clean the entire room using only the 4 given APIs shown below.
// 
// interface Robot {
//   // returns true if next cell is open and robot moves into the cell.
//   // returns false if next cell is obstacle and robot stays on the current cell.
//   boolean move();
// 
//   // Robot will stay on the same cell after calling turnLeft/turnRight.
//   // Each turn will be 90 degrees.
//   void turnLeft();
//   void turnRight();
// 
//   // Clean the current cell.
//   void clean();
// }
//
// Example:
// 
// Input:
// room = [
//   [1,1,1,1,1,0,1,1],
//   [1,1,1,1,1,0,1,1],
//   [1,0,1,1,1,1,1,1],
//   [0,0,0,1,0,0,0,0],
//   [1,1,1,1,1,1,1,1]
// ],
// row = 1,
// col = 3
// 
// Explanation:
// All grids in the room are marked by either 0 or 1.
// 0 means the cell is blocked, while 1 means the cell is accessible.
// The robot initially starts at the position of row=1, col=3.
// From the top left corner, its position is one row below and three columns right.
//
// Notes:
// - The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded".
// In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
// - The robot's initial position will always be in an accessible cell.
// - The initial direction of the robot will be facing up.
// - All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
// - Assume all four edges of the grid are all surrounded by wall.
//
// ***
class Solution
{

	public:

		void cleanRoom(Robot& robot)
		{
			unordered_set<string> visited;

			// Initial position is (0, 0). Initial orientation is up (specified by the problem).
			int x = 0, y = 0, orientation = 0;
			backtrack(robot, x, y, orientation, visited);
		}

	private:

		// Absolute (global) directions: going up, right, down, left.
		vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

		// Orientation is the robot's absolute (global) orientation: 0: up, 1: right, 2: down, 3: left
		void backtrack(Robot& robot, int x, int y, int orientation, unordered_set<string>& visited)
		{
			string position = to_string(x) + "," + to_string(y);

			if (visited.count(position))
			{
				return;
			}

			robot.clean();
			visited.insert(position);

			// For all four directions
			for (int i = 0; i < 4; ++i)
			{
				// If move succeeds, the robot will move forward one step, otherwise, the robot stays in place.
				if (robot.move())
				{
					int newX = x + directions[orientation][0], newY = y + directions[orientation][1];
					backtrack(robot, newX, newY, orientation, visited);

					// After backtracking, trace back to original position and orientation.
					// First turn 180 degree, move one step, then turn another 180 degree to face the original orientation.
					robot.turnRight(); robot.turnRight();
					robot.move();
					robot.turnRight(); robot.turnRight();
				}

				// Turn right to face next orientation.
				robot.turnRight();
				orientation = (orientation + 1) % 4;
			}
		}

};
