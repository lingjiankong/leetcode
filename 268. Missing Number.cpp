// ***
//
// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
// 
// Example 1:
// Input: [3,0,1]
// Output: 2
//
// Example 2:
// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
//
// ***
//
// Bitwise XOR everything in the array [0, 1, ..., n] (one number is missing in the array) with [1, 2, ..., n], the leftover number must be the missing number.
int missingNumber(vector<int>& nums)
{
	int result = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		result ^= (i + 1) ^ nums[i];
	}

	return result;
}
