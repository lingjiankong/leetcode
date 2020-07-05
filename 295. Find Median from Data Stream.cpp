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
// Maintain two priority queues, _smaller stores the smaller half of all data, _larger stores the larger half.
// EITHER _smaller and _larger must have exactly the same length
// (when the total data is even -> median = (_smaller.top() + _larger.top()) / 2.0),
// OR, the length of _smaller must be only one greater than the length of _larger
// (when the total data is odd -> median = (double)_smaller.top().
//
// For exampe:
// _smaller: [1, 3, 5], _larger: [6, 8, 8] -> median = (5 + 6) / 2.0 = 5.5.
// _smaller: [4, 4, 6], _larger: [7, 8] -> median = 6.
class MedianFinder {
public:
    void addNum(int num) {
        // You should check which priority queue you want to push the number to.
        // If you blindy push everything to _smaller (or _larger) and hope to balance them later,
        // you might get something like [1, 3], [2], which is not the correct result.
        if (_smaller.empty() || num <= _smaller.top()) {
            _smaller.push(num);
        } else {
            _larger.push(num);
        }

        // Balance two priority queues.
        // We must always make sure that _smaller has either exactly the same elements as _larger,
        // (when total numbers are even), or _smaller has only one more element than _larger (when total numbers are
        // odd).
        if (_smaller.size() < _larger.size()) {
            _smaller.push(_larger.top());
            _larger.pop();
        } else if (_smaller.size() > _larger.size() + 1) {
            _larger.push(_smaller.top());
            _smaller.pop();
        }
    }

    double findMedian() {
        if ((_smaller.size() + _larger.size()) & 1) {
            return (double)_smaller.top();
        } else {
            return (_smaller.top() + _larger.top()) / 2.0;
        }
    }

private:
    // Default C++ priority queue is max queue using std::less<int> i.e. Max element has the highest priority.
    // Note the difference between priority_queue (implemented using heap, can only do operation on the top element).
    // and multiset (implemented using binary search tree has everything that priority queue offer and much more).
    // Here, we always need the max from the smaller half nums, therefore we use std::less<int>.
    priority_queue<int, vector<int>, less<int>> _smaller;

    // We always need the min from the larger half nums, therefore we use std::greater<int>.
    priority_queue<int, vector<int>, greater<int>> _larger;
};
