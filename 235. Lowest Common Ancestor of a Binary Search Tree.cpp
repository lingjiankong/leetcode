// ***
//
// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//
// Example:
//
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
//
// ***
//
// See also 236. Lowest Common Ancester of a Binary Tree.
//
// Just uses the property of a binary search tree: left subtree < root < right subtree.
// Compare the value of p and q with current root node to decide which subtree we should search.
class Solution
{

	public:

		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
		{
			if (!root)
			{
				return nullptr;
			}

			else if (p->val < root->val && q->val < root->val)
			{
				return lowestCommonAncestor(root->left, p, q);
			}

			else if (p->val > root->val && q->val > root->val)
			{
				return lowestCommonAncestor(root->right, p, q);
			}

			else
			{
				return root;
			}
		}

};
