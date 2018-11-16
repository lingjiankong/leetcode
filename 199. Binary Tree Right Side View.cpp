// This is a very good question.
// We use a modified version of preorder traversal that traverse down the tree on the right,
// So we know that the first node we see on a new level must be the right most node on that level.
// So, whenever we see a node on a new level, append that node->val to the result.
class Solution
{

	public:

		vector<int> rightSideView(TreeNode* root)
		{
			int level = 0;
			dfs(root, level);
			return mResult;
		}

	private:

		vector<int> mResult;

		void dfs(TreeNode* node, int level)
		{
			if (!node)
			{
				return;
			}

			if (mResult.size() == level)
			{
				mResult.push_back({node->val});
			}
			
			dfs(node->right, level + 1);
			dfs(node->left, level + 1);
		}

};
