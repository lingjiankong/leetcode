// I did 104, 250, 687, 543 together.
//
// IMPORTANT NOTE: In 104. Maximum Depth of Binary Tree, the definition of max depth is the
// NUMBER OF NODE along the longest path. In this question (and some other questions), it talks about
// the longest path (or longest length, longest height or whatever), which is THE NUMBER OF EDGES BETWEEN NODES,
// so pay attention to what it asks and don't confuse yourself.
//
// When calculating maxLength:
// if (!node) return -1.
//
// When calculating maxDepth:
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

			return max(leftTreeMaxLength, rightTreeMaxLength) + 1;
		}

};
