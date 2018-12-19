// ***
//
// Given a binary tree, count the number of uni-value subtrees.
// 
// A Uni-value subtree means all nodes of the subtree have the same value.
// 
// Example :
// 
// Input:  root = [5,1,5,5,5,null,5]
// 
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// 
// Output: 4
//
// ***
//
// Use *postorder* traversal to check:
// 1. If left and right subtrees are all univalue trees
// 2. If they are both univalue trees, then see if the value of current node is the same as the value of its existing subtrees.
// If so, then we just found another univalue tree, ++mTotalUnivalueTrees.
class Solution
{

	public:

		int countUnivalSubtrees(TreeNode* root)
		{
			mTotalUnivalueTrees = 0;

			isUnivalTree(root);

			return mTotalUnivalueTrees;
		}

	private:

		int mTotalUnivalueTrees;

		bool isUnivalTree(TreeNode* node)
		{
			if (!node)
			{
				return true;
			}

			bool leftSubtreeIsUnival = isUnivalTree(node->left);
			bool rightSubtreeIsUnival = isUnivalTree(node->right);

			if (leftSubtreeIsUnival && rightSubtreeIsUnival)
			{
				if (node->left && node->val != node->left->val)	
				{
					return false;
				}
				if (node->right && node->val != node->right->val)
				{
					return false;
				}

				++mTotalUnivalueTrees;
				return true;
			}
			else
			{
				return false;
			}
		}

};
