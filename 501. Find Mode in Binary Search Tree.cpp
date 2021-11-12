// ***
//
// Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently
// occurred element) in it.
//
// If the tree has more than one mode, return them in any order.
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
//
//
// Example 1:
//
//
// Input: root = [1,null,2,2]
// Output: [2]
//
//
// Example 2:
//
// Input: root = [0]
// Output: [0]
//
// ***

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return _ans;
    }

private:
    int _maxCount = 0;
    int _count = 0;
    int _val = 0;
    vector<int> _ans;

    void inorder(TreeNode* root) {
        if (not root) {
            return;
        }

        inorder(root->left);
        visit(root);
        inorder(root->right);
    }

    void visit(TreeNode* root) {
        if (_count > 0 and root->val == _val) {
            ++_count;
        } else {
            _val = root->val;
            _count = 1;
        }

        if (_count > _maxCount) {
            _maxCount = _count;
            _ans.clear();
        }

        if (_count == _maxCount) {
            _ans.push_back(root->val);
        }
    }
};
