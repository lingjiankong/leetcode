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

// The idea is very simple. For each house, you find the two heaters that are next to it (using binary search).
// You compare the distance between heater and the house. Final radius of the heater is the maximum distance ever seen.
// You need to pay special attention when pos = heaters.begin() or pos = heaters.end().
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxRadius = 0;
        sort(heaters.begin(), heaters.end());

        for (int house : houses) {
            // Find the first heater position that is no less than house position.
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            int nextHeaderToHouseDistance = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int prevHeaderToHourDistance = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);
            maxRadius = max(maxRadius, min(nextHeaderToHouseDistance, prevHeaderToHourDistance));
        }

        return maxRadius;
    }
};

// Wtih binary search implementation instead of built-in std::lower_bound()
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxRadius = 0;
        sort(heaters.begin(), heaters.end());

        for (int house : houses) {
            int left = 0, right = heaters.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            int nextHeaderToHouseDistance = (right == heaters.size()) ? INT_MAX : heaters[right] - house;
            int prevHeaterToHouseDistance = (right == 0) ? INT_MAX : house - heaters[right - 1];
            maxRadius = max(maxRadius, min(nextHeaderToHouseDistance, prevHeaterToHouseDistance));
        }

        return maxRadius;
    }
};
