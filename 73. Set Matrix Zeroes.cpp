// ***
//
// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
// 
// Example 1:
// 
// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:
// 
// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
//
// ***
//
// Although this solution is long, it is very clear in conveying the idea once you know what's going on:
// Store state (bool flag which indicates whether to set each row/col to zero) of each row in the first element of that row,
// and store state of each column in the first element of that column.
// Because the state of row0 and the state of column0 would occupy the same cell, we define two bool:
// rowZero and colZero, to store the state of the first row, and first column.
void setZeroes(vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix[0].empty())
	{
		return;
	}

	int m = matrix.size(), n = matrix[0].size();
	bool rowZero = false, colZero = false;

	// Traverse the first column and first row to set rowZero and colZero.
	for (int i = 0; i < n; ++i)
	{
		if (matrix[0][i] == 0)
		{
			rowZero = true;
			break;
		}
	} 
	for (int i = 0; i < m; ++i)
	{
		if (matrix[i][0] == 0)
		{
			colZero = true;
			break;
		}
	}

	// Traverse the entire matrix except the first row and first column
	// to set the flag for that row and column.
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	// After we have the flag for each row and column, traverse the
	// entire matrix again to set correct value for every single element.
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (matrix[0][j] == 0 || matrix[i][0] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}

	// Now deal with the first row and first column according to their flags.
	if (rowZero)
	{
		for (int i = 0; i < n; ++i) matrix[0][i] = 0;
	}
	if (colZero)
	{
		for (int i = 0; i < m; ++i) matrix[i][0] = 0;
	}
}
