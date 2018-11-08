bool isSameTree(TreeNode* p, TreeNode* q)
{
	// Both are empty: same.
	if (!p && !q)
	{
		return true;
	}

	// Only one of the node is empty: not the same.
	else if (!p || !q)
	{
		return false;
	}

	// Both nodes are non-empty,
	// Nodes have different values, not the same.
	else if (p->val != q->val)
	{
		return false;
	}

	// Both nodes are non-empty
	// Nodes have the same values, then recursively check if left subtrees
	// and right subtrees are equal to each other.
	else
	{
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}
