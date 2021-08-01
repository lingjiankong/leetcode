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

// Multiset
// labuladong sliding window template
// Time complexity: O(n * logk)
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
            window.erase(window.lower_bound(num));
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

// Monotonic queue in descending order (using deque as the underlying data structure)
// (a monotonic queue is a data structure which elements is strictly increasing or decreasing)
// Time complexity: O(n)
class MonotonicQueue {
public:
    // Push an element e to the monotonic queue.
    // All elements smaller than e will be popped from the queue,
    // so the queue will always be sorted in non-ascending order,
    // with the largest element on the left and smallest element on the right.
    // The underlying deque looks something like this: (9, 7, 7, 4, 1}
    void push(int e) {
        while (not _data.empty() and e > _data.back()) {
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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;

        int left = 0, right = 0;
        vector<int> maximums;
        while (right < nums.size()) {
            int num = nums[right++];
            q.push(num);

            while (right - left == k) {
                maximums.push_back(q.peekMax());

                int num = nums[left++];
                // Only pop the max element from the monotonic queue if it equals to the element that we no longer need
                // in the window. There might be multiple max element with the samle value. We only pop one of them.
                if (num == q.peekMax()) {
                    q.popMax();
                }
            }
        }

        return maximums;
    }
};
