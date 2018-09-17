// index:   0   1   2   3   4   5

//              L1  R1
// num1:    3   5 | 8   9               cut1 (the vertical line): number of element to the left of nums1
// num2:    1   2   7 | 10  11  12      cut2 (the vertical line): number of element to the left of nums2
//                  L2  R2

// effect:  1   2   3   5   7 | 8   9   10   11   12

// the basic idea is to use binary search on nums1 to find cut1 (and cut2 can be automatically calculated as cut2 = (n1+n2)/2 - cut1), such that L1 <= R2 and L2 <= R1. The solution is very intuitive once you understand the code, so read the comment in code. If you don't get it (which you should), read https://blog.csdn.net/chen_xinjia/article/details/69258706

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) // we want nums1 to be the shorter array so our runtime can be O(min(log(n1, n2)))
            return findMedianSortedArrays(nums2, nums1);

        if (n1 == 0) // if length of num1 is zero, then we simply return the median of nums2. Note the problem tells us that nums1 and nums2 cannot be both empty so if n1 == 0 then nums2 must contain element
            return static_cast<double>(nums2[(n2-1)/2] + nums2[n2/2]) / 2;

        int len = n1 + n2;
        int cut1 = 0;
        int cut2 = 0;
        int cutL = 0; // i.e. low on nums1 - left bound for binary search of cut1 on nums1
        int cutR = n1; // i.e. high on nums1 - right bound for binary search of cut1 on nums1

        while (cut1 <= n1) { // minimum of cut1 can be 0 (nothing to the left), maximum of cut1 can be n1 (nothing to the right)

            cut1 = cutL + (cutR-cutL)/2;
            cut2 = len / 2 - cut1; // if we know cut1, then cut2 is just len/2-cut1 i.e. (n1+n2)/2-cut1.

            // if cut1 = 0, L1 is INT_MIN because nothing to cut1's left thus we can think of L1 as a very small value; if cut1 = n1, R1 = INT_MAX because nothing is cut1's right thus we can think of R1 as a very big value. Same thing applies for cut2.
            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            int R1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int R2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (L1 > R2) { // L1 too big, pulling down the range to search cut1 to the left by cutR = cut1 - 1
                cutR = cut1 - 1;
            } else if (L2 > R1) { // R1 too small, pushing up the range to search cut1 to the right cutL = cut1 + 1
                cutL = cut1 + 1;
            } else {
                // in this case we've found the right cut, now we need to see whether n1+n2 (i.e. len) is even or odd:
                // If len is even, then (number of element to the left of cut1 + number of element to the left of cut2) = (number of element to the right of cut1 + number of element to the right of cut2), that's why we return median of sorted array as static_cast<double>(max(L1, L2) + min(R1, R2)) / 2.
                // If len is odd, then (number of element to the right of cut1 + number of element to the right of cut2) has one more element than (number of element to the left of cut1 + number of element to the left of cut2), thus we return median of sorted array as static_cast<double>(min(R1, R2))
                if (len % 2 == 0) {
                    return static_cast<double>(max(L1, L2) + min(R1, R2)) / 2;
                } else {
                    return static_cast<double>(min(R1, R2));
                }
            }
        }

        return -1;

    }
};