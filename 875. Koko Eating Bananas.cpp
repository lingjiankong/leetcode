// ***
//
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and
// will come back in h hours.
//
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k
// bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more
// bananas during this hour.
//
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//
// Return the minimum integer k such that she can eat all the bananas within h hours.
//
//
// Example 1:
//
// Input: piles = [3,6,7,11], h = 8
// Output: 4
//
// Example 2:
//
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
//
// Example 3:
//
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
//
//
// Constraints:
//
// 1 <= piles.length <= 10^4
// piles.length <= h <= 10^9
// 1 <= piles[i] <= 10^9
//
// ***

// Almost the same as 1011. Capacity To Ship Packages Within D Days
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }

        // Min speed she can eat banana is 1 banana per hour
        // Max speed she can eat banana is max(piles) bananas per hour
        int left = 1, right = maxPile + 1;

        // lower_bound: binary search on eat speed to find the minimum eat speed such that totalHours == h
        // (eat slowly before the guard comes back)
        while (left < right) {
            // mid is the candidate eat speed (bananas per hour)
            int mid = left + (right - left) / 2;

            // Hours take to finish all piles.
            int totalHours = 0;
            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid;  // (p + m - 1) / m is equivalent to ceil(p / m)
            }

            if (totalHours == h) {
                // Try to reduce the eat speed (lower_bound)
                right = mid;
            } else if (totalHours < h) {
                // Finished all before guard is back, we should reduce eat speed.
                right = mid;
            } else if (totalHours > h) {
                // Takes too long to eat, we should increase eat speed.
                left = mid + 1;
            }
        }

        return right;
    }
};

