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
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
// ***

// This question is just a slight modification based on 100. Same Tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return _preorder(root->left, root->right);
    }

private:
    bool _preorder(TreeNode* l, TreeNode* r) {
        if (!l && !r) {
            return true;
        } else if (!l || !r) {
            return false;
        } else if (l->val != r->val) {
            return false;
        } else {
            return _preorder(l->left, r->right) && _preorder(l->right, r->left);
        }
    }
};
