// I did 104, 250, 687, 543 together.
// Compare this one with 111. Minimum Depth of Binary Tree.
//
// Postorder traversal.
int maxDepth(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	int leftSubtreeMaxDepth = maxDepth(root->left);
	int rightSubtreeMaxDepth = maxDepth(root->right);
	int currentTreeMaxDepth = 1 + max(leftSubtreeMaxDepth, rightSubtreeMaxDepth);

	return currentTreeMaxDepth;
}

// Same thing.
int maxDepth(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
