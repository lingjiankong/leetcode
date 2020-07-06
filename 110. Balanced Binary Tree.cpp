// ***
//
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example 1:
//
// Given the following tree [3,9,20,null,null,15,7]:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.
//
// Example 2:
//
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.
//
// ***
//
// Note here that the definition of balanced tree is
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
// We must consider every node, not just the depth of every leaf from the root node.

// O(nlogn) solution. Not efficient.
// For every node, check the maxDepth of its left and right subtree, see if their difference <= 1.
// Then, recursively check if its left and right subtrees are balanced.
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int leftHeight = _findMaxDepth(root->left);
        int rightHeight = _findMaxDepth(root->right);

        return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int _findMaxDepth(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int leftDepth = _findMaxDepth(node->left);
        int rightDepth = _findMaxDepth(node->right);

        return 1 + max(leftDepth, rightDepth);
    }
};

// O(n) solution.
// Previously when we check the maxDepth of left and right subtrees using _findMaxDepth(),
// we are visiting each node and we know the depth information of every subtree within left and right subtrees,
// but we didn't compare the depth inside _findMaxDepth(), so why don't we just use that information.
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;

        _findMaxDepth(root, balanced);

        return balanced;
    }

private:
    int _findMaxDepth(TreeNode* node, bool& balanced) {
        if (!node) {
            return 0;
        }

        int leftDepth = _findMaxDepth(node->left, balanced);
        int rightDepth = _findMaxDepth(node->right, balanced);

        if (abs(leftDepth - rightDepth) > 1) {
            balanced = false;

            // Return whatever here so we could break out of recursive calls.
            return -1;
        }

        return 1 + max(leftDepth, rightDepth);
    }
};
