// ***
//
// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
// Example 1:
//
// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
//
// Example 2:
//
// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
//
// ***

// Recursive
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        _k = k;
        _inorder(root);
        return _res;
    }

private:
    int _k;
    int _res;

    void _inorder(TreeNode* node) {
        if (!node) {
            return;
        }

        _inorder(node->left);

        if (--_k == 0) {
            _res = node->val;
            return;
        }

        _inorder(node->right);
    }
};

// Iterative, no need to memorize it.
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> nodeStack;
    TreeNode* currentNode = root;

    while (currentNode || !nodeStack.empty()) {
        if (currentNode) {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            if (k-- == 1) {
                return node->val;
            }
            currentNode = node->right;
        }
    }
}
