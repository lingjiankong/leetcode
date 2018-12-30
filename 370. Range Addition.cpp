// ***
//
// Assume you have an array of length n initialized with all 0's and are given k update operations.
// Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of
// subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
// 
// Return the modified array after all k operations were executed.
// 
// Example:
// 
// Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
// Output: [-2,0,3,5,3]
// Explanation:
// 
// Initial state:
// [0,0,0,0,0]
// 
// After applying operation [1,3,2]:
// [0,2,2,2,0]
// 
// After applying operation [2,4,3]:
// [0,2,5,5,3]
// 
// After applying operation [0,2,-2]:
// [-2,0,3,5,3]
//
// ***
//
// This question was confusing to me until someone told me how to do it. It is hard to explain in word.
// The idea is mark the beginning with inc and mark one past the end with -inc,
// After you've done it for all updates, sum everything up later,
// now middle element are incremented as well, until the final decrement marker.
//
//  0  0  0  0  0  0
//
//  0  2  0  0 -2  0 ->  0  2  2  2  0  0
//  0  0  3  0  0 -3 ->  0  2  5  5  3  0
// -2  0  0  2  0  0 -> -2  0  3  5  3  0 
vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
{
	vector<int> toReturn, nums(length + 1, 0);

	for (int i = 0; i < updates.size(); ++i)
	{
		nums[updates[i][0]] += updates[i][2];
		nums[updates[i][1] + 1] -= updates[i][2];
	}

	int sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum += nums[i];
		toReturn.push_back(sum);
	}

	return toReturn;
}
