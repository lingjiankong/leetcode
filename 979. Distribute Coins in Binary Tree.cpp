// ***
//
// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n
// coins in total throughout the whole tree. In one move, we may choose two adjacent nodes and move one coin from one
// node to another. A move may be from parent to child, or from child to parent. Return the minimum number of moves
// required to make every node have exactly one coin.
//
//
// Example 1:
//
// Input: root = [3,0,0]
// Output: 2
// Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
//
//
// Example 2:
//
// Input: root = [0,3,0]
// Output: 3
// Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one
// coin from the root of the tree to the right child.
//
//
// Example 3:
//
// Input: root = [1,0,2]
// Output: 2
//
//
// Example 4:
//
// Input: root = [1,0,0,null,3]
// Output: 4
//
//
// Constraints:
//
// The number of nodes in the tree is n.
// 1 <= n <= 100
// 0 <= Node.val <= n
// The sum of all Node.val is n.
//
// ***

// Not easy to understand.
// See huahua video: https://zxi.mytechroad.com/blog/tree/leetcode-979-distribute-coins-in-binary-tree/
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        balance(root);
        return _moves;
    }

private:
    int _moves = 0;

    int balance(TreeNode* root) {
        if (not root) {
            return 0;
        }

        // How many coin flows through (to/from) the left subtree
        int l = balance(root->left);

        // How many coin flows through (to/from) the right subtree
        int r = balance(root->right);

        // Add to total coin flows
        _moves += abs(l) + abs(r);

        // Return total coin flows through (to/from) tree at root
        // -1 here because if root->val = 1, it is perfect, no flow is needed.
        return root->val - 1 + l + r;
    }
};

