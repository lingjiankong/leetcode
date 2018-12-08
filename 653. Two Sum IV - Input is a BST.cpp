// ***
//
// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
// 
// Example 1:
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
// 
// Target = 9
// 
// Output: True
//
// Example 2:
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
// 
// Target = 28
// 
// Output: False
//
// ***
//
// Exactly the same logic as 1. Two Sum.
class Solution
{

	public:

		bool findTarget(TreeNode* root, int k)
		{
			return dfs(root, k);
		}

	private:

		unordered_set<int> mSeen;

		bool dfs(TreeNode* root, int& k)
		{
			if (!root)
			{
				return false;
			}

			int target = k - root->val;
			if (mSeen.count(target))
			{
				return true;
			}

			mSeen.insert(root->val);

			return dfs(root->left, k) || dfs(root->right, k);
		}

};
