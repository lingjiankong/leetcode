// ***
//
// A binary tree is uni-valued if every node in the tree has the same value.
//
// Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
//
//
// Example 1:
//
// Input: root = [1,1,1,1,1,null,1]
// Output: true
//
//
// Example 2:
//
// Input: root = [2,2,2,5,2]
// Output: false
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [1, 100].
// 0 <= Node.val < 100
//
// ***

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (not root) {
            return true;
        }

        return _dfs(root, root->val);
    }

private:
    bool _dfs(TreeNode* root, int val) {
        if (not root) {
            return true;
        }

        if (root->val != val) {
            return false;
        }

        return _dfs(root->left, val) and _dfs(root->right, val);
    }
};

// Without helper function.
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (not root) {
            return true;
        }

        if (root->left and root->val != root->left->val) {
            return false;
        }

        if (root->right and root->val != root->right->val) {
            return false;
        }

        return isUnivalTree(root->left) and isUnivalTree(root->right);
    }
};

