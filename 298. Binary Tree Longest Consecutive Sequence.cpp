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

        // Initial target doesn't matter, you can set taret = 12345.
        // currentLength will either be increased by 1 (if we pass in target = root->val),
        // or currentLength will be reset to 1 (if we pass in a random number).
        int currentLength = 0;
        int target = 0;
        int maxLength = 0;

        _dfs(root, currentLength, root->val, maxLength);

        return maxLength;
    }

private:
    void _dfs(TreeNode* node, int currentLength, int target, int& maxLength) {
        if (!node) {
            return;
        }

        if (node->val == target) {
            ++currentLength;
        } else {
            // Reset current length.
            currentLength = 1;
        }

        maxLength = max(maxLength, currentLength);

        _dfs(node->left, currentLength, node->val + 1, maxLength);
        _dfs(node->right, currentLength, node->val + 1, maxLength);
    }
};
