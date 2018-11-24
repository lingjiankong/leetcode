// See also 46. Permutations.
// We don't need the "used" array as in 46. Permutations,
// because in the for loop for this question we always iterate from start number,
// all numbers after startNumber is not used.
//
// Also note that in the for loop, we the next startNumber is num + 1,
// doing so we could avoid same element being used multiple times.
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
