// ***
//
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
// Example 2:
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
// Follow up:
//
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?
//
// ***

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inOrderTreeNodePtrs;
        vector<int> inOrderTreeNodeValues;

        _inorder(root, inOrderTreeNodePtrs, inOrderTreeNodeValues);

        sort(inOrderTreeNodeValues.begin(), inOrderTreeNodeValues.end());
        for (int i = 0; i < inOrderTreeNodePtrs.size(); ++i) {
            inOrderTreeNodePtrs[i]->val = inOrderTreeNodeValues[i];
        }
    }

private:
    void _inorder(TreeNode* root, vector<TreeNode*>& inOrderTreeNodePtrs, vector<int>& inOrderTreeNodeValues) {
        if (!root) {
            return;
        }
        _inorder(root->left, inOrderTreeNodePtrs, inOrderTreeNodeValues);

        inOrderTreeNodePtrs.push_back(root);
        inOrderTreeNodeValues.push_back(root->val);

        _inorder(root->right, inOrderTreeNodePtrs, inOrderTreeNodeValues);
    }
};
