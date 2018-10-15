// The whole idea is bucket sort
// You put each element into the corresponding bucket.
//
// gap is the distance between each bucket
// i.e. the size of each bucket
// i.e. How big each bucket is
// i.e. the distance within each bucket. 
//
// We would like to choose gap size, such that it is smaller than the
// minimum possible max difference between any two successive elements.
//
// Example:
// nums = [1, 4, 5, 8, 10, 25, 26, 27, 28, 29, 30]
// gap = ceil(30-1)/11-1) = 3, number of bucket = nums.size()-1 = 10
// We have the following buckets:
// [1, 4) | [4, 7) | [7, 10) | [10, 13) | [13, 16) | [16, 19) | [19, 22) | [22, 25) | [25, 28) | [28, 30)
//
// 0th bucket: empty
// 1th bucket: min=4, max=5
// 2th bucket: min=8, max=8
// 3th bucket: min=10, max=10
// 4th bucket: empty
// 5th bucket: empty
// 6th bucket: empty
// 7th bucket: empty
// 8th bucket: min=25, max=27
// 9th bucket: min=28, max=29
// 
// Another example
// [ 2,      3,  4, 5,              10, 11,   12,     13	 ]
//  (minNum) 3 | 4, 5 |	    |     | 10, 11 |  12  |  (maxNum)
// gap = ceil(13-2)/(8-1) = ceil(11/7) = 2
// number of bucket = nums.size()-1 = 8-1 = 7
// 3, 4, 5, 10, 11, 12 are put into the corresponding positon in the bucket
//
// Given nums, the minimum possible max difference between any successive elemenets
// can not be smaller than (maxNum - minNum) / (n - 1).
// Visualize it: if you have nums = [3, 4, 5, 9],
// the minimum *possible* max difference between any two successive elements is
// (maxNum - minNum) / (n - 1) = (9 - 3) / (4 - 1) = 6 / 3 = 2.
// the *actual* max difference between two successive elements, in this case, is 4 (9 - 5 = 4).
//
// In the extreme case, nums are evenly spaced, for example when we have [3, 5, 7, 9], 
// the minimum possible max difference between any two successive elements is 2,
// and the actual max difference between two successive elements is also 2.
//
// Another example
// When we have [1, 1, 2, 1, 1], the minimum possible max difference between any two successive elements
// is (2-1)/(5-1) = 1/4, which ceil to 1, which is also the same as the
// actual max difference between two successive elements (2 - 1 = 2).
//
// So if we make bucket size (gap) smaller than this minimum possible max difference between any two
// successive elements, then any difference within the same bucket is not the
// "actual max difference between two successive elements" we are looking for, 
// so we are safe to look only for the inter-bucket differences.
//
// Actually, if you make the gap between the buckets smaller than the
// minimum possible max difference between any two successive elements,
// everything works just fine, so making the buckets smaller doesn't affect the correctness,
// You might just as well use gap = (maxNum-minNum)/(2n).
// and make the bucket size smaller (i.e. more buckets)
class Solution
{

	public:

		int maximumGap(vector<int>& nums)
		{

			// No such "difference between successive elements" if only one element.
			if (nums.size() < 2)
			{
				return 0;
			}

			int n = nums.size();
			int minNum = INT_MAX;
			int maxNum = INT_MIN;

			minNum = *min_element(nums.begin(), nums.end());
			maxNum = *max_element(nums.begin(), nums.end());
			
			// If minNum == maxNum, max difference between two successive elements is just 0.
			// 
			// Also, if minNum == maxNum, gap = (int)(ceil(((double)(maxNum-minNum)/(n-1)))) will be zero.
			// Later when we select bucket index we will have index = (num-minNum)/gap 
			// which is devided by zero. We do not want that.
			if (minNum == maxNum)
			{
				return 0;
			}

			// Why do we have std::ceil? Because it avoids the case when gap = 0.
			// We've tested if (minNum == maxNum) above so now maxNum-minNum must be greater than 0,
			// therefore ceil anything greater than 0 will give us 1.
			//
			// std::ceil takes floating point values, that's why we cast our integer devision result to double
			int gap = (int)(ceil(((double)(maxNum-minNum)/(n-1))));

			vector<int> bucketsMin(n-1, INT_MAX); // the min of each bucket
			vector<int> bucketsMax(n-1, INT_MIN); // the max of each bucket

			for (auto num : nums)
			{
				if (num == minNum || num == maxNum)
				{
					// we don't want to put minNum and maxNum in the bucket.
					// We will deal with them in the next loop
					continue;
				}

				int index = (num-minNum) / gap; // bucket index
				
				// Update max and min value in each bucket.
				bucketsMin[index] = min(num, bucketsMin[index]);
				bucketsMax[index] = max(num, bucketsMax[index]);
			}

			int maxDifference = INT_MIN;

			int prevMax = minNum;

			// Iterate over all buckets (we have n-1 buckets)
			for (int i = 0; i < n-1; ++i)
			{
				// maxDifference candidate is the min in current bucket, minus the max in previous bucket
				// (or previous previous previous bucket, if the last two bucket were empty, for example)
				// We only update maxDifference if min exists in current bucket
				if (bucketMin[i] != INT_MAX)
				{
					maxDifference = max(maxDifference, bucketsMin[i] - prevMax);
				}
				
				// We only update prevMax if max exists in current bucket
				if (bucketMax[i] != INT_MIN)
				{
					prevMax = max(prevMax, bucketsMax[i]);
				}
			}

			// Don't forget maxNum
			maxDifference = max(maxDifference, maxNum - prevMax);

			return maxDifference;
		}
};
