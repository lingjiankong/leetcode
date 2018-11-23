// BFS solution:
// This solution uses the idea in 102. Binary Tree Level Order Traversal
void connect(TreeLinkNode* root)
{
	if (!root)
	{
		return;
	}
		
	TreeLinkNode* currentLevelStart = root;

	while (currentLevelStart)
	{
		TreeLinkNode* current = currentLevelStart;

		while (current)
		{
			if (current->left)
			{
				current->left->next = current->right;
			}

			if (current->right && current->next)
			{
				current->right->next = current->next->left;
			}

			current = current->next;
		}

		currentLevelStart = currentLevelStart->left;
	}
}

// DFS (preorder) solution:
void connect(TreeLinkNode* root)
{
	if (!root)
	{
		return;
	}

	if (root->left)
	{
		root->left->next = root->right;
	}

	if (root->right && root->next)
	{
		root->right->next = root->next->left;
	}

	connect(root->left);
	connect(root->right);
}
