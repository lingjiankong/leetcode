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
// condition, and recursively check its left and right subtrees.

class Solution {
public:
    bool isValidBST(TreeNode* root) { return _preorder(root, nullptr, nullptr); }

private:
    bool _preorder(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (not root) {
            return true;
        }

        if (minNode and root->val <= minNode->val) {
            return false;
        }

        if (maxNode and root->val >= maxNode->val) {
            return false;
        }

        return _preorder(root->left, minNode, root) and _preorder(root->right, root, maxNode);
    }
};

// In order traversal of a binary search tree gives ascending order.
class Solution {
public:
    bool isValidBST(TreeNode* root) { return _inorder(root); }

private:
    TreeNode* _prevNode = nullptr;

    // Returns false if during in order traversal we do not see elements in ascending order.
    bool _inorder(TreeNode* root) {
        if (not root) {
            return true;
        }

        if (not _inorder(root->left)) {
            return false;
        }

        if (_prevNode and _prevNode->val >= root->val) {
            return false;
        }
        _prevNode = root;

        return _inorder(root->right);
    }
};
