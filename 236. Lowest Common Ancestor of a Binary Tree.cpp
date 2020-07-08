// ***
//
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as
// descendants (where we allow a node to be a descendant of itself).”
//
// Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
//
// Example:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
//
// Explanation: The LCA of nodes 5 and 1 is 3.
//
// ***
//
// This question is kind of abstract... You need to memorize it.
// Use postorder traversal, return the common ancester upward to the top level.
// The basic idea is that, if you see p or q, you return that node upward.
// For any root in the recursion process, if you find the left subtree contains a valid returned node,
// and the right subtree also contains a valid returned node, then current root must be the common ancester.
// and then, you keep return that common ancester node upward until it reaches the top level.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return nullptr;
    } else if (root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (!left && !right) {
        return nullptr;
    } else if (left && !right) {
        return left;
    } else if (!left && right) {
        return right;
    } else {
        return root;
    }
}

