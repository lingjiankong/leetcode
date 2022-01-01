// ***
//
// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Input:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
//
// ***
//
// See also 113. Path Sum II.

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<string> all;
        string cur;

        _dfs(root, cur, all);

        return all;
    }

private:
    void _dfs(TreeNode* node, string cur, vector<string>& all) {
        // Learning: In tree problems, we generally need to check whether the node we are instereted in right now is a
        // nullptr i.e. check if (!node) { return; }. However, in the case when we have already performed check for
        // nullptrs during recursion for subtrees (i.e. if (node->left) and if (node->right)), checking if (!node) is no
        // longer necessary

        // If a node is a leaf node, then it is the end of a path,
        // so we just push back that entire path to result.
        if (!node->left && !node->right) {
            all.push_back(cur + to_string(node->val));
        }

        if (node->left) {
            _dfs(node->left, cur + to_string(node->val) + "->", all);
        }

        if (node->right) {
            _dfs(node->right, cur + to_string(node->val) + "->", all);
        }
    }
};
