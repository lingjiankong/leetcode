// 1. Brute force
// Time complexity: O((n – k + 1) * k)
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> ans;
	
	// i is the right most element of the sliding window.
	// i.e. i+1 is the right bound of the sliding window.
	for (int i = k - 1; i < nums.size(); ++i)
	{
		int maxElement = *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1);
		ans.push_back(maxElement);
	}

	return ans;
}

// 2. B.S.T. (multiset)
// Time complexity: O((n – k + 1) * logk)
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> ans;
	multiset<int> window;

	for (int i = 0; i < nums.size(); ++i)
	{
		window.insert(nums[i]);

		// When we've reached a "full window", we start removing elements to the left
		// of the left bound of the sliding window.
		if (i - k + 1 >= 0)
		{
			// Iterator denoted by rbegin() is the biggest element in the multiset.
			ans.push_back(*window.rbegin())	
			
			// Remove the element no longer in the window. 
			auto itr = window.find(nums[i-k+1]);
			if (itr != window.end())
			{
				window.erase(itr);
			}
		}
	}
		
	return ans; 
}

// 3. Monotonic priority queue
// Time complexity: O(n)
class MonotonicQueue
{

	public:

		// Push an element to the priority queue.
		// All elements smaller than e will be popped from the queue.
		// The queue will always be sorted in non-increasing order.
		void push(int e)
		{
			while (!mData.empty() && e > mData.back())
			{
				mData.pop_back();
			}
			mData.push_back(e);
		}

		// Pop the max element
		void pop()
		{
			mData.pop_front();
		}

		// Peek the max element
		int max() const
		{
			return mData.front();
		}
	
	private:
		
		deque<int> mData;

};

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> ans;
	MonotonicQueue q;

	for (int i = 0; i < nums.size(); ++i)
	{
		q.push(nums[i]);

		if (i - k + 1 >= 0)
		{
			ans.push_back(q.max());

			if (nums[i-k+1] == q.max())
			{
				q.pop();
			}
		}
	}

	return ans;
}
