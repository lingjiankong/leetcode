// ***
//
// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
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
// You should develop your own sort of convention when doing tree problems.
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
			maxUnivalueLength(root);
			return mLongestPath;
		}

	private:

		int mLongestPath;	

		int maxUnivalueLength(TreeNode* node)
		{
			if (!node)
			{
				return -1;
			}

			int leftSubtreeMaxUnivalLength = maxUnivalueLength(node->left);
			int rightSubtreeMaxUnivalLength = maxUnivalueLength(node->right);

			// Reset maxUnival of a subtree if its values != the value of our current node.
			if (node->left && node->val != node->left->val)
			{
				leftSubtreeMaxUnivalLength = -1;
			}

			if (node->right && node->val != node->right->val)
			{
				rightSubtreeMaxUnivalLength = -1;
			}

			mLongestPath = max(mLongestPath, leftSubtreeMaxUnivalLength + rightSubtreeMaxUnivalLength + 2);

			return 1 + max(leftSubtreeMaxUnivalLength, rightSubtreeMaxUnivalLength);
		}
};

// Same thing, just help you better understand the concept.
class Solution
{

	public:

		int longestUnivaluePath(TreeNode* root)
		{
			mLongestPath = 0;
			maxUnivalueLength(root);
			return mLongestPath;
		}

	private:

		int mLongestPath;	

		int maxUnivalueLength(TreeNode* node)
		{
			if (!node)
			{
				return -1;
			}

			int leftSubtreeMaxUnivalLength = maxUnivalueLength(node->left);
			int rightSubtreeMaxUnivalLength = maxUnivalueLength(node->right);

			// Calculate the new leftSubtreeMaxUnivalLength and rightSubtreeMaxUnivalLength
			// with current node as the root node.
			if (node->left && node->val == node->left->val)
			{
				leftSubtreeMaxUnivalLength += 1;
			}
			else
			{
				leftSubtreeMaxUnivalLength = 0;
			}

			if (node->right && node->val == node->right->val)
			{
				rightSubtreeMaxUnivalLength += 1;
			}
			else
			{
				rightSubtreeMaxUnivalLength = 0;
			}

			mLongestPath = max(mLongestPath, leftSubtreeMaxUnivalLength + rightSubtreeMaxUnivalLength);

			return max(leftSubtreeMaxUnivalLength, rightSubtreeMaxUnivalLength);
		}

};
