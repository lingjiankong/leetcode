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
// subtree(s). If so, then we just found another univalue tree, ++_totalUnivalueTrees.
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        _isUnivalueTree(root);

        return _totalUnivalueTrees;
    }

private:
    int _totalUnivalueTrees = 0;

    bool _isUnivalueTree(TreeNode* node) {
        if (not node) {
            return true;
        }

        bool isLeftUnival = _isUnivalueTree(node->left);
        bool isRightUnival = _isUnivalueTree(node->right);

        if (isLeftUnival and isRightUnival) {
            if (node->left and node->val != node->left->val) {
                return false;
            }

            if (node->right and node->val != node->right->val) {
                return false;
            }

            ++_totalUnivalueTrees;
            return true;
        }

        return false;
    }
};
