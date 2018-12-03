// ***
//
// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
//
// ***
//
// One way is the first take the transpose, then reverse the rows.
// 1  2  3　　　 　　 1  4  7　　　　　  7  4  1
// 
// 4  5  6　　-->　　 2  5  8　　 -->  　8  5  2　　
// 
// 7  8  9 　　　 　　3  6  9　　　　    9  6  3
void rotate(vector<vector<int> > &matrix)
{
	int n = matrix.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
		reverse(matrix[i].begin(), matrix[i].end());
	}
}
