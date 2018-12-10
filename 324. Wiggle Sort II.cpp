// ***
//
// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
// 
// Example 1:
// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].
// 
// Example 2:
// Input: nums = [1, 3, 2, 2, 3, 1]
// Output: One possible answer is [2, 3, 1, 3, 1, 2].
// 
// Note:
// You may assume all input has valid answer.
//
// ***
//
// See https://leetcode.com/problems/wiggle-sort-ii/discuss/77678/3-lines-Python-with-Explanation-Proof
//
// The idea is to first sort nums, then
// put the smaller half of the numbers on the even indexes and the larger half on the odd indexes,
// since the question asks us to reorder nums such that nums[0] < nums[1] > nums[2] < nums[3]... 
// 
// Example nums = [1,2,...,7]      Example nums = [1,2,...,8]
// Small half:  4 . 3 . 2 . 1      Small half:  4 . 3 . 2 . 1 .
// Large half:  . 7 . 6 . 5 .      Large half:  . 8 . 7 . 6 . 5
// --------------------------      --------------------------
// Together:    4 7 3 6 2 5 1      Together:    4 8 3 7 2 6 1 5
//
// We want odd-index numbers to be larger than their neighbors.
// Since we put the larger numbers on the odd indexes, clearly we already have:
// Odd-index numbers are larger than or *equal to* their neighbors.
// 
// However we can't let any adjacent numbers to be equal to each other,
// therfore, we need to put the each number from the sortedNums
// in their corresponding positions in nums starting *from right to left*.
// The purpose of putting numbers in nums from right to left is
// to keep the same element away from each other.
// 
// For example: 
// If you put each number in nums from left to right:
// smaller half: S S M M
// greater half: M M L L
// insert together : S M S M M L M L
// 
// If you put each number in nums from right to left:
// smaller half: S S M M
// greater half: M M L L
// insert together: M L M L S M S M
void wiggleSort(vector<int>& nums)
{
	vector<int> sortedNums = nums;
	sort(sortedNums.begin(), sortedNums.end());

	// i: the index in nums where we want to put the element at, starting at right most element.
	// j: index keeping track of the beginning of the smaller half, starting at 0.
	// k: index keeping track of the beginning of the bigger half, starting at one past the middle element.
	for (int i = sortedNums.size() -1, j = 0, k = (sortedNums.size() - 1) / 2 + 1; i >= 0; --i)
	{
		nums[i] = sortedNums[i & 1 ? k++ : j++];
	}
}
