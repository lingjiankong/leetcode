// ***
//
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level
// by level from leaf to root).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
//
// ***
/
// This is just 102. Binary Tree Level Order Traversal with result reversed.
// Or you can use BFS and push new level to the front of the returned result.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int level = 0;
        _dfs(root, level);

        reverse(_result.begin(), _result.end());
        return _result;
    }

private:
    vector<vector<int>> _result;

    void _dfs(TreeNode* root, int level) {
        if (not root) {
            return;
        }

        while (_result.size() <= level) {
            _result.push_back({});
        }

        _result[level].push_back(root->val);
        _dfs(root->left, level + 1);
        _dfs(root->right, level + 1);
    }
};
