// ***
//
// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two
// different nodes in the tree.
//
// ***

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return _minDiff;
    }

private:
    int _minDiff = INT_MAX;
    TreeNode* _prevNode = nullptr;

    void inorder(TreeNode* root) {
        if (not root) {
            return;
        }

        inorder(root->left);

        if (_prevNode) {
            _minDiff = min(_minDiff, root->val - _prevNode->val);
        }
        _prevNode = root;

        inorder(root->right);
    }
};

