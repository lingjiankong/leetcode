// ***
// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
// 
// You have the following 3 operations permitted on a word:
// 
// Insert a character
// Delete a character
// Replace a character
// 
// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// 
// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
//
// ***
//
// Just memorize the code. Memorizing the code might be more efficient.
//
// dp[i][j] stores the minimum edit distance for word1[0, i) and word2[0, j) (i and j are the right bounds).
//
// Given two string word1 and word2, there are four cases when you calculate the minimum edit distance:
//
// word1 = "", word2 = "ros"
// 1. If word1 is empty, then the min edit distance is word2.size();
//
// word1 = "horse", word2 = ""
// 2. If word2 is empty, then the min edit distance is word1.size();
//
// word1 = "hors", word2 = "ros"
// 3. If word1[i-1] = word2[j-1] (i.e. last letter is the same),
// then the min edit distance = dp[i-1][j-1].
// That is, the min edit distance for (word1 = "hors", word2 = "ros") is the same as the min edit distance for (word1 = "hor", word2 = "ro").
//
// word1 = "horse", word2 = "ros"
// 4. If word1[i-1] != word2[j-1] (i.e. last later not the same),
// then the min edit distance is: dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1,
// where dp[i][j-1] stores the edit distance between (horse, ro), so (horse, ros) can be obtained by insertion (add one additional editing distance)
// where dp[i-1][j] stores the edit distance between (hors, ros), so (horse, ros) can be obtained by insertion (add one additional editing distance)
// where dp[i-1][j-1] stores the edit distance between (hors, ro), so (horse, ros) can be obtained by replacement (add one additional editing distance)
//
//   Ø a b c d
// Ø 0 1 2 3 4
// b 1 1 1 2 3
// b 2 2 1 2 3
// c 3 3 2 1 2

int minDistance(string word1, string word2)
{
	int m = word1.size(), n = word2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (int i = 0; i <= m; ++i)
	{
		dp[i][0] = i;
	}

	for (int j = 0; j <= n; ++j)
	{
		dp[0][j] = j;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (word1[i-1] == word2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
			}
		}
	}

	return dp[m][n];
}
