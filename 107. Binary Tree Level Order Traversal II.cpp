// ***
//
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
// 
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
//
// ***
//
// This is just 102. Binary Tree Level Order Traversal with result reversed.
// Or you can use BFS and push new level to the front of the returned result.
class Solution
{

	public:

		vector<vector<int>> levelOrderBottom(TreeNode* root)
		{
			int level = 0;

			dfs(root, level);

			reverse(mResult.begin(), mResult.end());

			return mResult;
		}

	private:

		vector<vector<int>> mResult;

		void dfs(TreeNode* node, int level)
		{
			if (!node)	
			{
				return;
			}

			while (mResult.size() <= level)
			{
				mResult.push_back({});
			}

			mResult[level].push_back(node->val);

			dfs(node->left, level + 1);
			dfs(node->right, level + 1);
		}

};
