// ***
//
// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
//
// Note:
// A subtree must include all of its descendants.
//
// Example:
//
// Input: [10,5,15,1,8,null,7]
//
//    10
//    / \
//   5  15
//  / \   \
// 1   8   7
//
// Output: 3
// Explanation: The Largest BST Subtree in this case is the highlighted one.
//              The return value is the subtree's size, which is 3.
//
// ***
//
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
