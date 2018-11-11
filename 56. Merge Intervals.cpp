// |__________|
//  |______|
//     |__________|
//                   |__________|
//                       |___________|
//                         |__|

/*
 * Definition for an interval:
 * struct Interval
 * {
 *	   int start;
 *	   int end;
 *	   Interval() : start(0), end(0) {}
 *	   Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> merge(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) {return a.start < b.start;});

	vector<Interval> mergedIntervals;

	for (auto interval : intervals)
	{
		// If mergedIntervals is empty, or
		// if the start of current interval is greater than the end of last merged interval,
		// then we shall start a brand new interval.
		if (mergedIntervals.empty() || interval.start > mergedIntervals.back().end)
		{
			mergedIntervals.push_back(interval);
		}
		else
		{
			// Must take the max in case previous end is greater than current end.
			mergedIntervals.back().end = max(mergedIntervals.back().end, interval.end);
		}
	}

	return mergedIntervals;
}
