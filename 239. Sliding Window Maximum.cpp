// ***
//
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
// 
// Example:
// 
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 
// 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
//
// ***
//
// 1. Brute force
// Time complexity: O((n – k) * k)
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	// Need to check for empty nums due to *max_element
	if (nums.empty())
	{
		return {};
	}

	vector<int> toReturn;
	
	for (int i = 0; i <= nums.size() - k; ++i)
	{
		int maxElement = *max_element(nums.begin() + i, nums.begin() + i + k);
		toReturn.push_back(maxElement);
	}

	return toReturn;
}

// 2. BST (multiset), the most intuitive solution.
// Time complexity: O((n – k + 1) * logk)
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> toReturn;
	multiset<int> window;

	for (int i = 0; i < nums.size(); ++i)
	{
		window.insert(nums[i]);

		// Initially, the window builds up, we just add elements to the multiset.
		// However, when we've reached a "full window", we start removing elements to the left
		// of the left bound of the sliding window.
		if (i - k + 1 >= 0)
		{
			// Iterator denoted by rbegin() is the biggest element in the multiset.
			toReturn.push_back(*window.rbegin());
			
			// Remove the element no longer in the window. 
			auto itr = window.find(nums[i - k + 1]);
			window.erase(itr);
		}
	}
		
	return toReturn; 
}

// 3. Monotonic priority queue (using deque as underlying data structure)
// Time complexity: O(n)
class MonotonicQueue
{

	public:

		// Push an element e to the priority queue.
		// All elements smaller than e will be popped from the queue,
		// so the queue will always be sorted in non-ascending order.
		// The underlying deque looks something like this: (9, 7, 7, 4, 1}
		void push(int e)
		{
			while (!mData.empty() && e > mData.back())
			{
				mData.pop_back();
			}

			mData.push_back(e);
		}

		// Pop the max element
		void popMax()
		{
			mData.pop_front();
		}

		// Peek the max element
		int peekMax() const
		{
			return mData.front();
		}
	
	private:
		
		deque<int> mData;

};

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> toReturn;
	MonotonicQueue q;

	for (int i = 0; i < nums.size(); ++i)
	{
		q.push(nums[i]);

		if (i - k + 1 >= 0)
		{
			toReturn.push_back(q.peekMax());

			if (nums[i-k+1] == q.peekMax())
			{
				q.popMax();
			}
		}
	}

	return toReturn;
}
