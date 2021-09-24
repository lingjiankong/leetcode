// ***
//
// You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat,
// and seats[i] = 0 represents that the ith seat is empty (0-indexed).
//
// There is at least one empty seat, and at least one person sitting.
//
// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
//
// Return that maximum distance to the closest person.
//
//
// Example 1:
//
// Input: seats = [1,0,0,0,1,0,1]
// Output: 2
// Explanation:
// If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
//
//
// Example 2:
//
// Input: seats = [1,0,0,0]
// Output: 3
// Explanation:
// If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.
//
//
// Example 3:
//
// Input: seats = [0,1]
// Output: 1
//
//
// Constraints:
//
// 2 <= seats.length <= 2 * 10^4
// seats[i] is 0 or 1.
// At least one seat is empty.
// At least one seat is occupied.
//
// ***

// See also 855. Exam Room.
//
// Traverse from left to right to find all seats with someone sitting.
// The max distance between two people is to sit in the middle.
// Note that we need to handle cases where we sit right next to the left wall and the right wall.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), res = 0;
        vector<int> nums;

        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                nums.push_back(i);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                // Sit next to left wall
                res = max(res, nums[0]);
            } else {
                // Sit in between two people
                res = max(res, (nums[i] - nums[i - 1]) / 2);
            }
        }

        // Sit next to right wall
        res = max(res, (n - 1) - nums.back());

        return res;
    }
};

// Same idea, traverse once.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prevIdx = -1;  // index of previous seat which has been taken.
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i] != 1) {
                continue;
            }
            if (prevIdx == -1) {
                res = max(res, i);  // sit next to left wall
            } else {
                res = max(res, (i - prevIdx) / 2);  // sit in the middle
            }

            prevIdx = i;
        }

        res = max(res, (n - 1) - prevIdx);  // sit next to right wall

        return res;
    }
};
