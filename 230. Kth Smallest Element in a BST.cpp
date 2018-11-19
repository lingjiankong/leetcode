class Solution
{

	public:

		int kthSmallest(TreeNode* root, int k)
		{
			mCount = k;

			inOrder(root);

			return mResult;
		}

	private:
		
		int mCount;

		int mResult;

		void inOrder(TreeNode* node)
		{
			if (!node)
			{
				return;
			}

			inOrder(node->left);

			if (mCount-- == 1)
			{
				mResult = node->val;
			}

			inOrder(node->right);
		}
};
