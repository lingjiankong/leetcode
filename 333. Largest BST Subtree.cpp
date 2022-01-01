// ***
//
// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with
// largest number of nodes in it.
//
// Note:
// A subtree must include all of its descendants.
//
// Example:
//
// Input: [10,5,15,1,8,null,7]
//
//    10
//    / \
//   5  15
//  / \   \
// 1   8   7
//
// Output: 3
// Explanation: The Largest BST Subtree in this case is the highlighted one.
//              The return value is the subtree's size, which is 3.
//
// ***

// This is not the optimized solution, but is very clear.
// See also 98. Validate Binary Search Tree.
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // Because we are using preorder traversal, the first time you see a valid BST it is
        // guaranteed to be the largest BST among its subtrees, simply return the number of nodes.
        if (_isValidBST(root, INT_MIN, INT_MAX)) {
            return _countNodes(root);
        }

        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }

private:
    bool _isValidBST(TreeNode* root, int minValue, int maxValue) {
        if (not root) {
            return true;
        }

        if (root->val <= minValue or root->val >= maxValue) {
            return false;
        }

        return _isValidBST(root->left, minValue, root->val) and _isValidBST(root->right, root->val, maxValue);
    }

    int _countNodes(TreeNode* root) {
        if (not root) {
            return 0;
        }

        return 1 + _countNodes(root->left) + _countNodes(root->right);
    }
};
