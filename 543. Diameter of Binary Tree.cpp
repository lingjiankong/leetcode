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
// IMPORTANT NOTE: In 104. Maximum Depth of Binary Tree, the definition of max depth is the
// NUMBER OF NODE along the longest path. In this question (and some other questions), it talks about
// the longest path (or longest length, longest height or whatever), which is THE NUMBER OF EDGES BETWEEN NODES,
// so pay attention to what it asks and don't confuse yourself.
//
// When calculating maxLength (number of edges):
// if (!node) return -1.
//
// When calculating maxDepth (number of nodes):
// if (!node) return 0.
//
// In general, maxDepth = maxLength + 1.
//
class Solution
{

	public:

		int diameterOfBinaryTree(TreeNode* root)
		{
			mDiameter = 0;

			maxLength(root);

			return mDiameter;
		}

	private:

		int mDiameter;

		int maxLength(TreeNode* node)
		{
			if (!node)
			{
				return -1;
			}

			int leftTreeMaxLength = maxLength(node->left);
			int rightTreeMaxLength = maxLength(node->right);

			mDiameter = max(mDiameter, leftTreeMaxLength + rightTreeMaxLength + 2);

			return 1 + max(leftTreeMaxLength, rightTreeMaxLength);
		}

};
