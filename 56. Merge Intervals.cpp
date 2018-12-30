// ***
//
// Given a collection of intervals, merge all overlapping intervals.
// 
// Example 1:
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
// Example 2:
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// Definition for an interval:
// struct Interval
// {
//    int start;
//    int end;
//    Interval() : start(0), end(0) {}
//    Interval(int s, int e) : start(s), end(e) {}
// };
//
// ***
//
// After sorting by Interval::start
//
// |__________|
//  |______|
//     |__________|
//                   |__________|
//                       |___________|
//                         |__|
//
vector<Interval> merge(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return a.start < b.start;});

	vector<Interval> mergedIntervals;

	for (auto interval : intervals)
	{
		// If mergedIntervals is empty, or if the start of current interval is greater than the end of last merged interval,
		// then add a brand new interval to merged interval.
		if (mergedIntervals.empty() || mergedIntervals.back().end < interval.start)
		{
			mergedIntervals.push_back(interval);
		}
		// Otherwise, merge two intervals.
		else
		{
			// Must take the max of last merged interval end and current interval end
			// in case last merged interval end is greater than current end (i.e. current interval is inside previously merged interval).
			mergedIntervals.back().end = max(mergedIntervals.back().end, interval.end);
		}
	}

	return mergedIntervals;
}
