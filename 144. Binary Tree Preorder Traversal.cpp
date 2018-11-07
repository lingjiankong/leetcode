// Recursive
class Solution
{

	public:

		vector<int> preorderTraversal(TreeNode* root)
		{
			dfs(root);
			return result;
		}
		
		void dfs(TreeNode* root)
		{
			if (!root)
			{
				return;
			}

			result.push_back(root->val);
			dfs(root->left);
			dfs(root->right);
		}

	private:

		vector<int> result;

};
