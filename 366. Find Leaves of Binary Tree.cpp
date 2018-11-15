// We need to use a bottom up approach, all leaves should have a height of 0
// (and therefore be pushed back to mLeaves[0]).
// The height of every node in the tree is the max height of its left or right subtree.
//
// Use postorder traversal to recursively deal with leaves (subtrees) first,
// append those leaves to mLeaves with their corresponding height.
//
// Compare this question with 102. Binary Tree Level Order Traversal, which is a similar question
// but uese a top-down appraoch.
class Solution
{

	public:

		vector<vector<int>> findLeaves(TreeNode* root)
		{
			maxHeight(root);
			return mLeaves;
		}

	private:

		vector<vector<int>> mLeaves;

		int maxHeight(TreeNode* node)
		{
			if (!node)
			{
				return -1;
			}

			int leftSubtreeMaxHeight = maxHeight(node->left);
			int rightSubtreeMaxHeight = maxHeight(node->right);

			int currentMaxHeight = 1 + max(leftSubtreeMaxHeight, rightSubtreeMaxHeight);

			// Make sure mLeaves has enough space.
			while (mLeaves.size() <= currentMaxHeight)
			{
				mLeaves.push_back({});
			}


			mLeaves[currentMaxHeight].push_back(node->val);

			// Make node the nullptr (i.e. erase that node, since the question asks us to do so)
			// Whether you set node to nullptr has no effect to the result mLeaves.
			node = nullptr;

			return currentMaxHeight;
		}

};
