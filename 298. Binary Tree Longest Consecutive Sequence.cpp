// ***
//
// Given a binary tree, find the length of the longest consecutive sequence path.
// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child
// connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
//
// Example 1:
//
// Input:
//
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
//
// Output: 3
//
// Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
//
// Example 2:
//
// Input:
//
//    2
//     \
//      3
//     /
//    2
//   /
//  1
//
// Output: 2
//
// Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
//
// ***

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // Initial target doesn't matter, you can set target = 12345.
        // curLen will either be increased by 1 (if we pass in target = root->val),
        // or curLen will be reset to 1 (if we pass in a random number).
        int curLen = 0;

        _dfs(root, curLen, root->val);

        return _maxLen;
    }

private:
    int _maxLen = 0;

    void _dfs(TreeNode* node, int curLen, int target) {
        if (!node) {
            return;
        }

        if (node->val == target) {
            ++curLen;
        } else {
            // Reset current length.
            curLen = 1;
        }

        _maxLen = max(_maxLen, curLen);

        _dfs(node->left, curLen, node->val + 1);
        _dfs(node->right, curLen, node->val + 1);
    }
};

// Use same method as 549. Binary Tree Longest Consecutive Sequence II. Less efficient.
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int curLongest = 1 + helper(root, -1);

        return max({curLongest, longestConsecutive(root->left), longestConsecutive(root->right)});
    }

private:
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
