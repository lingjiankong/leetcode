// Binary search is a O(nlogn), there's another O(n) method that uses the idea in linked list cycle.
// You can do that if you have time in the future.
//
// Nums is unsorted, but we show sorted nums for clarity. Our algorithm works with unsorted nums.
// Note that we are guaranteed that there is only one duplicate number in the array, but it could be repeated more than once.
// So something like [1, 2, 3, 3, 3, 4, 4, 4] is not possible.
//
// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive)
// In our case, there are a total of 11 elements, each element is between 1 and 10 inclusive.
//
// first mid = 5
// no duplicate in [1, 5]
// nums  [1 3 5 6 8 8 8 8 8 9 10]
// index [0 1 2 3 4 5 6 7 8 9 10]
//
// first mid = 5
// duplicate in [1, 5]
// nums  [3 3 3 3 3 4 6 7 9 10]
// index [0 1 2 3 4 5 6 7 8 9 10]
//
// Every time you calculate a new mid, you iterate through all nums and find
// how many elements are less than or equal to mid, and store it in count.
//
// If count > mid, then there are more than mid elements in the range [1, mid].
// That is, there are more than mid element in a range of size (mid-1)+1 = mid.
// Thus this range must contain a duplicate.
// 
// If count <= mid, then there are n+1-count elements in the range [mid+1, n].
// That is, at least n+1-mid elements in a range of size (n-(mid+1)+1 = n-mid.
// Thus that range must contain a duplicate.
//
// In another word, We know that the whole range is "too crowded" and thus that the first half or the second half of the range
// is too crowded. So you check to know whether the first half is too crowded, and if it isn't, you know that the second half is.
class Solution
{

	public:

		int findDuplicate(vector<int>& nums)
		{
			int low = 0;
			int high = nums.size() - 1;
			while (low <= high)
			{
				int mid = low + (high-low)/2;
				int count = 0;

				for (int num : nums)
				{
					if (num <= mid)
					{
						++count;
					}
				}

				// Left half too crowded.
				if (count > mid)
				{
					high = mid - 1;
				}
				// Right half too crowded.
				else
				{
					low = mid + 1;
				}
			}
			return low;
		}
};
