// Simply use the property of binary search tree.
int closestValue(TreeNode* root, double target)
{
	int result = root->val;

	while (root)
	{
		if (abs(root->val - target) < abs(result - target))
		{
			result = root->val;
		}

		root = root->val < target ? root->right : root->left;
	}

	return result;
}
