// I did 104, 250, 687, 543 together.
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
