// See also 122. Path Sum, and 257. Binary Tree Paths.
class Solution
{

	public:

		vector<vector<int>> pathSum(TreeNode* root, int sum)
		{
			dfs(root, sum, {});
			return result;
		}

	private:

		vector<vector<int>> result;

		void dfs(TreeNode* node, int sum, vector<int> path)
		{
			if (!node)
			{
				return;
			}

			path.push_back(node->val);

			// If node->val == sum and the node has no children, then it is the end of a path,
			// which satisfies the sum requirement, so we just push back that entire path to result.
			if (node->val == sum && !node->left && !node->right)
			{
				result.push_back(path);
			}

			dfs(node->left, sum - node->val, path);
			dfs(node->right, sum - node->val, path);
		}

};
