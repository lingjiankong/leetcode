// ***
//
// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
// 
// Example 1:
// Input: [3, 2, 1]
// 
// Output: 1
// 
// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]
// 
// Output: 2
// 
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]
// 
// Output: 1
// 
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.
//
// ***
//
// This question is kind of stupid. It ask you for the third *distinct* maximum number in the array.
// For example if you have [2, 2, 2], then the third max number is 2, but there's no third *distinct* maximum number.
//
// Note the difference between this question and 334. Increasing Triplet Subsequence.
// 334 asks us to find whether there's increasing triplet. This question asks us for the third maximum distinct element.
// Notice the difference in the update to elements inside the if else if loop and you'll get the idea
int thirdMax(vector<int>& nums)
{
	long firstMax = LONG_MIN;
	long secondMax = LONG_MIN;
	long thirdMax = LONG_MIN;

	for (int num : nums)
	{
		if (num > firstMax)
		{
			thirdMax = secondMax;
			secondMax = firstMax;
			firstMax = num;
		}
		// firstMax, secondMax, and thirdMax have to be distinctive,
		// that is why we have an additionam condition here checking if ... && num < firstMax 
		// Same for the next else if loop.
		else if (num > secondMax && num < firstMax)
		{
			thirdMax = secondMax;
			secondMax = num;
		}
		else if (num > thirdMax && num < secondMax)
		{
			thirdMax = num;
		}
	}

	if (thirdMax != LONG_MIN)
	{
		return thirdMax;
	}
	else
	{
		return firstMax;
	}
}
