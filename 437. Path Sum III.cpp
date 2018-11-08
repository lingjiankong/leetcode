// Two recursion. One to iterate all subtree in a tree,
// i.e. treat each node as the root,
// the other recursion counts the sum in that tree.
class Solution
{

	public:

		int pathSum(TreeNode* root, int sum)
		{
			if (!root)
			{
				return 0;
			}

			return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
		}

	private:

		int dfs(TreeNode* node, int sum)
		{
			int count = 0;

			if (!node)
			{
				return 0;
			}

			if (node->val == sum)
			{
				++count;
			}

			count += dfs(node->left, sum - node->val) + dfs(node->right, sum - node->val);

			return count;
		}

};

// Same idea.
class Solution
{

	public:

		int pathSum(TreeNode* root, int sum)
		{
			if (!root)
			{
				return 0;
			}

			dfs(root, sum);
			pathSum(root->left, sum);
			pathSum(root->right, sum);

			return total;
		}

	private:

		int total = 0;

		void dfs(TreeNode* node, int sum)
		{
			if (!node)
			{
				return;
			}

			if (node->val == sum)
			{
				++total;
			}

			dfs(node->left, sum - node->val);
			dfs(node->right, sum - node->val);
		}

};

