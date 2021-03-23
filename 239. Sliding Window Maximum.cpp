// ***
//
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very
// right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return
// the max element in the sliding window.
//
// Example:
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7]
//
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

// labuladong sliding window template
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window;

    int left = 0, right = 0;
    vector<int> res;

    while (right < nums.size()) {
        int num = nums[right++];
        window.insert(num);

        while (window.size() == k) {
            res.push_back(*window.rbegin());

            int num = nums[left++];
            // need to use lower_bound here, otherwise multiple elements of the same value will be erased.
            window.erase(lower_bound(num));
        }
    }

    return res;
}

// Brute force
// Time complexity: O((n – k) * k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maximums;

    for (int i = 0; i <= nums.size() - k; ++i) {
        int maxElement = *max_element(nums.begin() + i, nums.begin() + i + k);
        maximums.push_back(maxElement);
    }

    return maximums;
}

// BST (multiset), the most intuitive solution.
// Time complexity: O((n – k + 1) * logk)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maximums;
    multiset<int> window;

    for (int i = 0; i < nums.size(); ++i) {
        window.insert(nums[i]);

        // Initially, the window builds up, we just add elements to the multiset. However, when we've reached a "full
        // window", we start removing elements to the left of the left bound of the sliding window. Here, i - k is the
        // element to the left of the left bound of the current window, i - k + 1 is therefore the first element in
        // current window. We first calculate the max value in current window by getting the biggest element denoted by
        // rbegin() and push the result to maximums. After this is done, the first element in the window is no longer
        // needed, and we thus erase that element from the multiset.
        if (i - k + 1 >= 0) {
            // Iterator denoted by rbegin() is the biggest element in the multiset.
            maximums.push_back(*window.rbegin());

            // Remove the element no longer needed in the window.
            auto itr = window.find(nums[i - k + 1]);
            window.erase(itr);
        }
    }

    return maximums;
}

// Monotonic queue in non-ascending order (using deque as underlying data structure)
// A monotonic queue is a data structure the elements from the front to the end is strictly either increasing or
// decreasing.
// Time complexity: O(n)
class MonotonicQueue {
public:
    // Push an element e to the monotonic queue.
    // All elements smaller than e will be popped from the queue,
    // so the queue will always be sorted in non-ascending order,
    // with the largest element on the left and smallest element on the right.
    // The underlying deque looks something like this: (9, 7, 7, 4, 1}
    void push(int e) {
        while (!_data.empty() && e > _data.back()) {
            _data.pop_back();
        }

        _data.push_back(e);
    }

    // Pop the max element
    void popMax() { _data.pop_front(); }

    // Peek the max element
    int peekMax() const { return _data.front(); }

private:
    deque<int> _data;
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maximums;
    MonotonicQueue q;

    for (int i = 0; i < nums.size(); ++i) {
        q.push(nums[i]);

        if (i - k + 1 >= 0) {
            maximums.push_back(q.peekMax());

            // Only pop the max element if it equals to the element that we no longer need in the window.
            // There might be multiple max element with the samle value. We only pop one of them.
            if (nums[i - k + 1] == q.peekMax()) {
                q.popMax();
            }
        }
    }

    return maximums;
}

