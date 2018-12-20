// ***
//
// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
// 
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
// ***


// Given root of a binary search tree, the smallest element is the left most node.
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
			TreeNode* currentSmallest = mStack.top(); mStack.pop();

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
