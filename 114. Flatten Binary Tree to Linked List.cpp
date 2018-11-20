// Note that each node's right child points to the next node of a pre-order traversal.
// The most intuitive solution to this question is to use reversed pre-order traversal,
// and add the last node first, dealing with tail node to head node.
class Solution
{

	public:

		void flatten(TreeNode* root)
		{
			if (!root)
			{
				return;
			}

			flatten(root->right);
			flatten(root->left);

			root->right = previousNode;
			root->left = nullptr;
			previousNode = root;
		}
	
	private:

		TreeNode* previousNode = nullptr;

};
