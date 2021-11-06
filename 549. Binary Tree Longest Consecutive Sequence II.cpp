// ***
//
// Given the root of a binary tree, return the length of the longest consecutive path in the tree.
//
// A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be
// either increasing or decreasing.
//
// For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
// On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
//
//
// Example 1:
//
// Input: root = [1,2,3]
// Output: 2
// Explanation: The longest consecutive path is [1, 2] or [2, 1].
//
//
// Example 2:
//
// Input: root = [2,1,3]
// Output: 3
// Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
//
// ***

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (not root) {
            return 0;
        }

        // Treat every node in the tree as the "turning point".
        int curLongest = 1 + helper(root, -1) + helper(root, 1);

        return max({curLongest, longestConsecutive(root->left), longestConsecutive(root->right)});
    }

private:
    // Find the length of longest consecutive path in the tree starting at root with diff difference.
    int helper(TreeNode* root, int diff) {
        if (not root) {
            return 0;
        }

        int left = 0, right = 0;
        if (root->left and root->val - root->left->val == diff) {
            left = 1 + helper(root->left, diff);
        }
        if (root->right and root->val - root->right->val == diff) {
            right = 1 + helper(root->right, diff);
        }

        return max(left, right);
    }
};
