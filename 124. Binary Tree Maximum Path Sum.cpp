// ***
//
// Given a non-empty binary tree, find the maximum path sum.
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
// The path must contain at least one node and does not need to go through the root.
// 
// Example 1:
// 
// Input: [1,2,3]
// 
//        1
//       / \
//      2   3
// 
// Output: 6
// Example 2:
// 
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
//
// Note that a path must contain at least one node, therefore the maxSum might be negative.
//
class Solution
{

	public:

		int maxPathSum(TreeNode* root)
		{
			int maxSum = INT_MIN;

			dfs(root, maxSum);

			return maxSum;
		}

	private:

		int dfs(TreeNode* node, int& maxSum)
		{
			if (!node)
			{
				return 0;
			}

			// We need to take max(dfs(node->left, maxSum), 0)
			// because for example if leftSubtreeMaxPathSum < 0, then we simply don't need the left subtree at all
			// when we are calculating the path sum for leftSubtree - root - rightSubtree.
			int leftSubtreeMaxPathSum = max(dfs(node->left, maxSum), 0);
			int rightSubtreeMaxPathSum = max(dfs(node->right, maxSum), 0);

			maxSum = max(maxSum, leftSubtreeMaxPathSum + rightSubtreeMaxPathSum + node->val);

			return max(leftSubtreeMaxPathSum, rightSubtreeMaxPathSum) + node->val;
		}

};
