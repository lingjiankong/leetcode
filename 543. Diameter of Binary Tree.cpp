// ***
//
// Given a binary tree, you need to compute the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may
// not pass through the root.
//
// Example:
// Given a binary tree
//           1
//          / \
//         2   3
//        / \
//       4   5
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
// ***
//
// This is exactly the same as 104. Maximum Depth of Binary Tree,
// with an added _diameter to track the diameter (leftMaxDepth + rightMaxDepth) of the tree.
//
// Very similar to 124. Binary Tree Maximum Path Sum
//
// Learning: generally in tree problems, if what you want to return in your recursion (max depth) needed for your
// calculation is not what the provided function returns (diameter), then you just should have another recursive
// function that returns the value you need (max depth), but tracks what the question asks for (diameter) internally.

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        _maxDepth(root);

        return _diameter;
    }

private:
    int _diameter = 0;

    int _maxDepth(TreeNode* root) {
        if (not root) {
            return 0;
        }

        int leftMaxDepth = _maxDepth(root->left);
        int rightMaxDepth = _maxDepth(root->right);

        _diameter = max(_diameter, leftMaxDepth + rightMaxDepth);

        return 1 + max(leftMaxDepth, rightMaxDepth);
    }
};
