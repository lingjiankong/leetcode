// ***
//
// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value
// sequence.
//
//
// Two binary trees are considered leaf-similar if their leaf value sequence is the same.
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
//
//
// Example 1:
//
// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true
//
//
// Example 2:
//
// Input: root1 = [1], root2 = [1]
// Output: true
//
//
// Example 3:
//
// Input: root1 = [1], root2 = [2]
// Output: false
//
//
// Example 4:
//
// Input: root1 = [1,2], root2 = [2,2]
// Output: true
//
//
// Example 5:
//
// Input: root1 = [1,2,3], root2 = [1,3,2]
// Output: false
//
//
// Constraints:
//
// The number of nodes in each tree will be in the range [1, 200].
// Both of the given trees will have values in the range [0, 200].
//
// ***

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeaves(root1, leaf1);
        getLeaves(root2, leaf2);

        return leaf1 == leaf2;
    }

private:
    void getLeaves(TreeNode* root, vector<int>& leafs) {
        if (not root) {
            return;
        }

        if (not root->left and not root->right) {
            leafs.push_back(root->val);
        }

        getLeaves(root->left, leafs);
        getLeaves(root->right, leafs);
    }
};
