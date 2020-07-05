// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So
// the median is the mean of the two middle value.
//
// Examples:
// [2,3,4] , the median is 3
//
// [2,3], the median is (2 + 3) / 2 = 2.5
//
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very
// right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your
// job is to output the median array for each window in the original array.
//
// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
// Window position                Median
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
// Therefore, return the median sliding window as [1,-1,-1,3,5,6].
//
// Note:
// You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
// Answers within 10^-5 of the actual value will be accepted as correct.

// Straightforward solution using a multiset, not efficient because mid iterator needs to be recalculated every time..
// You can optimize the code to track mid iterator depending on the value of element to be inserted and removed.
// However it turns out to be very buggy incrementing and decrementing mid iterator, while keep adding element and
// popping element from the multiset (for example, what happens if the element to be removed is the current mid iterator
// itself), even altough the idea seems to be super simple. I have spent couple hours on it, so don't get yourself into
// the rabbit hole.
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> listOfMedians;
        multiset<double> window(nums.begin(), nums.begin() + k);
        for (int i = k;; ++i) {
            auto mid = std::next(window.begin(), k / 2);
            if (k & 1) {
                listOfMedians.push_back(*mid);
            } else {
                listOfMedians.push_back((*mid + *std::prev(mid, 1)) / 2);
            }

            // Return when i == nums.size(), meaning we have calculated the medians for all windows, return.
            // Otherwise, add new element to window and remove leftmost element from window and keep calculating.
            if (i == nums.size()) {
                return listOfMedians;
            }

            window.insert(nums[i]);
            window.erase(window.lower_bound(nums[i - k]));
        }
    }
};

// Very similar to 295. Find Median from Data Stream
// Maintain two multiset to keep track of the smaller half and larger half of data
// EITHER small and large must have exactly the same length,
// OR the length of small must be only one greater than the length of large.
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> listOfMedians;
        multiset<int> small, large;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k])) {
                    small.erase(small.find(nums[i - k]));
                } else if (large.count(nums[i - k])) {
                    large.erase(large.find(nums[i - k]));
                }
            }
            if (small.size() <= large.size()) {
                if (large.empty() || nums[i] <= *large.begin()) {
                    small.insert(nums[i]);
                } else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            } else {
                // In this case, small has exactly one more element than large
                // so we must insert the new element to large.
                if (nums[i] >= *small.rbegin()) {
                    large.insert(nums[i]);
                } else {
                    large.insert(*small.rbegin());
                    // To erase the biggest element in small, we erase --small.end() because small.end() isn't pointing
                    // to any element. We can't use rbegin() here because it does not work with erase()
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            if (i >= (k - 1)) {
                if (k & 1) {
                    listOfMedians.push_back(*small.rbegin());
                } else {
                    listOfMedians.push_back(((double)*small.rbegin() + *large.begin()) / 2);
                }
            }
        }
        return listOfMedians;
    }
};
