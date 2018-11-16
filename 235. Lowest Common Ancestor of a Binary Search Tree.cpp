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
