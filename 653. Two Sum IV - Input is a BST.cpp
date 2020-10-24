// ***
//
// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their
// sum is equal to the given target.
//
// Example 1:
// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
// Example 2:
// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False
//
// ***
//
// Exactly the same logic as 1. Two Sum.

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }

        int numToFind = k - root->val;
        if (_seen.count(numToFind)) {
            return true;
        }

        _seen.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }

private:
    unordered_set<int> _seen;
};
