// For a binary search tree, all nodes in left subtree must be smaller than current node,
// and all nodes in right subtree must be larger than current node.
// Therefore we can use preorder traversal to see whether a node satisfy this condition,
// and recursively check its left and right subtrees.
// We use nullptr so that we don't need to hard code things like INT_MIN or INT_MAX.
// The root node does not have any constraint on the min and max value it can take.
class Solution
{

	public:

		bool isValidBST(TreeNode* root)
		{
			return isValidBST(root, nullptr, nullptr);
		}

	private:

		bool isValidBST(TreeNode* node, int* minValue, int* maxValue)
		{
			if (!node)
			{
				return true;
			}

			if ((minValue && node->val <= *minValue) || (maxValue && node->val >= *maxValue))
			{
				return false;
			}

			return isValidBST(node->left, minValue, &node->val) && isValidBST(node->right, &node->val, maxValue);
		}

};

// In order traversal of a binary search tree gives ascending order.
class Solution
{

	public:

		bool isValidBST(TreeNode* root)
		{
			previousNode = nullptr;
			return inOrder(root);
		}

	private:

		TreeNode* previousNode;

		bool inOrder(TreeNode* node)
		{
			if (!node)
			{
				return true;
			}

			if (!inOrder(node->left))
			{
				return false;
			}

			if (previousNode && node->val <= previousNode->val) 
			{
				return false;
			}

			previousNode = node;

			return inOrder(node->right);
		}

};
