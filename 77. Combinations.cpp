// ***
//
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
// ***
//
// See also 46. Permutations.
//
// We don't need the "used" array as in 46. Permutations,
// because in the for loop for this question we always iterate from start number,
// all numbers after startNumber is not used.
//
// Also note that in the for loop, the next startNumber is num + 1,
// doing so we could avoid same element being used multiple times.
// startNumber could be all numbers in [1, n].
class Solution
{

    public:

		vector<vector<int>> combine(int n, int k)
        {
			int startNumber = 1;
            vector<int> currentCombination;
            vector<vector<int>> allCombinations;

            backtrack(n, k, startNumber, currentCombination, allCombinations);

            return allCombinations;
        }

    private:

        void backtrack(int n, int k, int startNumber, vector<int>& currentCombination, vector<vector<int>>& allCombinations)
        {
            if (currentCombination.size() == k)
            {
                allCombinations.push_back(currentCombination);
            }

            for (int num = startNumber; num <= n; ++num)
            {
                currentCombination.push_back(num);
                backtrack(n, k, num + 1, currentCombination, allCombinations);
                currentCombination.pop_back();
            }
        }

};
