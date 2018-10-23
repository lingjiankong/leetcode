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

	vector<Interval> res;

	for (const auto& interval : intervals)
	{
		if (res.empty() || interval.start > res.back().end)
		{
			res.push_back(interval);
		}
		else
		{
			// Must take the max in case previous end is greater than current end
			res.back().end = max(res.back().end, interval.end);
		}
	}

	return res;
}
