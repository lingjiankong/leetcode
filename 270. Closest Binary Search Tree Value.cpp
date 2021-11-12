// ***
//
// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
// Note:
//
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.
// Example:
//
// Input: root = [4,2,5,1,3], target = 3.714286
//
//     4
//    / \
//   2   5
//  / \
// 1   3
//
// Output: 4
//
// ***

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        helper(root, target);
        return _closestNodeVal;
    }

private:
    void helper(TreeNode* root, double target) {
        if (not root) {
            return;
        }

        if (abs(root->val - target) < _closest) {
            _closest = abs(root->val - target);
            _closestNodeVal = root->val;
        }

        if (root->val > target) {
            closestValue(root->left, target);
        } else {
            closestValue(root->right, target);
        }
    }

    double _closest = DBL_MAX;

    int _closestNodeVal = 0;
};
