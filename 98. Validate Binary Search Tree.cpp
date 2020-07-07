// ***
//
// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:
//
// Input:
//     2
//    / \
//   1   3
// Output: true
//
// Example 2:
//
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.
//
// ***
//
// For a binary search tree, all nodes in left subtree must be smaller than current node, and all nodes in right subtree
// must be larger than current node. Therefore we can use preorder traversal to see whether a node satisfy this
// condition, and recursively check its left and right subtrees. If you do not want to hard code things like INT_MIN or
// INT_MAX, then you can use use nullptr, because the root node does not have any constraint on the min and max value it
// can take. For clarity we use INT_MAX here. This won't pass the OJ.

class Solution {
public:
    bool isValidBST(TreeNode* root) { return _preorder(root, INT_MIN, INT_MAX); }

private:
    bool _preorder(TreeNode* node, int minValue, int maxValue) {
        if (!node) {
            return true;
        }

        if ((node->val <= minValue) || (node->val >= maxValue)) {
            return false;
        }

        return _preorder(node->left, minValue, node->val) && _preorder(node->right, node->val, maxValue);
    }
};

// In order traversal of a binary search tree gives ascending order.
class Solution {
public:
    bool isValidBST(TreeNode* root) { return _inorder(root); }

private:
    TreeNode* _prevNode = nullptr;

    // Returns false if during in order traversal we do not see elements in ascending order.
    bool _inorder(TreeNode* node) {
        if (!node) {
            return true;
        }

        if (!_inorder(node->left)) {
            return false;
        }

        if (_prevNode && _prevNode->val >= node->val) {
            return false;
        }
        _prevNode = node;

        return _inorder(node->right);
    }
};
