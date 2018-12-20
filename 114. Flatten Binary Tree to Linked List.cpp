// ***
//
// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//
// ***

// Note that in the linked list each node's right child points to the next node during preorder traversal.
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

			root->right = mPreviousNode;
			root->left = nullptr;
			mPreviousNode = root;
		}

	private:

		TreeNode* mPreviousNode = nullptr;

};
