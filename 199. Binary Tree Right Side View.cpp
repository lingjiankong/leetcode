// ***
//
// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
// ordered from top to bottom.
//
// Example:
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
//
// ***
//
// This is a very good question.
// We use a modified version of preorder traversal that traverse down the tree on the right,
// So we know that the first node we see on a new level must be the right most node on that level.
// So, whenever we see a node on a new level, append that node->val to the result.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        _dfs(root, level);
        return _result;
    }

private:
    vector<int> _result;

    void _dfs(TreeNode* node, int level) {
        if (!node) {
            return;
        }

        // In this case, we are seeing a new level for the first time,
        // meaning we are seeing the right most node on that level.
        // In this case, push the value of node to _result.
        if (_result.size() == level) {
            _result.push_back({node->val});
        }

        _dfs(node->right, level + 1);
        _dfs(node->left, level + 1);
    }
};
