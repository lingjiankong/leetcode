// ***
//
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//     3   3
//
// ***

// This question is just a slight modification based on 100. Same Tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return _dfs(root->left, root->right);
    }

private:
    bool _dfs(TreeNode* p, TreeNode* q) {
        if (!p and !q) {
            return true;
        }

        if (!p or !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return _dfs(p->left, q->right) and _dfs(p->right, q->left);
    }
};
