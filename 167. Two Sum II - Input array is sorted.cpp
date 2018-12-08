// ***
//
// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
// 
// Note:
// 
// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.
// 
// Example:
// 
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
//
// ***
//
// Since numbers is sorted, keep two pointers left and right, depending on the value of
// numbers[left] and numbers[right], move left pointer to the right or the right pointer to the left,
// until we found numbers[left] == numbers[right] or until left and right meet.
//
// See also 15. 3Sum and 18. 4Sum. They are all generalizations of this problem with almost identical code
// (those questions must deal with issues of duplicate result).
vector<int> twoSum(vector<int>& numbers, int target)
{
	int left = 0, right = numbers.size() - 1;

	while (left < right)
	{
		int sum = numbers[left] + numbers[right];
		if (sum == target)
		{
			return {left + 1, right + 1};
		}
		else if (sum < target)
		{
			++left;
		}
		else
		{
			--right;
		}
	}

	return {};
}
