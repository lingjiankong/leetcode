// ***
//
// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
// 
// Note:
// 
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
// 
// Example 1:
// 
// Input: [2,2,1]
// Output: 1
// Example 2:
// 
// Input: [4,1,2,1,2]
// Output: 4
//
// ***
//
// Known that A XOR A = 0 and the XOR operator is commutative, the solution will be very straightforward.
// Let's say we have an array - [2,1,4,5,2,4,1]. What we are doing is essentially this:
// 
// => 2 ^ 1 ^ 4 ^ 5 ^ 2 ^ 4 ^ 1
// 
// => 2^2 ^ 1^1 ^ 4^4 ^5 (Rearranging, taking same numbers together)
// 
// => 0 ^ 0 ^ 0 ^ 5
// 
// => 5

int singleNumber(vector<int>& nums)
{
	int result = nums[0];

	for (int i = 1; i < nums.size(); ++i)
	{
		result ^= nums[i];
	}

	return result;
}
