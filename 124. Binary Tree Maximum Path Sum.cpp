// ***
//
// Given a non-empty binary tree, find the maximum path sum.
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along
// the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
//
// Example 2:
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42
//
// ***

// See also 687. Longest Univalue Path. Very similar structure.
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        _oneSideMax(root);

        return _maxSum;
    }

private:
    // Note that a path must contain at least one node (which can be negative), therefore the maxSum might be negative.
    int _maxSum = INT_MIN;

    // Returns max sum from current root,
    // This will return either leftSubtreeMaxSum + root->val, or rightSubtreeMaxSum + root->val.
    int _oneSideMax(TreeNode* root) {
        if (not root) {
            return 0;
        }

        // We need to take max(_oneSideMax(root->left), 0)
        // because for example if leftMaxPathSum is negative, then we simply don't need the left subtree at all
        // when we are calculating the path sum for leftSubtree -> root -> rightSubtree.
        int leftMaxPathSum = max(0, _oneSideMax(root->left));
        int rightMaxPathSum = max(0, _oneSideMax(root->right));

        // Update global max sum.
        _maxSum = max(_maxSum, leftMaxPathSum + rightMaxPathSum + root->val);

        // Return max sum from current root.
        return max(leftMaxPathSum, rightMaxPathSum) + root->val;
    }
};
