// ***
//
// You are given the root of a binary search tree (BST) and an integer val.
//
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a
// node does not exist, return null.
//
// ***

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (not root) {
            return nullptr;
        }

        if (root->val == val) {
            return root;
        }

        if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
};
