// Compare this one with 111. Minimum Depth of Binary Tree.
int maxDepth(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
