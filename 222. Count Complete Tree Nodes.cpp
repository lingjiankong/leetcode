// ***
//
// Given a complete binary tree, count the number of nodes.
//
// Note:
//
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last
// level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//
// Example:
//
// Input:
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
//
// Output: 6
//
// ***
//
// We are already told that the tree is complete, so if there's any difference in depth,
// then there's at most one. We traverse all the way to the left most node, and traverse all the way to the right most
// node, and see the difference in depth. If same, then it is a perfect tree, return 2 ^ depth - 1. Otherwise,
// recursively traverse the left and right subtrees and see if the subtrees are perfect trees.

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }

    TreeNode *left = root, *right = root;
    int heightLeft = 0, heightRight = 0;

    while (left) {
        ++heightLeft;
        left = left->left;
    }

    while (right) {
        ++heightRight;
        right = right->right;
    }

    // If left most node and right most node has the same height, it is a perfect binary tree.
    if (heightLeft == heightRight) {
        return pow(2, heightLeft) - 1;
    }

    // Otherwise, count node like you would normally for vanilla binary tree.
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Same idea. Clearer.
class Solution {
public:
    int countNodes(TreeNode* root) {
        int leftHeight = _getLeftSubtreeHeight(root);
        int rightHeight = _getRightSubtreeHeight(root);

        if (leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int _getLeftSubtreeHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + _getLeftSubtreeHeight(root->left);
    }

    int _getRightSubtreeHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + _getRightSubtreeHeight(root->right);
    }
};
