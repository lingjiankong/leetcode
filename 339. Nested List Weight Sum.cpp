// ***
//
// Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
//
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
// Example 1:
//
// Input: [[1,1],2,[1,1]]
// Output: 10
// Explanation: Four 1's at depth 2, one 2 at depth 1.
// Example 2:
//
// Input: [1,[4,[6]]]
// Output: 27
// Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.
//
// ***

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;

        for (auto& node : nestedList) {
            res += preorder(node, 1);
        }

        return res;
    }

private:
    int preorder(NestedInteger& root, int level) {
        if (root.isInteger()) {
            return level * root.getInteger();
        }

        int res = 0;
        for (auto& child : root.getList()) {
            res += preorder(child, level + 1);
        }

        return res;
    }
};

// Same idea, maintain global variable.
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        for (auto& node : nestedList) {
            preorder(node, 1);
        }

        return _res;
    }

private:
    int _res = 0;

    void preorder(NestedInteger& root, int level) {
        if (root.isInteger()) {
            _res += level * root.getInteger();
        }

        for (auto& child : root.getList()) {
            preorder(child, level + 1);
        }
    }
};
