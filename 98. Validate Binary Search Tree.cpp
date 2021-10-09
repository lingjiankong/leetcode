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

// Postorder
class Solution {
public:
    bool isValidBST(TreeNode* root) { return _postorder(root, LONG_MIN, LONG_MAX); }

private:
    bool _postorder(TreeNode* root, long minVal, long maxVal) {
        if (not root) {
            return true;
        }

        bool isLeftValid = _postorder(root->left, minVal, root->val);
        bool isRightValid = _postorder(root->right, root->val, maxVal);

        return isLeftValid and isRightValid and minVal < root->val and root->val < maxVal;
    }
};

// Preorder
class Solution {
public:
    bool isValidBST(TreeNode* root) { return _preorder(root, LONG_MIN, LONG_MAX); };

private:
    bool _preorder(TreeNode* root, long minVal, long maxVal) {
        if (not root) {
            return true;
        }

        if (root->val <= minVal) {
            return false;
        }

        if (root->val >= maxVal) {
            return false;
        }

        return _preorder(root->left, minVal, root->val) and _preorder(root->right, root->val, maxVal);
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
