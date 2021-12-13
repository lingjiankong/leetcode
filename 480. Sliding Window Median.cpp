// ***
//
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
//
// ***

// Window is almost the same as 295. Find Median from Data Stream.
// We replace priority_queue with multiset because we need to be able to erase element (removeNum)
class Window {
public:
    void addNum(int num) {
        if (_smaller.empty() or num <= *(_smaller.rbegin())) {
            _smaller.insert(num);
        } else {
            _larger.insert(num);
        }

        balance();
    }

    void removeNum(int num) {
        if (_smaller.count(num)) {
            _smaller.erase(_smaller.lower_bound(num));
        } else if (_larger.count(num)) {
            _larger.erase(_larger.lower_bound(num));
        }

        balance();
    }

    double findMedian() {
        if ((_smaller.size() + _larger.size()) & 1) {
            return (double)(*_smaller.rbegin());
        } else {
            return (*_smaller.rbegin() + *_larger.begin()) / 2.0;
        }
    }

    void balance() {
        if (_smaller.size() < _larger.size()) {
            _smaller.insert(*_larger.begin());
            _larger.erase(_larger.begin());
        } else if (_smaller.size() > _larger.size() + 1) {
            _larger.insert(*(_smaller.rbegin()));
            _smaller.erase(--_smaller.end());  // can't erase _smaller.rbegin(). Has to use forward itr
        }
    }

    size_t size() { return _smaller.size() + _larger.size(); }

private:
    multiset<long> _smaller;
    multiset<long> _larger;
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        Window window;

        int left = 0, right = 0;
        while (right < nums.size()) {
            int num = nums[right++];
            window.addNum(num);

            while (window.size() == k) {
                ans.push_back(window.findMedian());

                int num = nums[left++];
                window.removeNum(num);
            }
        }

        return ans;
    }
};

