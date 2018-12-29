// ***
//
// Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher,
// write a function to compute the researcher's h-index.
// Definition: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
// 
// Example:
// 
// Input: citations = [0,1,3,5,6]
// Output: 3 
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively. 
// Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, her h-index is 3.
//
// Note:
// If there are several possible values for h, the maximum one is taken as the h-index.
//
// ***
//
// By definition on Wikipedia, we can find H-index in the following way:
// Sort the array descending order, give each a index start from 1.
// From left to right, find the last number >= its index, the result is its H-index.
// i.e. h of his paper have at least h citations each
// In the case below, the H-index is 3.
//
// citations: 25, 8, 5, 3, 3, 2, 2, 0
// index:	  1,  2, 3, 4, 5, 6, 7, 8
//
// In this problem, we are given citations in ascending order and index from 0:
//
// citations: 0, 2, 2, 3, 3, 5, 8, 25
// index0:	  0, 1, 2, 3, 4, 5, 6, 7
//
// We can covert the index from 0-based to reverse 1-based by converting the original index to (n - index):
//
// citations: 0, 2, 2, 3, 3, 5, 8, 25
// index1:	  8, 7, 6, 5, 4, 3, 2, 1
//                           ^
//                           H-Index
// 
// The problem now becomes equivalent to using binary search (i.e. std::lower_bound)
// to find the first number in citations that is greater or equal to target
// (in this case the target is the correponding reversed 1-based index, i.e. n - mid)
int hIndex(vector<int>& citations)
{
	int n = citations.size();

	int left = 0;
	int right = citations.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (citations[mid] < n - mid)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	// right is the 0-based index,
	// so n - right is the reversed 1-based index.
	return n - right;
}
