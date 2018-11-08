// This question is just a slight modification based on 100. Same Tree
bool isSymmetric(TreeNode* root)
{
	if (!root)
	{
		return true;
	}

	return dfs(root->left, root->right);
}

bool dfs(TreeNode* l, TreeNode* r)
{
	if (!l && !r)
	{
		return true;
	}

	else if (!l || !r)
	{
		return false;
	}

	else if (l->val != r->val)
	{
		return false;
	}

	else
	{
		return dfs(l->left, r->right) && dfs(l->right, r->left);
	}
}
