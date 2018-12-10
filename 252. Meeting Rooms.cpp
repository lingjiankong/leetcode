// ***
//
// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//
// Example 1:
//
// Input: [[0,30],[5,10],[15,20]]
// Output: false
//
// Example 2:
//
// Input: [[7,10],[2,4]]
// Output: true
//
// ***
//
// This question is same as asking whether there are overlapping intervals.
//
// Examples:
//
// After sorted by Interval::start
//
// Can't attend all meetings
// |__________|
//  |______|
//   |__________|
//                  |__________|
//                       |___________|
//                         |__|
//
// Can attend all meetings
// |__________|
//               |______|
//                        |__________|
//
bool canAttendMeetings(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) {return a.start < b.start;});

	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i-1].end > intervals[i].start)
		{
			return false;
		}
	}

	return true;
}
