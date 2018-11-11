// Maintain two priority queues, mSmaller stores the smaller half of all data,
//
// mLarger stores the larger half. mSmaller and mLarger must have exactly the same length
// (when the total data is even -> median = (mSmaller.top() + mLarger.top())/2.0),
// OR, the length of mSmaller must be only one greater than the length of mLarger
// (when the total data is odd -> median = (double)mSmaller.top().
// For exampe:
// mSmaller: [1, 3, 5], mLarger: [6, 8, 8] -> median = (5+6)/2.0 = 5.5.
// mSmaller: [4, 4, 6], mLarger: [7, 8] -> median = 6.
class MedianFinder
{

	public:

		void addNum(int num)
		{
			// Must do this here. If you blindy push everything to mSmaller and hope to balance them later,
			// you might get something like [1, 3], [2], which is not the correct result.
			if (mSmaller.empty() || num <= mSmaller.top())
			{
				mSmaller.push(num);
			}
			else
			{
				mLarger.push(num);
			}
			
			// Balance two priority queues.
			// We must always make sure that mSmaller has either exactly the same elements as mLarger,
			// (when total numbers are even), or mSmaller has only one more element than mLarger (when total numbers are odd).
			if (mSmaller.size() < mLarger.size())
			{
				mSmaller.push(mLarger.top());
				mLarger.pop();
			}
			else if (mSmaller.size() > mLarger.size() + 1)
			{
				mLarger.push(mSmaller.top());
				mSmaller.pop();
			}
		}

		double findMedian()
		{
			if ((mSmaller.size() + mLarger.size()) & 1)
			{
				return (double)mSmaller.top();
			}
			else
			{
				return (mSmaller.top() + mLarger.top())/2.0;
			}
		}

	private:
		
		// Default C++ priority queue is max queue using std::less<int>
		// i.e. Max element has the highest priority
		priority_queue<int, vector<int>, less<int>> mSmaller;

		priority_queue<int, vector<int>, greater<int>> mLarger;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
