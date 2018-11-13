// O(nlogn) solution.
// For every node, check the maxDepth of its left and right subtree, see if their difference <= 1.
// Then, recursively check if its left and right subtrees are balanced.
class Solution
{

	public:

		bool isBalanced(TreeNode* root)
		{
			if (!root)
			{
				return true;
			}

			int leftHeight = maxDepth(root->left);
			int rightHeight = maxDepth(root->right);

			return abs(leftHeight-rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
		}

	private:

		int maxDepth(TreeNode* node)
		{
			if (!node)
			{
				return 0;
			}

			return 1 + max(maxDepth(node->left), maxDepth(node->right));
		}

};

// O(n) solution.
// Previously when we check the maxDepth of left and right subtrees using maxDepth(),
// we are visiting each node and the know the depth information of every subtree within left and right subtrees,
// but we didn't compare the depth inside maxDepth(), so why don't we just use that information.
// Previous solution kind of does two redundant maxDepth calculation.
class Solution
{

	public:

		bool isBalanced(TreeNode* root)
		{
			bool balanced = true;

			maxDepth(root, &balanced);

			return balanced;
		}

	private:

		int maxDepth(TreeNode* node, bool* balanced)
		{
			if (!node)
			{
				return 0;
			}

			int leftDepth = maxDepth(node->left, balanced);
			int rightDepth = maxDepth(node->right, balanced);

			if (abs(leftDepth - rightDepth) > 1)
			{
				*balanced = false;

				// Return whatever to break out of recursive calls.
				return -1;
			}

			return 1 + max(leftDepth, rightDepth);
		}

};
