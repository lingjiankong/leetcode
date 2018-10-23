// The idea is to place the largest number in the right most position (m+n-1),
// and move from right to left and place the elements from nums1 and nums2
// into corresponding positions.
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = m - 1; // right most element of nums1
	int j = n - 1; // right most element of nums2
	int k = m + n - 1; // right most element of combined

	// Once all of the numbers from nums2 have been merged into nums1,
	// the rest of the numbers in nums1 that were not moved are already in the correct place
	// If we've finished a list, then the corresponding index (i.e. i or j) will be -1.
	while (j >= 0)
	{
		nums1[k--] = i >= 0 && nums1[i] > nums2[j] ? nums[i--] : nums[j--];
	}
}
