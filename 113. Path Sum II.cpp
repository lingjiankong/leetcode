// ***
//
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
// 
// Note: A leaf is a node with no children.
// 
// Example:
// 
// Given the below binary tree and sum = 22,
// 
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:
// 
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
//
// ***
//
// See also 122. Path Sum, and 257. Binary Tree Paths.
class Solution
{

	public:

		vector<vector<int>> pathSum(TreeNode* root, int sum)
		{
			vector<vector<int>> all;
			vector<int> current;

			dfs(root, sum, current, all);

			return all;
		}

	private:

		void dfs(TreeNode* node, int sum, vector<int> current, vector<vector<int>>& all)
		{
			if (!node)
			{
				return;
			}

			current.push_back(node->val);

			if (node->val == sum && !node->left && !node->right)
			{
				all.push_back(current);
			}

			dfs(node->left, sum - node->val, current, all);
			dfs(node->right, sum - node->val, current, all);

			current.pop_back();
		}

};
