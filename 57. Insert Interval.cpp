// ***
//
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
// Example 2:
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
// ***

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int insertPos = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) {
                // No overlap:
                // Right boundary of existing interval i is less than left boundary of new interval.
                ans.push_back(intervals[i]);
                ++insertPos;
            } else if (intervals[i][0] > newInterval[1]) {
                // No overlap:
                // Left boundary of existing interval i is greater than right boundary of new interval.
                ans.push_back(intervals[i]);
            } else {
                // In this case, new interval overlap with existing interval,
                // we form a new merged interval based on the boundaries of two intervals.
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        ans.insert(ans.begin() + insertPos, newInterval);
        return ans;
    }
};
