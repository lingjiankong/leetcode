// ***
//
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
// 
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
//
// ***
//
// Similar question: 314. Binary Tree Vertical Order Traversal.
//
// Our DFS solution uses preorder traversal to take care of current node first then its subtrees,
// using preorder might be a bit more intuitive, but actually in the DFS solution for this question,
// it doesn't matter if you use preorder, inorder, or postorder traversal.
//
// Compare this question with 366. Find Leaves of Binary Tree, which is a very similar question
// but uses a bottom up approach.
class Solution
{

	public:

		vector<vector<int>> levelOrder(TreeNode* root)
		{
			int level = 0;
			dfs(root, level);
			return mResult;
		}

	private:

		vector<vector<int>> mResult;

		void dfs(TreeNode* root, int level)
		{
			if (!root)
			{
				return;
			}

			while (mResult.size() <= level)	
			{
				mResult.push_back({});
			}

			mResult[level].push_back(root->val);

			dfs(root->left, level + 1);
			dfs(root->right, level + 1);
		}

};


// BFS solution, only one queue.
vector<vector<int>> levelOrder(TreeNode *root)
{
	if (!root)
	{
		return {};
	}

	vector<vector<int>> result;

	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		vector<int> currentLevel;
		int currentLevelSize = nodeQueue.size();

		for (int i = 0; i < currentLevelSize; ++i)
		{
			TreeNode* node = nodeQueue.front(); nodeQueue.pop();

			currentLevel.push_back(node->val);

			if (node->left)
			{
				nodeQueue.push(node->left);
			}

			if (node->right)
			{
				nodeQueue.push(node->right);
			}
		}

		result.push_back(currentLevel);
	}

	return result;
}


// BFS solution again:
// Similar question that uses the idea: 116. Populating Next Right Pointers in Each Node.
vector<vector<int>> levelOrder(TreeNode* root)
{
	if (!root)
	{
		return {};
	}

	vector<vector<int>> result;

	vector<TreeNode*> currentLevel = {root};
	vector<TreeNode*> nextLevel = {};

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

		currentLevel.swap(nextLevel);
		nextLevel.clear();
	}

	return result;
}

