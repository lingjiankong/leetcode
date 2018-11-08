TreeNode* invertTree(TreeNode* root)
{
	if (root)	
	{
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		swap(root->left, root->right);
	}
	
	return root;
}

//Same thing
class Solution
{

	public:

		TreeNode* invertTree(TreeNode* root)
		{
			dfs(root);
			return root;
		}

	private:

		void dfs(TreeNode* node)
		{
			if (node)
			{
				dfs(node->left);
				dfs(node->right);
				swap(node->left, node->right);
			}
		}

};
