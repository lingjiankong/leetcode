// ***
//
// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where
// each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the
// sum of the weight of those people is at most limit.
//
// Return the minimum number of boats to carry every given person.
//
//
// Example 1:
//
// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)
//
//
// Example 2:
//
// Input: people = [3,2,2,1], limit = 3
// Output: 3
// Explanation: 3 boats (1, 2), (2) and (3)
//
//
// Example 3:
//
// Input: people = [3,5,3,4], limit = 5
// Output: 4
// Explanation: 4 boats (3), (3), (4), (5)
//
//
// Constraints:
//
// 1 <= people.length <= 5 * 10^4
// 1 <= people[i] <= limit <= 3 * 10^4
//
// ***

// Intuition:
//
// If the heaviest person can share a boat with the lightest person, then do so. Otherwise, the heaviest person can't
// pair with anyone, so they get their own boat.
//
// The reason this works is because if the lightest person can pair with anyone, they might as well pair with the
// heaviest person.
//
// Algorithm:
//
// Let people[i] to the currently lightest person, and people[j] to the heaviest.
//
// Then, as described above, if the heaviest person can share a boat with the lightest person (if people[i] + people[j]
// <= limit) then do so; otherwise, the heaviest person sits in their own boat.

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());  // sort people's weight from light to heavy.
        int numBoats = 0;

        int i = 0, j = people.size() - 1;
        while (i <= j) {
            // Spare a new boat.
            ++numBoats;

            // If heaviest person can take the lightest person, then take him.
            if (people[i] + people[j] <= limit) {
                ++i;
            }

            // Heaviest person must go regardless (either by himself, or with the lightest person)
            --j;
        }

        return numBoats;
    }
};

