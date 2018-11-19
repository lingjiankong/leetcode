// Given root of a binary search tree, the smallest element is the left most node.
//
// Given root of a binary search tree, the next element that is bigger than current root is
// the left most node of right subtree of current root.
//
// It is hard to describe in words. Just look at the code. This is a good question.
class BSTIterator
{
	public:

		BSTIterator(TreeNode *root)
		{
			pushAllLeftNodes(root);
		}

		bool hasNext()
		{
			return !mStack.empty();
		}

		int next()
		{
			TreeNode* currentSmallest = mStack.top();
			mStack.pop();

			pushAllLeftNodes(currentSmallest->right);

			return currentSmallest->val;
		}

	private:

		stack<TreeNode*> mStack;

		void pushAllLeftNodes(TreeNode* node)
		{
			while (node)
			{
				mStack.push(node);
				node = node->left;
			}
		}
};
