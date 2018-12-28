// ***
//
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// - Integers in each row are sorted in ascending from left to right.
// - Integers in each column are sorted in ascending from top to bottom.
// 
// Example:
// Consider the following matrix:
// 
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// 
// Given target = 5, return true.
// Given target = 20, return false.
//
// ***
//
// Just memorize it:
// Start with the upper right element, if target element is greater than it, search next row;
// If target element is smaller than it, search previous element on the same row.
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty() || matrix[0].empty())
	{
		return false;
	}
	
	int m = matrix.size();
	int n = matrix[0].size();

	int i = 0;
	int j = n - 1;

	while (i < m && j >= 0)
	{
		if (matrix[i][j] < target)
		{
			++i;
		}
		else if (matrix[i][j] > target)
		{
			--j;
		}
		else
		{
			return true;
		}
	}

	return false;
}
