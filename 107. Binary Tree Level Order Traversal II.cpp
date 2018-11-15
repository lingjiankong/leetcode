// This is just 102. Binary Tree Level Order Traversal with result reversed.
// Or you can use BFS and push new level to the front of the returned result.
class Solution
{

	public:

		vector<vector<int>> levelOrderBottom(TreeNode* root)
		{
			int level = 0;

			dfs(root, level);

			reverse(mResult.begin(), mResult.end());

			return mResult;
		}

	private:

		vector<vector<int>> mResult;

		void dfs(TreeNode* node, int level)
		{
			if (!node)	
			{
				return;
			}

			while (mResult.size() <= level)
			{
				mResult.push_back({});
			}

			mResult[level].push_back(node->val);

			dfs(node->left, level + 1);
			dfs(node->right, level + 1);
		}

};
