// ***
//
// Given a binary tree, count the number of uni-value subtrees.
// A Uni-value subtree means all nodes of the subtree have the same value.
//
// Example :
//
// Input:  root = [5,1,5,5,5,null,5]
//
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
//
// Output: 4
//
// ***
//
// Use *postorder* traversal to check:
// 1. If left and right subtrees are all univalue trees
// 2. If they are both univalue trees, then see if the value of current node is the same as the value of its existing
// subtree(s). If so, then we just found another univalue tree, ++_totalUnivalTrees.
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        _isUnivalueTree(root);

        return _totalUnivalTrees;
    }

private:
    int _totalUnivalTrees = 0;

    bool _isUnivalueTree(TreeNode* root) {
        if (not root) {
            return true;
        }

        bool isLeftUnival = _isUnivalueTree(root->left);
        bool isRightUnival = _isUnivalueTree(root->right);

        if (isLeftUnival and isRightUnival) {
            if (root->left and root->val != root->left->val) {
                return false;
            }

            if (root->right and root->val != root->right->val) {
                return false;
            }

            // Note: even if both root->left and root->right are nullptrs, we still have a valid univalue tree;
            // if one of root->left or root->right is nullptr, then as long as the other tree's value is the same as
            // root's value, we still have a valid univalue tree.
            ++_totalUnivalTrees;
            return true;
        }

        return false;
    }
};
