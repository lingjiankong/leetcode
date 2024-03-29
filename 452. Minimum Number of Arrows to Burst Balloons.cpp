// ***
//
// There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and
// end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the
// x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.
//
// An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend
// bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An
// arrow once shot keeps traveling up infinitely.
//
// Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to
// burst all balloons.
//
//
// Example 1:
//
// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another
// arrow at x = 11 (bursting the other two balloons). Example 2:
//
// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
//
//
// Example 3:
//
// Input: points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
//
// ***

// Find the max number of non-overlapping interval. You need one arrow for each interval.
// Almost exactly the same as 435. Non-overlapping Intervals.
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1] or (a[1] == b[1] and a[0] < b[0]); });

        int res = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            int start = points[i][0];
            // According to the question statement, if start == end then two intervals can still be bursted by the same
            // arrow. Therefore we use if (start > end) instead of if (start >= end)
            if (start > end) {
                end = points[i][1];
                ++res;
            }
        }

        return res;
    }
};

