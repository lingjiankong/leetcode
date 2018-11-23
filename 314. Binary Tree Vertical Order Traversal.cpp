// See also 102. Binary Tree Level Order Traversal.
//
// Horizontally level order traverse the tree,
// in the queue for level order traversal, also store the current vertical level for each node:
// For a left node, vertical level -= 1,
// for a right node node, vertical level += 1.
// Maintain an tree map<int, vector<int>> levelToNodes, which stores each vertical level and all nodes at that level.
//
// Why do we need to maintain an tree map levelToNodes?
// Because unlike horizontal level order, initially you don't know what the "0th" vertial level is,
// so you can't use index to push to vector. We have to traverse through levelToNodes in the end
// and push each vector at different vertical level to toReturn in the end.
vector<vector<int>> verticalOrder(TreeNode* root)
{
	if (!root)
	{
		return {};
	}

	vector<vector<int>> toReturn;

	map<int, vector<int>> levelToNodes;

	// Stores node as well as that node's vertical level.
	queue<pair<TreeNode*, int>> nodeQueue;
	nodeQueue.push({root, 0});

	while (!nodeQueue.empty())
	{
		auto nodeToLevel = nodeQueue.front();
		nodeQueue.pop();

		TreeNode* node = nodeToLevel.first;
		int verticalLevel = nodeToLevel.second;

		levelToNodes[verticalLevel].push_back(node->val);

		if (node->left)
		{
			nodeQueue.push({node->left, verticalLevel - 1});
		}
		
		if (node->right)
		{
			nodeQueue.push({node->right, verticalLevel + 1});
		}
	}

	for (auto element : levelToNodes)
	{
		vector<int> sameLevelNodes = element.second;
		toReturn.push_back(sameLevelNodes);
	}

	return toReturn;
}
