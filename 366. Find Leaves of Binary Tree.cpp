// ***
//
// Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
//
// Example:
// Input: [1,2,3,4,5]
//
//           1
//          / \
//         2   3
//        / \
//       4   5
//
// Output: [[4,5,3],[2],[1]]
//
// Explanation:
//
// 1. Removing the leaves [4,5,3] would result in this tree:
//
//           1
//          /
//         2
//
// 2. Now removing the leaf [2] would result in this tree:
//
//           1
//
// 3. Now removing the leaf [1] would result in the empty tree:
//
//           []
//
// ***
//
// We need to use a bottom up approach, all leaves should have a height of 0 (and therefore be pushed back to mLeaves[0]).
// i.e. When you traverse down to a leaf node, its lefSubtreeMaxHeight = -1 and rightSubtreeMaxHeight = -1, that's why all leaves have a height of 0.
// This is just 104. Maximum Depth of Binary Tree, while adding depth of node to a vector along the way.
//
// The height of every node in the tree is the max height of its left or right subtree.
// Use *postorder* traversal to recursively deal with leaves (subtrees) first, append those leaves to mLeaves with their corresponding height.
//
// Compare this question with 102. Binary Tree Level Order Traversal, which is a similar question but uese a top-down appraoch.
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
