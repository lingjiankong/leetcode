// In the first for loop, calculate the product of all numbers to the left of nums[i].
// Then in the second for loop, times the product of all numbers to the right of nums[i],
//
// Example:
// nums:                            [1,  2,  3,  4]
// Product to the left of nums[i]:  [1,  1,  2,  6]
// Product to the right of nums[i]: [24, 12, 4,  1]
// Combine together:                [24, 12, 8,  6]
//
vector<int> productExceptSelf(vector<int>& nums)
{
	vector<int> res(nums.size(), 1);

	int leftProduct = 1;

	for (int i = 0; i < nums.size(); ++i)
	{
		res[i] = leftProduct;
		leftProduct *= nums[i];
	}
	
	int rightProduct = 1;

	for (int i = nums.size()-1; i >= 0; --i)
	{
		res[i] *= rightProduct;
		rightProduct *= nums[i];
	}
	
	return res;
}
