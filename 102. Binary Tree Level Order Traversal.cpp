class Solution
{

	public:

		vector<vector<int>> levelOrder(TreeNode* root)
		{
			int depth = 0;
			dfs(root, depth);
			return result;
			
			/* return bfs(root); */
		}

	private:

		void dfs(TreeNode* root, int depth)
		{
			if (!root)
			{
				return;
			}

			while (result.size() <= depth)	
			{
				result.push_back({});
			}

			result[depth].push_back(root->val);
			dfs(root->left, depth + 1);
			dfs(root->right, depth + 1);
		}

		vector<vector<int>> bfs(TreeNode* root)
		{
			if (!root)
			{
				return {};
			}

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

		vector<vector<int>> result;

};
