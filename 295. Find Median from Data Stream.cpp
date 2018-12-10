// ***
//
// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
// So the median is the mean of the two middle value.
// 
// For example,
// [2,3,4], the median is 3
// 
// [2,3], the median is (2 + 3) / 2 = 2.5
// 
// Design a data structure that supports the following two operations:
// 
// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
//  
// 
// Example:
// 
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
//
// ***
//
// Maintain two priority queues, mSmaller stores the smaller half of all data, mLarger stores the larger half. 
// EITHER mSmaller and mLarger must have exactly the same length
// (when the total data is even -> median = (mSmaller.top() + mLarger.top())/2.0),
// OR, the length of mSmaller must be only one greater than the length of mLarger
// (when the total data is odd -> median = (double)mSmaller.top().
//
// For exampe:
// mSmaller: [1, 3, 5], mLarger: [6, 8, 8] -> median = (5+6)/2.0 = 5.5.
// mSmaller: [4, 4, 6], mLarger: [7, 8] -> median = 6.
class MedianFinder
{

	public:

		void addNum(int num)
		{
			// You should check which priority queue you want to push the number to.
			// If you blindy push everything to mSmaller (or mLarger) and hope to balance them later,
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
		
		// Default C++ priority queue is max queue using std::less<int> i.e. Max element has the highest priority.
		// Note the difference between priority_queue (implemented using heap, can only do operation on the top element).
		// and multiset (implemented using binary search tree has everything that priority queue offer and much more).
		// Here, we always need the max from the smaller half nums, therefore we use std::less<int>.
		priority_queue<int, vector<int>, less<int>> mSmaller;
		
		// We always need the min from the larger half nums, therefore we use std::greater<int>.
		priority_queue<int, vector<int>, greater<int>> mLarger;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
