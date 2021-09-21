// ***
//
// You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may
// also be integers or other lists. Implement an iterator to flatten it.
//
// Implement the NestedIterator class:
//
// NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
// int next() Returns the next integer in the nested list.
// boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
// Your code will be tested with the following pseudocode:
// // initialize iterator with nestedList // res = []
// while iterator.hasNext()
//     append iterator.next() to the end of res
// return res
// If res matches the expected flattened list, then your code will be judged as correct.
//
//
// Example 1:
//
// Input: nestedList = [[1,1],2,[1,1]]
// Output: [1,1,2,1,1]
// Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should
// be: [1,1,2,1,1].
//
//
// Example 2:
//
// Input: nestedList = [1,[4,[6]]]
// Output: [1,4,6]
// Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should
// be: [1,4,6].
//
//
// Constraints:
//
// 1 <= nestedList.length <= 500
// The values of the integers in the nested list is in the range [-106, 106].
//
// ***

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Pre-generate all elements during construction.
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for (auto child : nestedList) {
            _traverse(child);
        }
    }

    int next() {
        int res = _list.front();
        _list.pop_front();
        return res;
    }

    bool hasNext() { return not _list.empty(); }

private:
    list<int> _list;

    // N-tree preorder traversal.
    // root is leaf node if it is an integer. If root contains a list then root has children.
    // We are only interested in leaf node (integer).
    void _traverse(NestedInteger& root) {
        // Only put leaf node (integer) into list.
        if (root.isInteger()) {
            _list.push_back(root.getInteger());
            return;
        }

        for (auto child : root.getList()) {
            _traverse(child);
        }
    }
};

// Generate next element during runtime
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for (int i = 0; i < nestedList.size(); ++i) {
            _dq.push_back(nestedList[i]);
        }
    }

    int next() {
        int res = _dq.front().getInteger();
        _dq.pop_front();
        return res;
    }

    bool hasNext() {
        while (not _dq.empty()) {
            NestedInteger cur = _dq.front();
            if (cur.isInteger()) {
                return true;
            }

            _dq.pop_front();
            vector<NestedInteger>& children = cur.getList();
            for (int i = 0; i < children.size(); ++i) {
                // Note the sequence of insertion.
                _dq.insert(_dq.begin() + i, children[i]);
            }
        }
        return false;
    }

private:
    deque<NestedInteger> _dq;
};

