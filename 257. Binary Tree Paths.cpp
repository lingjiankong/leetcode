// See also 113. Path Sum II.
class Solution
{

	public:

		vector<string> binaryTreePaths(TreeNode* root)
		{
			if (!root)
			{
				return {};
			}

			dfs(root, to_string(root->val));

			return result;
		}

	private:

		vector<string> result;

		void dfs(TreeNode* node, string path)
		{
			// You don't have to check if the node is empty,
			// since the way this function is called is guaranteed that the node is not empty.
			if (!node)
			{
				return;
			}

			// If a node has no children, then it is the end of a path,
			// so we just push back that entire path to result.
			if (!node->left && !node->right)	
			{
				result.push_back(path);
			}

			if (node->left)
			{
				dfs(node->left, path + "->" + to_string(node->left->val));
			}

			if (node->right)
			{
				dfs(node->right, path + "->" + to_string(node->right->val));
			}
		}

};
