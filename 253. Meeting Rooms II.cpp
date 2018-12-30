// ***
//
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
// find the minimum number of conference rooms required.
// 
// Example 1:
// 
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// 
// Example 2:
// 
// Input: [[7,10],[2,4]]
// Output: 1
//
// Definition for an interval.
// struct Interval {
//       int start;
//       int end;
//       Interval() : start(0), end(0) {}
//       Interval(int s, int e) : start(s), end(e) {}
// };
//
// ***
//
// Appraoch: Sort both start and end.
//
// |__________|
//				|_______|
//					|__________|
//					  |__________|
//							|______|

int minMeetingRooms(vector<Interval>& intervals)
{
	vector<int> starts;
	vector<int> ends;

	for (auto interval : intervals)
	{
		starts.push_back(interval.start);
		ends.push_back(interval.end);
	}

	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	// end: index of current end
	// ends[end]: the earliest time when one of the meetings will end
	// There might be several meeting going on at the same time,
	// and we want the know when the earliest time one of the meetings will end,
	// so if a meeting has ended, we can put the meeting that starts now in that room which has been vacanted.
	int end = 0;

	// Total meeting rooms
	int total = 0;

	for (int i = 0; i < intervals.size(); ++i)
	{
		// No previous meeting room has been vacanted. Must open a new room.
		if (starts[i] < ends[end])
		{
			++total;
		}
		// If starts[i] >= ends[end], a meeting room has just been vacanted.
		// We can use that meeting room. ++end.
		else
		{
			++end;
		}
	}

	return total;
}

// Using priority_queue which stores the *end time* (the earliest end time has highest priority) of each meeting.
int minMeetingRooms(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) { return a.start < b.start; });
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto interval : intervals)
	{
		// Last meeting has ended, we can use that room, no need for extra room.
		if (!pq.empty() && pq.top() <= interval.start)
		{
			pq.pop();
		}

		pq.push(interval.end);
	}

	return pq.size();
}

