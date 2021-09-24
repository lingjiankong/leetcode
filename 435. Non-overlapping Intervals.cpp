// ***
//
// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you
// need to remove to make the rest of the intervals non-overlapping.
//
//
// Example 1:
//
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
//
// Example 2:
//
// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
//
// Example 3:
//
// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
//
// ***
//
// Greedy.
// This is a typical "Interval Scheduling" type of question. See labuladong book 382
// The question can be rephrased as: given intervals, find the max number of events you can attend (maxEvents).
// Therefore the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping is
// just intervals.size() - maxEvents
//
// Sort intervals based on end time. Traverse intervals, whenever you see start time >= current end time, ++maxEvents.
//    |--------| <- first event
// |-----------.-----|
//      |------.--------|
//             . |---------| <- second event
//             ^ ^     |------|
//             ^ ^  |------------|
//           end start
              
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1] or (a[1] == b[1] and a[0] < b[0]); });

        int maxEvents = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            int start = intervals[i][0];
            if (start >= end) {
                end = intervals[i][1];  // end of current interval becomes the new end.
                ++maxEvents;
            }
        }

        return intervals.size() - maxEvents;
    }
};
