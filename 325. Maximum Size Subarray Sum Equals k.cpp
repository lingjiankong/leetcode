// The idea of this question is similar to Two Sum.
//
// You keep an unordered_map which stores:
// Key: cumulativeSum from beginning (0) to current index.
// Value: index corresponds to this cumulativeSum.
//
// Suppose you are at current index with current cumulativeSum.
// To find the beginning index and end index of a subarray whose sum == k:
// Simply find if cumulativeSumToIndex[cumulativeSum-k] exists in the unordered_map
// If exists, then the beginning index of a subarray whose sum == k is just cumulativeSumToIndex[cumulativeSum-k] + 1
// (i.e. Exculde everything from 0 to cumulativeSum-k inclusive)
// and the end index is current index.
// The length of this subarray is index - cumulativeSumToIndex[cumulativeSum-k]
//
// If you read the code you would understand the idea.  
int maxSubArrayLen(vector<int>& nums, int k)
{
	unordered_map<int, int>	cumulativeSumToIndex;

	int cumulativeSum = 0;
	int maxLength = 0;

	for (int index = 0; index < nums.size(); ++index)
	{
		cumulativeSum += nums[index];

		if (cumulativeSum == k)
		{
			// Since we are trying to find the maxLength of subarray which sums to k,
			// if we see the cumulativeSum from 0 to index is k, then
			// this must be the maxLength seen so far.
			maxLength = index + 1;
		}
		else if (cumulativeSumToIndex.find(cumulativeSum-k) != cumulativeSumToIndex.end())
		{
			// If cumulativeSum-k exists in the unordered_map, then we found a subarray which sums to k.
			// The index of this subarray starts from cumulativeSumToIndex[cumulativeSum-k] + 1
			// and end at current index,
			// so the length is just index - cumulativeSumToIndex[cumulativeSum-k]
			maxLength = max(maxLength, index - cumulativeSumToIndex[cumulativeSum-k]);
		}
		
		if (cumulativeSumToIndex.find(cumulativeSum) == cumulativeSumToIndex.end())
		{
			// Only update cumulativeSumToIndex if cumulativeSum does not exist,
			// since you are trying to get maxLength of the subarray,
			// the smaller the index is, the larger the resulting length.
			cumulativeSumToIndex[cumulativeSum] = index;
		}
	}

	return maxLength;
}
