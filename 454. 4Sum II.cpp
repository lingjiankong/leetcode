// ***
//
// Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
// 
// To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
// 
// Example:
// 
// Input:
// A = [ 1, 2]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2]
// 
// Output:
// 2
// 
// Explanation:
// The two tuples are:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
//
// ***
//
// Note that the problem has specified that A, B, C, D have the same length.
// 用两个哈希表分别记录AB和CB的两两之和出现次数，然后遍历其中一个哈希表，并在另一个哈希表中找和的相反数出现的次数
//
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	unordered_map<int, int> hash1, hash2;

	int n = A.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			++hash1[A[i] + B[j]];
			++hash2[C[i] + D[j]];
		}
	}

	int count = 0;
	for (auto sumAB : hash1)
	{
		int target = 0 - sumAB.first;

		if (hash2.count(target))
		{
			count += sumAB.second * hash2[target];
		}
	}

	return count;
}
