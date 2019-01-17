// ***
//
// Invert a binary tree.
// 
// Example:
// 
// Input:
// 
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// Output:
// 
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
//
// ***
//
// Postorder traverse the left and right subtree of root, then swap the left and right subtree.
TreeNode* invertTree(TreeNode* root)
{
	if (!root)
	{
		return nullptr;
	}

	root->left = invertTree(root->left);
	root->right = invertTree(root->right);
	swap(root->left, root->right);

	return root;
}

// Same thing:
class Solution
{

	public:

		TreeNode* invertTree(TreeNode* root)
		{
			dfs(root);
			return root;
		}

	private:

		void dfs(TreeNode* root)
		{
			if (!root)
			{
				return;
			}

			dfs(root->left);
			dfs(root->right);
			swap(root->left, root->right);
		}

};
