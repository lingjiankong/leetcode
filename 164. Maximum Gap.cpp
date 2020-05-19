// ***
//
// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Return 0 if the array contains less than 2 elements.
//
// Example 1:
//
// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
//              (3,6) or (6,9) has the maximum difference 3.
//
// Example 2:
//
// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
// Note:
// - You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// - Try to solve it in linear time/space.
//
// ***
//
// The whole idea is bucket sort
// You put each element into the corresponding bucket.
//
// bucketSize is the size of each bucket
// i.e. How big each bucket is (the distance within each bucket).
//
// We would like to choose bucketSize, such that it is smaller than the
// minimum possible max difference between any two successive elements.
//
// Example:
// nums = [1, 4, 5, 8, 10, 25, 26, 27, 28, 29, 33], 11 elements.
// Mininum possible max difference, in float, is (33-1)/(11-1) = 32/10 = 3.2
// therefore bucketSize = (33-1)/(11-1) = 3, number of bucket = (33-1)/3 + 1 = 11
// We have the following buckets:
// [1, 4) | [4, 7) | [7, 10) | [10, 13) | [13, 16) | [16, 19) | [19, 22) | [22, 25) | [25, 28) | [28, 31) | [33, _)
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
// 11th bucket: min=33, max=33
//
// Given nums, the minimum possible max difference between any successive elements
// can not be smaller than (maxNum - minNum) / (n - 1).
// Visualize it: if you have nums = [3, 4, 5, 9],
// the minimum *possible* max difference between any two successive elements is
// (maxNum - minNum) / (n - 1) = (9 - 3) / (4 - 1) = 6 / 3 = 2.
// the *actual* max difference between two successive elements, in this case, is 4 (9 - 5 = 4).
//
// In the extreme case, nums are evenly spaced, for example when we have [3, 5, 7, 9],
// the minimum possible max difference between any two successive elements (9-3)/(4-1) = 2,
// and the actual max difference between two successive elements is also 2.
//
// Another example:
// When we have [1, 1, 2, 1, 1], the minimum possible max difference between any two successive elements
// is (2-1)/(5-1) = 1/4. We can't have a bucket size of 0, so we set the bucketSize to be 1.
// Actual max difference between two successive elements (2 - 1 = 1).
//
// So if we make bucketSize smaller than this minimum possible max difference between any two
// successive elements, then any difference within the same bucket is not the
// "actual max difference between two successive elements" we are looking for,
// so we are safe to look only for the inter-bucket differences.
//
// Actually, if you make the bucketSize between the buckets smaller than the
// minimum possible max difference between any two successive elements,
// everything works just fine, so making the buckets smaller doesn't affect the correctness,
// You might just as well use bucketSize = (maxNum-minNum)/(2n).
// and make the bucket size smaller (i.e. more buckets)

int maximumGap(vector<int>& nums) {
    // No such "difference between successive elements" if only one element.
    if (nums.size() < 2) {
        return 0;
    }

    int minNum = *min_element(nums.begin(), nums.end());
    int maxNum = *max_element(nums.begin(), nums.end());

    // If minNum == maxNum, max difference between two successive elements is just 0.
    if (minNum == maxNum) {
        return 0;
    }

    int n = nums.size();
    int bucketSize = max(1, (maxNum - minNum) / (n - 1));
    int numberOfBuckets = (maxNum - minNum) / bucketSize + 1;

    vector<int> bucketsMin(numberOfBuckets, INT_MAX);  // the min of each bucket
    vector<int> bucketsMax(numberOfBuckets, INT_MIN);  // the max of each bucket

    for (auto num : nums) {
        int index = (num - minNum) / bucketSize;  // bucket index

        // Update max and min value in each bucket.
        bucketsMin[index] = min(num, bucketsMin[index]);
        bucketsMax[index] = max(num, bucketsMax[index]);
    }

    int maxDifference = INT_MIN;

    int prevMax = minNum;

    // Iterate over all buckets.
    for (int i = 0; i < numberOfBuckets; ++i) {
        // maxDifference candidate is the min in current bucket, minus the max in previous bucket
        // (or previous previous previous bucket, if the last two bucket were empty, for example)
        // We only update maxDifference if min exists in current bucket
        if (bucketsMin[i] != INT_MAX) {
            maxDifference = max(maxDifference, bucketsMin[i] - prevMax);
        }

        // We only update prevMax if max exists in current bucket
        if (bucketsMax[i] != INT_MIN) {
            prevMax = max(prevMax, bucketsMax[i]);
        }
    }

    return maxDifference;
}
