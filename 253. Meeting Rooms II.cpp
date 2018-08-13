// |__________|
//              |_______|
//                  |__________|
//                    |__________|
//                          |______|

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        vector<int> starts;
        vector<int> ends;

        for (auto interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int end = 0; // index of current end
        int total = 0; // total meeting rooms
        for (int i = 0; i < intervals.size(); ++i) {
            if (starts[i] < ends[end])
                ++total; // no previous meeting room has been vacanted. Must open a new room.
            else
                ++end; // if starts[i] >= ends[end], a meeting room has just been vacanted. We can use that meeting room. ++end.
        }
        return total;
    }
};
