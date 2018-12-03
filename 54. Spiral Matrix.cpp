// ***
//
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// 
// Example 1:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// 
// Example 2:
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//
// ***
//
// The idea is just to add the elements in the spiral order. First the up-most row (up), then the right-most column (right),
// then the down-most row (down), and finally the left-most column (left).
// After finishing a row or a column, update the corresponding variable to continue the process.
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix[0].empty())
	{
		return {};
	}

	vector<int> res;
	int m = matrix.size(), n = matrix[0].size();
	int up = 0, down = m - 1, left = 0, right = n - 1;

	while (true)
	{
		for (int j = left; j <= right; ++j)
		{
			res.push_back(matrix[up][j]);
		}
		if (++up > down)
		{
			break;
		}

		for (int i = up; i <= down; ++i)
		{
			res.push_back(matrix[i][right]);
		}
		if (--right < left)
		{
			break;
		}

		for (int j = right; j >= left; --j)
		{
			res.push_back(matrix[down][j]);
		}
		if (--down < up)
		{
			break;
		}

		for (int i = down; i >= up; --i)
		{
			res.push_back(matrix[i][left]);
		}
		if (++left > right)
		{
			break;
		}
	}

	return res;
}
