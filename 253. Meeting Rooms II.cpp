// ***
//
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the
// minimum number of conference rooms required.
//
// Example 1:
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
//
// Example 2:
// Input: [[7, 10],[2, 4]]
// Output: 1
//
// ***

// Using tree map.
// Traverse through the intervals. For every start time, you need one additional room; for every end time, you vacate
// one room. If start time and end time overlap, the net room change is zero. timeToNewRoomsNeeded[i] is additional room
// you need at time i (can also be negative, which means you've vacated rooms). In the end, traverse through all the
// time (i.e. whenever you start or end a meeting), clculate how many rooms you need to use at each time, and keep track
// of the max rooms you need.
int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> timeToNewRoomsNeeded;

    for (auto interval : intervals) {
        ++timeToNewRoomsNeeded[interval[0]];
        --timeToNewRoomsNeeded[interval[1]];
    }

    int currentRooms = 0, maxRooms = 0;
    for (auto element : timeToNewRoomsNeeded) {
        currentRooms += element.second;
        maxRooms = max(maxRooms, currentRooms);
    }

    return maxRooms;
}

// Sort both start and end.
//
// |__________|
//				|_______|
//					|__________|
//					  |__________|
//							|______|
//
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> startTimes;
    vector<int> endTimes;

    for (auto interval : intervals) {
        startTimes.push_back(interval[0]);
        endTimes.push_back(interval[1]);
    }

    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    // endTimes[endIndex]: the earliest time when one of the meetings will end
    // There might be several meeting going on at the same time, and we want to know when the earliest time one of the
    // meetings will end, so if a meeting has ended, we can put the meeting that starts now in that room which has just
    // been vacanted.
    int endIndex = 0;

    int totalRooms = 0;

    for (int i = 0; i < intervals.size(); ++i) {
        // No previous meeting room has been vacanted. Must open a new room.
        if (startTimes[i] < endTimes[endIndex]) {
            ++totalRooms;
        }
        // If startTimes[i] >= endTimes[endIndex], a meeting room has just been vacanted.
        // We can use that meeting room. ++endIndex.
        else {
            ++endIndex;
        }
    }

    return totalRooms;
}

// Use priority queue
int minMeetingRooms(vector<vector<int>>& intervals) {
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    // Using priority_queue to store the *end time* (the earliest end time has highest priority) of each meeting.
    priority_queue<int, vector<int>, greater<int>> pqEndTimes;

    for (auto interval : intervals) {
        // If pqEndTimes.top() (earliest end time of exisiting meetings) <= interval[0] (start time of current meeting),
        // then there's a meeting that has just ended, in which case we can use that vacanted room. No need for extra
        // room.
        if (!pqEndTimes.empty() && pqEndTimes.top() <= interval[0]) {
            pqEndTimes.pop();
        }

        // Regardless of using previously vacanted room or open a new room, we need to push the end time of current
        // meeting to the priority queue
        pqEndTimes.push(interval[1]);
    }

    // Explanation why pdEndTimes.size() is the minimum number of meeting rooms:
    // Every time your new meeting can use a previously vacanted room, you pop the earliest end time out, and you push
    // the end time for your new meeting in (pq size -1 (pop), then +1 (push)). However when you do not have a vancated
    // room to use, you only push the end time for your new meeting in without poping any end time out (pq size +1
    // (push)). So in the end the size of pq tracks the total number of meeting rooms you have opened when you've
    // finished traversing all the meetings.
    return pqEndTimes.size();
}

