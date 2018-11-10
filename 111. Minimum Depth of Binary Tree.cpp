// Compare this question with 104. Maximum Depth of Binary Tree,
// Note the extra if and else if condition in this problem that checks if
// a node has only one subtree.
int minDepth(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	// If only one subtree exist (either left or right subtree),
	// then we must look into that subtree that exists,
	// otherwise, the null subtree (the subtree that doesn't exist) will return 0,
	// and you will falsely conclude that a node which only has one subtree has
	// minimum depth of 0.
	if (!root->left && root->right)
	{
		return 1 + minDepth(root->right);
	}
	else if (root->left && !root->right)
	{
		return 1 + minDepth(root->left);
	}
	else
	{
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
}
