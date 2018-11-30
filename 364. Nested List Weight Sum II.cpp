// ***
//
// Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
// 
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
// 
// Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up.
// i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
// 
// Example 1:
// 
// Input: [[1,1],2,[1,1]]
// Output: 8
// Explanation: Four 1's at depth 1, one 2 at depth 2.
//
// Example 2:
// 
// Input: [1,[4,[6]]]
// Output: 17
// Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
//
// ***
//
// Because we don't know what the max depth is, we maintain a vector<int> of sum at all levels
// After the max depth is known (which is sumAtAllLevels.size()), we add the corresponding weight to the values in sumAtAllLevels
// and add all numbers together
class Solution
{

	public:

		int depthSumInverse(vector<NestedInteger>& nestedList)
		{
			int res = 0;
			vector<int> sumAtAllLevels;

			for (auto element : nestedList)
			{
				dfs(element, 0, sumAtAllLevels);
			}

			for (int i = sumAtAllLevels.size() - 1; i >= 0; --i)
			{
				res += sumAtAllLevels[i] * (sumAtAllLevels.size() - i);
			}

			return res;
		}
	
	private:

		void dfs(NestedInteger nestedInteger, int depth, vector<int> &sumAtAllLevels)
		{
			if (depth >= sumAtAllLevels.size())
			{
				sumAtAllLevels.push_back(0);
			}

			if (nestedInteger.isInteger())
			{
				sumAtAllLevels[depth] += nestedInteger.getInteger();
			}
			else
			{
				for (auto element : nestedInteger.getList())
				{
					dfs(element, depth + 1, sumAtAllLevels);
				}
			}
		}

};

