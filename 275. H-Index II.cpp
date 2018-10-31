// See also 274. H-Index
// By definition on Wikipedia, we can find H-index in the following way:
// Sort the array descending order, give each a index start from 1.
// From left to right, find the last number >= its index, the result is its H-index.
// i.e. h of his paper have at least h citations each
// In the case below, the H-index is 3.
//
// citations: 25, 8, 5, 3, 3, 2, 2, 0
// index:	  1,  2, 3, 4, 5, 6, 7, 8
//
// In this problem, we are given citations in ascending order and index from 0
//
// citations: 0, 2, 2, 3, 3, 5, 8, 25
// index:	  0, 1, 2, 3, 4, 5, 6, 7
//
// We can covert it by subtracting length of array n with the index, we get:
//
// citations: 0, 2, 2, 3, 3, 5, 8, 25
// index0:	  0, 1, 2, 3, 4, 5, 6, 7
// index1:	  8, 7, 6, 5, 4, 3, 2, 1
//                           ^
//                           H-Index
//
// Now, instead of from left to right find the LAST number >= its index,
// we would like to from left to right find FIRST number >= its index.
// Now we can just use binary search to find that number.
// A thing we need to have in mind here is that we need to convert index0 to reversed index1 (i becomes nums.size()-i).
//
// if citations[mid] == n-mid, we find the H-index and return it
// if citations[mid] > n-mid, we set high = mid - 1, you DO NOT return here because you want the FIRST citations[mid] >= n-mid
// if citations[mid] < n-mid, we set low = mid + 1

// Why we return n - low in the end?
// Because it possible that until low == high, you still didn't find exactly citations[mid] == n-mid
// (i.e. first element in citations that = its index).
// In this case, we return the first element in citations > its index (if exists), which is n - low.
// While technically in the end when low == high, low = mid = high, so why not just return n-mid or n-high?
// The reason is that if citations is empty, then high = -1 and low is undefined.
// Therefore returning n - low is just safer and less drama.

int hIndex(vector<int>& citations)
{
	int n = citations.size();
	int low = 0;
	int high = citations.size() - 1;
	int mid;

	while (low <= high)
	{
		mid = low + (high-low)/2;
		if (citations[mid] == n-mid)
		{
			return citations[mid];
		}
		else if (citations[mid] > n-mid)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return n - low;
}
