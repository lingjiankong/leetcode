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

// O(n) space complexity.
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

// O(1) space complexity not counting recursion.
// Since we know exactly one pair has been swapped, we can find that pair.
class Solution {
public:
    void recoverTree(TreeNode* root) {
        _inorder(root);
        swap(first->val, second->val);
    }

    void _inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        _inorder(root->left);

        if (!prev) {
            prev = root;
        } else {
            // We know only two elements have been swapped, so if prev->val > root->val,
            // then prev is a misplaced node, assign it to first;
            // current root is also a misplace rnode, assign it to second.
            if (prev->val > root->val) {
                if (!first) {
                    first = prev;
                }
                second = root;
            }

            prev = root;
        }

        _inorder(root->right);
    }

private:
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
};
