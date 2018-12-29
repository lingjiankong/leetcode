// ***
//
// You are given an integer array nums and you have to return a new counts array.
// The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
// 
// Example:
// 
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
//
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
// ***
//
// 将给定数组nums从最后一个开始，用二分法插入到一个新的数组sortedSeen，这样新数组sortedSeen就是有序的，
// 那么此时该数字在新数组sortedSeen中的坐标就是原数组nums中其右边所有较小数字的个数
vector<int> countSmaller(vector<int>& nums)
{
	vector<int> sortedSeen;
	vector<int> toReturn(nums.size());

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		int left = 0, right = sortedSeen.size();

		// Same as std::lower_bound, find the index of first number that >= target (nums[i])
		// All elements in sortedSeen to the left of this index are smaller than nums[i].
		while (left < right)
		{
			int mid = left + (right - left) / 2;

			if (sortedSeen[mid] < nums[i])
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}

		toReturn[i] = right;
		sortedSeen.insert(sortedSeen.begin() + right, nums[i]);
	}

	return toReturn;
}
