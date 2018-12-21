// ***
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// 
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
// 
// Find the minimum element.
// 
// You may assume no duplicate exists in the array.
// 
// Example 1:
// Input: [3,4,5,1,2] 
// Output: 1
// 
// Example 2:
// Input: [4,5,6,7,0,1,2]
// Output: 0
//
// ***
//
// Looking at subarray with index [left, right], we can find out that if the first member is less than the last member,
// then there's no rotation in the array. So we could directly return the first element in this subarray.
// If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element.
// If value of the element in the middle is larger than the first element,
// we know the rotation is at the second half of this array. Else, it is in the first half in the array.
int findMin(vector<int> &num)
{
	int left = 0, right = num.size() - 1;
	
	while (left < right)
	{
		if (num[left] < num[right])
		{
			return num[left];
		}
		
		int mid = left + (right - left) / 2;
		
		if (num[mid] >= num[left])
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	
	return num[left];
}
