// ***
//
// You are given an integer array ribbons, where ribbons[i] represents the length of the ith ribbon, and an integer k.
// You may cut any of the ribbons into any number of segments of positive integer lengths, or perform no cuts at all.
//
// For example, if you have a ribbon of length 4, you can:
// Keep the ribbon of length 4,
// Cut it into one ribbon of length 3 and one ribbon of length 1,
// Cut it into two ribbons of length 2,
// Cut it into one ribbon of length 2 and two ribbons of length 1, or
// Cut it into four ribbons of length 1.
// Your goal is to obtain k ribbons of all the same positive integer length. You are allowed to throw away any excess
// ribbon as a result of cutting.
//
// Return the maximum possible positive integer length that you can obtain k ribbons of, or 0 if you cannot obtain k
// ribbons of the same length.
//
//
// Example 1:
//
// Input: ribbons = [9,7,5], k = 3
// Output: 5
// Explanation:
// - Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
// - Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
// - Keep the third ribbon as it is.
// Now you have 3 ribbons of length 5.
//
// Example 2:
//
// Input: ribbons = [7,5,9], k = 4
// Output: 4
// Explanation:
// - Cut the first ribbon to two ribbons, one of length 4 and one of length 3.
// - Cut the second ribbon to two ribbons, one of length 4 and one of length 1.
// - Cut the third ribbon to three ribbons, two of length 4 and one of length 1.
// Now you have 4 ribbons of length 4.
//
// Example 3:
//
// Input: ribbons = [5,7,9], k = 22
// Output: 0
// Explanation: You cannot obtain k ribbons of the same positive integer length.
//
//
// Constraints:
//
// 1 <= ribbons.length <= 10^5
// 1 <= ribbons[i] <= 10^5
// 1 <= k <= 10^9
//
// ***

// Compare with
// 875. Koko Eating Bananas and
// 1011. Capacity To Ship Packages Within D Days
// which are very similar questions but are looking for minimum values (therefore uses lower_bound).
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        long sumRibbons = 0;
        for (long ribbon : ribbons) {
            sumRibbons += ribbon;
        }

        if (k > sumRibbons) {
            return 0;
        }

        // If we want a total of k ribbons,
        // Minimum possible cut length is 1, maximum possible cut length is sumRibbons / k.
        long left = 1, right = sumRibbons / k + 1;

        // upper_bound: Looking for maximum cut length.
        while (left < right) {
            // Candidate cut length
            long mid = left + (right - left) / 2;

            int numRibbons = 0;  // number of ribbons you can obtain of the same length.
            for (int ribbon : ribbons) {
                numRibbons += ribbon / mid;
            }

            if (numRibbons == k) {
                // Try if increase cut length still works.
                left = mid + 1;
            } else if (numRibbons < k) {
                // Need more ribbons, therefore need to decrease cut length.
                right = mid;
            } else if (numRibbons > k) {
                // Can have fewer ribbons, therefore need to increase cut length.
                left = mid + 1;
            }
        }

        // Note that since we are formulating the binary search in std::upper_bound way,
        // final "right" will be one greater than the actual cut length.
        // Therefore we should return right - 1 to get the actual cut length.
        return right - 1;
    }
};

