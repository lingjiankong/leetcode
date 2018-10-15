class Solution
{

	public:

		bool increasingTriplet(vector<int>& nums) {

			int min = INT_MAX; // Most minimum element
			int secondMin = INT_MAX; // Second most minimum element

			// Note: <= (not <) is important, because we want increasing orders. 
			// If we want non-decreasing orders, we can do <
			for (int num : nums)
			{
				if (num <= min)
				{
					// num is the most minimum element seen so far
					min = num;
				}
				else if (num <= secondMin)
				{
					// num is the second most minimum element seen so far
					// If we enter this else if loop, then we are guaranteed that there exists 
					// the most minimum element (min) that occurs before num (now secondMin)
					secondMin = num;
				}
				else
				{
					// Same logic, now we are guaranteed that there are two increasing elements which
					// occured before num. We found increasing triplet, simply return true.
					return true; 
				}
			}

			return false;
		}
};
