// ***
//
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of
// every node never differ by more than 1.
//
// Example:
//
// Given the sorted array: [-10,-3,0,5,9],
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
//
// ***
//
// The root value of a binary search tree is greater than its left subtree and
// less than its right subtree. That is, the root of a binary serach tree is nums[mid].
//
// Remember you can calculate the mid index of an array using two ways:
// 1. (nums.size() - 1) / 2 : mid is on the left part if even elements.
// 2. nums.size() / 2 : mid is on the right part if even elements.

class Solution {
public:
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        return _preorder(nums, l, r);
    }

private:
    TreeNode* _preorder(const vector<int>& nums, int l, int r) {
        if (l >= r) {
            return nullptr;
        }

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _preorder(nums, l, mid);
        root->right = _preorder(nums, mid + 1, r);

        return root;
    }
};
