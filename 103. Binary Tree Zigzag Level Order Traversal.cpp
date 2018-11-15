// Just 102. Binary Tree Level Order Traversal with a leftToRight bool.
// There are methods that you don't need to reverse currentLevel, for example, 
// change the order of pushing back to nextLevel depending on current leftToRight flag.
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	if (!root)
	{
		return {};
	}

	vector<vector<int>> result;

	vector<TreeNode*> currentLevel = {root};
	vector<TreeNode*> nextLevel = {};

	bool leftToRight = true;

	while (!currentLevel.empty())
	{
		result.push_back({});

		for (auto node : currentLevel)
		{
			result.back().push_back(node->val);

			if (node->left)
			{
				nextLevel.push_back(node->left);
			}
			if (node->right)
			{
				nextLevel.push_back(node->right);
			}
		}

		if (!leftToRight)
		{
			reverse(result.back().begin(), result.back().end());
		}

		currentLevel.swap(nextLevel);
		nextLevel.clear();
		leftToRight = !leftToRight;
	}

	return result;
}
