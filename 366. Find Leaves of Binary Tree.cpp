// ***
//
// Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until
// the tree is empty.
//
// Example:
// Input: [1,2,3,4,5]
//
//           1
//          / \
//         2   3
//        / \
//       4   5
//
// Output: [[4,5,3],[2],[1]]
//
// Explanation:
//
// 1. Removing the leaves [4,5,3] would result in this tree:
//
//           1
//          /
//         2
//
// 2. Now removing the leaf [2] would result in this tree:
//
//           1
//
// 3. Now removing the leaf [1] would result in the empty tree:
//
//           []
//
// ***
//
// This is just 104. Maximum Depth of Binary Tree, while adding depth of node to a vector along the way.
//
// We need to use a bottom up approach, all leaves should have a height of 0.
//
// The height of every node in the tree is the max height of its left or right subtree.
// Use *postorder* traversal to recursively deal with leaves (subtrees) first, append those leaves to _leaves with their
// corresponding height.
//
// Compare this question with 102. Binary Tree Level Order Traversal, which is a similar question but uese a top-down
// appraoch.

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        _maxHeight(root);

        return _leaves;
    }

private:
    vector<vector<int>> _leaves;

    // Note here we are returning the max *height* of a root, which is the number of *edges* along a path,
    // not the max *depth* of a root, which is the number of *nodes* along a path.
    // that's why if (!root) { return -1; }, instead of if (!root) { return 0; }.
    int _maxHeight(TreeNode* root) {
        if (!root) {
            return -1;
        }

        int leftSubtreeMaxHeight = _maxHeight(root->left);
        int rightSubtreeMaxHeight = _maxHeight(root->right);
        int currentMaxHeight = 1 + max(leftSubtreeMaxHeight, rightSubtreeMaxHeight);

        // Make sure _leaves has enough space.
        while (_leaves.size() <= currentMaxHeight) {
            _leaves.push_back({});
        }
        _leaves[currentMaxHeight].push_back(root->val);

        // Make root the nullptr (i.e. erase that node, since the question asks us to do so)
        // Whether you set root to nullptr has no effect to the result _leaves.
        root = nullptr;

        return currentMaxHeight;
    }
};
