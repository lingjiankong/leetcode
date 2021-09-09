// ***
//
// Given a binary tree, find the length of the longest path where each root in the path has the same value. This path
// may or may not pass through the root. Note: The length of path between two nodes is represented by the number of
// edges between them.
//
// Example 1:
// Input:
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:
// 2
//
// Example 2:
// Input:
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:
// 2
//
// ***
//
// Pay attention to the following terms:
// Depth: number of nodes, can only go from parent to child.
// Height (or length): number of edges connecting nodes, can only go from parent to child.
// Path: number of edges connecting nodes, doesn't necessarily go from parent to child.
//
// This is a postorder traversal problem because we need the information from both left and right subtrees
// and compare them to current root node.
//
// See also 124. Binary Tree Maximum Path Sum. The structure is very similar.

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        _maxUnivalueDepth(root);

        return _longestPath;
    }

private:
    int _longestPath = 0;

    int _maxUnivalueDepth(TreeNode* root) {
        if (not root) {
            return 0;
        }

        int leftMaxUnivalDepth = _maxUnivalueDepth(root->left);
        int rightMaxUnivalDepth = _maxUnivalueDepth(root->right);

        // Reset maxUnival of a subtree if its values != the value of our current root.
        if (root->left and root->val != root->left->val) {
            leftMaxUnivalDepth = 0;
        }

        if (root->right and root->val != root->right->val) {
            rightMaxUnivalDepth = 0;
        }

        // Note: we are interested in path (i.e. number of edges, instead of number of nodes),
        // so we just need to compare current _longestPath with leftMaxUnivalDepth + rightMaxUnivalDepth
        _longestPath = max(_longestPath, leftMaxUnivalDepth + rightMaxUnivalDepth);

        return 1 + max(leftMaxUnivalDepth, rightMaxUnivalDepth);
    }
};
