class Solution
{

	public:

		int longestConsecutive(TreeNode* root)
		{
			int maxLength = 0;
			
			// Initial target doesn't matter,
			// currentLength will either be increased to 1 (if we pass in target = root->val),
			// or currentLength will be reset to 1 (if we pass in a random number).
			dfs(root, 0, 12345, maxLength);

			return maxLength;
		}

	private:

		void dfs(TreeNode* node, int currentLength, int target, int& maxLength)
		{
			if (!node)
			{
				return;
			}

			if (node->val == target)
			{
				++currentLength;
			}
			else
			{
				// Reset current length.
				currentLength = 1;
			}

			maxLength = max(maxLength, currentLength)
			dfs(node->left, currentLength, node->val + 1, maxLength);
			dfs(node->right, currentLength, node->val + 1, maxLength);
		}

};
