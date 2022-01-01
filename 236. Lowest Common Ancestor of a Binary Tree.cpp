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
// This question is a little bit abstract. See labuladong book pp. 261.
//
// Use postorder traversal, return the common ancester upward to the top level.
// The basic idea is that, if you see p or q, you return that node upward (bubble up).
// For any root in the recursion process, if you find the left subtree contains a valid returned node,
// and the right subtree also contains a valid returned node, then current root must be the common ancester.
// and then, you keep return that common ancester node upward until it reaches the top level.
//
// 1. if p and q are in the tree starting at root, return the lowest common ancester.
// 2. if neither p nor q are in the tree starting at root, return the nullptr.
// 3. if p is in the tree strating at root but not q, return p.
// 4. if q is in the tree strating at root but not p, return q.
//
// Note, this question guarantees that lowest common ancester exists.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (not root) {
        return nullptr;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // Can also be placed above recursion.
    if (root == p or root == q) {
        return root;
    }

    if (left and right) {
        // If left and right both exist, then root must be the lowest common ancester.
        // (root is guaranteed to be the lowest because of postorder traversal).
        return root;
    } else if (left) {
        return left;
    } else if (right) {
        return right;
    } else {
        return nullptr;
    }
}

