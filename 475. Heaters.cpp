// ***
//
// Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all
// the houses.
//
// Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that
// all houses could be covered by those heaters.
//
// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum
// radius standard of heaters.
//
// Note:
//
// Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
// Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
// As long as a house is in the heaters' warm radius range, it can be warmed.
// All the heaters follow your radius standard and the warm radius will the same.
//
//
// Example 1:
//
// Input: [1,2,3],[2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses
// can be warmed.
//
//
// Example 2:
//
// Input: [1,2,3,4],[1,4]
// Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses
// can be warmed.
//
// ***

// The idea is very simple. For each house, you find the *two* heaters that are next to it (using binary search).
// You compare the distance between heater and the house. Final radius of the heater is the maximum distance ever seen.
// You need to pay special attention when pos = heaters.begin() or pos = heaters.end().
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxRadius = 0;  // maximum of min radius we've seen
        sort(heaters.begin(), heaters.end());

        for (int house : houses) {
            // Find the first heater position that is no less than house position.
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);

            int rightDist = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int leftDist = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);

            maxRadius = max(maxRadius, min(rightDist, leftDist));
        }

        return maxRadius;
    }
};
