// ***
//
// Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
// Definition: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
// 
// Example:
// Input: citations = [3,0,6,1,5]
// Output: 3
//
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
// Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, her h-index is 3.
// Note: If there are several possible values for h, the maximum one is taken as the h-index.
//
// ***
//
// Think geometrically. Imagine plotting a histogram where the y-axis represents the number of citations for each paper.
// After sorting in descending order, h-index is the length of the largest square in the histogram.
int hIndex(vector<int>& citations)
{
	// By definition on Wikipedia, we can find H-index in the following way:
	// sort the array (contains the number of citations for each paper) in descending order,
	// give each a index start from 1. From left to right, find the last number >= its index,
	// the result is its index. In the case below, the H-index is 3.
	//
	// citations: 25, 8, 5, 3, 3, 2, 2, 0
	// index1:	  1,  2, 3, 4, 5, 6, 7, 8
	// index0:	  0,  1, 2, 3, 4, 5, 6, 7
	//
	// This is the same as saying from right to left, find the first number >= its index.
	// thus we can sort citations in ascending order and reverse the 1-based index simply using len(array)-i
	// citation: 0, 2, 2, 3, 3, 5, 8, 25
	// index1:	 8, 7, 6, 5, 4, 3, 2, 1
	sort(citations.begin(), citations.end());
	int n = citations.size();

	for (int i = 0; i < n; ++i)
	{
		// find the first number >= n-i
		if (citations[i] >= n-i)
		{
			return n-i;
		}
	}
	return 0;
}

// Counting sort, O(n)
int hIndex(vector<int>& citations)
{
	int n = citations.size();

	// The jth element is the number of papers with j citations,
	// i.e. there are papers[j] number of papers with j citations
	vector<int> papers (n+1, 0);

	for (int citation : citations)
	{
		// Max possible H-index is the number of paper published (n),
		// thus papers with number of citations greater than n is set to have n citations
		++papers[citation > n ? n : citation];
	}

	// res papers have at least i citations
	int res = 0;

	for (int i = papers.size() - 1; i > 0; --i)
	{
		// i here is the number of citations, papers[i] is the number of papers having i citations
		// ; i > 0 ; because you don't need think about i = 0 because papers with zero citation won't change the H-index
		res += papers[i];

		// res papers have at least i citations each <---> h papers have at least h citations each
		if (res >= i)
		{
			return i;
		}
	}

	return 0; // for example you have [0], one paper with zero citation, we return 0
}
