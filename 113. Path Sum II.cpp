// ***
//
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
//
// ***
//
// See also 122. Path Sum, and 257. Binary Tree Paths.

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> all;
        vector<int> cur;

        _dfs(root, sum, cur, all);

        return all;
    }

private:
    void _dfs(TreeNode* root, int sum, vector<int> cur, vector<vector<int>>& all) {
        if (not root) {
            return;
        }

        cur.push_back(root->val);
        if (root->val == sum and not root->left and not root->right) {
            all.push_back(cur);
        }

        _dfs(root->left, sum - root->val, cur, all);
        _dfs(root->right, sum - root->val, cur, all);
    }
};
