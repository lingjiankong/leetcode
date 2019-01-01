// ***
//
// Given a binary tree, you need to compute the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// 
// Example:
// Given a binary tree 
//           1
//          / \
//         2   3
//        / \
//       4   5    
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
// ***
// 
// This is exactly the same as 104. Maximum Depth of Binary Tree,
// with an added mDiameter to track the diameter (leftSubtreeMaxDepth + rightSubtreeMaxDepth)of the tree.
class Solution
{

	public:

		int diameterOfBinaryTree(TreeNode* root)
		{
			mDiameter = 0;

			maxDepth(root);

			return mDiameter;
		}

	private:

		int mDiameter;

		int maxDepth(TreeNode* root)
		{
			if (!root)
			{
				return 0;
			}

			int leftTreeMaxDepth = maxDepth(root->left);
			int rightTreeMaxDepth = maxDepth(root->right);

			mDiameter = max(mDiameter, leftTreeMaxDepth + rightTreeMaxDepth);

			return 1 + max(leftTreeMaxDepth, rightTreeMaxDepth);
		}

};
