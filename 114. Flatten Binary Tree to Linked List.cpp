// ***
//
// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//
// ***
//
// Note that in the linked list each node's right child points to the next node during preorder traversal.
// The most intuitive solution to this question is to use *reversed* pre-order traversal,
// and add the last node first, dealing from tail node to head node.
//
// Note: Reversed pre-order traversal gives you the exact opposite result as pre-order traversal.
// Same for reversed in-order traversal and reversed post-order traversal.

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = _prevNode;
        root->left = nullptr;
        _prevNode = root;
    }

private:
    TreeNode* _prevNode = nullptr;
};
