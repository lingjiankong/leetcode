// This is not the optimized solution, but is very clear.
// See also 98. Validate Binary Search Tree.
class Solution
{

	public:

		int largestBSTSubtree(TreeNode* root)
		{
			if (!root)
			{
				return 0;
			}

			if (isValidBST(root, INT_MIN, INT_MAX))
			{
				return countNodes(root);
			}

			return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
		}

	private:

		bool isValidBST(TreeNode* root, int minValue, int maxValue)
		{
			if (!root)
			{
				return true;
			}

			if (root->val <= minValue || root->val >= maxValue)
			{
				return false;
			}

			return (isValidBST(root->left, minValue, root->val) && isValidBST(root->right, root->val, maxValue));
		}

		int countNodes(TreeNode* root)
		{
			if (!root)
			{
				return 0;
			}
			
			return 1 + countNodes(root->left) + countNodes(root->right);
		}

};
