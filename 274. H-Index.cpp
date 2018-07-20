// Ed's video is somewhat confusing
// Think geometrically. Imagine plotting a histogram where the yy-axis represents the number of citations for each paper. After sorting in descending order, hh-index is the length of the largest square in the histogram.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // By definition on Wikipedia, we can find H-index in the following way: sort the array in descending order, give each a index start from 1. From left to right, find the last number >= its index, the result is its index. In the case below, the H-index is 3.

        // citations: 25, 8, 5, 3, 3, 2, 2, 0
        // index1:    1,  2, 3, 4, 5, 6, 7, 8
        // index0:    0,  1, 2, 3, 4, 5, 6, 7

        // This is the same as saying from right to left, find the first number >= its index.
        // thus we can sort citations in ascending order and reverse the 1-based index simply using len(array)-i
        // citation: 0, 2, 2, 3, 3, 5, 8, 25
        // index1:   8, 7, 6, 5, 4, 3, 2, 1
        int n = citations.size();
        std::sort(citations.begin(), citations.end());

        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= n-i) // find the first number >= n-i
                return n-i;
        }
        return 0;
    }

    // counting sort, O(n)
    int hIndex2(vector<int>& citations) {

        int n = citations.size();
        vector<int> papers (n+1, 0); // the jth element is the number of papers with j citations

        for (const int& citation : citations)
            ++papers[citation > n ? n : citation]; // max possible H-index is the number of paper published

        int res = 0;
        for (int i = papers.size() - 1; i > 0; --i) {
            // i here is the number of citations, papers[i] is the number of papers having i citations
            // ; i > 0 ; you don't need think about i = 0 because papers with zero citation won't change the H-index
            res += papers[i]; // res papers have at least i citations
            if (res >= i) // res papers have at least i citations each <-> h papers have at least h citations each
                return i;
        }
        return 0; // for example you have [0], one paper with zero citation, we return 0
    }
};
