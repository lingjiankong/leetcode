// ***
//
// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
// 
// Example:
// 
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//
// ***
//
// See 54. Spiral Matrix. Same method.
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> toReturn(n, vector<int>(n, 0));

	int up = 0, down = n - 1, left = 0, right = n - 1;
	int val = 1;

	while (true)
	{
		for (int j = left; j <= right; ++j)
		{
			toReturn[up][j] = val++;
		}
		if (++up > down)
		{
			break;
		}

		for (int i = up; i <= down; ++i)
		{
			toReturn[i][right] = val++;
		}
		if (--right < left)
		{
			break;
		}

		for (int j = right; j >= left; --j)
		{
			toReturn[down][j] = val++;
		}
		if (--down < up)
		{
			break;
		}

		for (int i = down; i >= up; --i)
		{
			toReturn[i][left] = val++;
		}
		if (++left > right)
		{
			break;
		}
	}

	return toReturn;
}
