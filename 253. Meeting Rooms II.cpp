// |__________|
//				|_______|
//					|__________|
//					  |__________|
//							|______|

/**
 * Definition for an interval.
 * struct Interval {
 *	   int start;
 *	   int end;
 *	   Interval() : start(0), end(0) {}
 *	   Interval(int s, int e) : start(s), end(e) {}
 * };
 */
int minMeetingRooms(vector<Interval>& intervals)
{

	vector<int> starts;
	vector<int> ends;

	for (const auto& interval : intervals)
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
