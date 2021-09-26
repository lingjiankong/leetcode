// ***
//
// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its depth = 3.
//
// ***
//
// Compare this one with 111. Minimum Depth of Binary Tree.

// Postorder traversal.
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftSubtreeMaxDepth = maxDepth(root->left);
    int rightSubtreeMaxDepth = maxDepth(root->right);
    int currentTreeMaxDepth = 1 + max(leftSubtreeMaxDepth, rightSubtreeMaxDepth);

    return currentTreeMaxDepth;
}

// Same thing.
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// DFS, maintain global variable.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        _dfs(root, 1);

        return _maxDepth;
    }

private:
    void _dfs(TreeNode* root, int depth) {
        if (not root) {
            return;
        }

        _maxDepth = max(_maxDepth, depth);
        _dfs(root->left, depth + 1);
        _dfs(root->right, depth + 1);
    }

    int _maxDepth = 0;
};
