// ***
//
// Given a binary tree, find the length of the longest path where each root in the path has the same value. This path may or may not pass through the root.
// Note: The length of path between two nodes is represented by the number of edges between them.
// 
// Example 1:
// Input:
// 
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:
// 2
//
// Example 2:
// Input:
// 
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:
// 2
//
// ***
//
// Pay attention to the following terms:
// Depth: number of nodes, can only go from parent to child.
// Height (or length): number of edges connecting nodes, can only go from parent to child.
// Path: number of edges connecting nodes, doesn't necessarily go from parent to child.
//
// This is a postorder traversal problem because we need the information from both left and right subtrees
// and compare them to current root node.
class Solution
{

	public:

		int longestUnivaluePath(TreeNode* root)
		{
			mLongestPath = 0;

			maxUnivalueDepth(root);

			return mLongestPath;
		}

	private:

		int mLongestPath;	

		int maxUnivalueDepth(TreeNode* root)
		{
			if (!root)
			{
				return 0;
			}

			int leftSubtreeMaxUnivalDepth = maxUnivalueDepth(root->left);
			int rightSubtreeMaxUnivalDepth = maxUnivalueDepth(root->right);

			// Reset maxUnival of a subtree if its values != the value of our current root.
			if (root->left && root->val != root->left->val)
			{
				leftSubtreeMaxUnivalDepth = 0;
			}

			if (root->right && root->val != root->right->val)
			{
				rightSubtreeMaxUnivalDepth = 0;
			}

			mLongestPath = max(mLongestPath, leftSubtreeMaxUnivalDepth + rightSubtreeMaxUnivalDepth);

			return 1 + max(leftSubtreeMaxUnivalDepth, rightSubtreeMaxUnivalDepth);
		}

};
