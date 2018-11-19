// This is a good question but not very intuitive to visualize. You might need to draw the tree to understand.
//
// Just remember:
// p's successor during in order traversal can either be
// 1. The smallest node in p's right subtree, OR if p does not have a right subtree, then
// 2. One of p's ancestor (not necessarily p's direct parent), more specifically, it is p's first ancestor
// to which the subtree p belongs to is that ancestor node's left subtree (first ancestor which "turns right").
//
// Note also that the smallest node in a binary search tree is just its left most node.
//
// Iteration solution:
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
	TreeNode* successor = nullptr;

	while (root)
	{
		if (root->val <= p->val)
		{
			root = root->right;
		}
		else
		{
			successor = root;
			root = root->left;
		}
	}

	return successor;
}

// Same idea as above, if and else swapped, this might be more intuitive.
//
// If root->val > p->val, then node p must be in the left subtree of current root, we assign current root to successor,
// and move current root to its left subtree. Now, keep comparing the value of root and node p.
// If still root->val > p->val, we repeat the above process.
// Otherwise, root->val < p->val, then node p must be in the right subtree of current node,
// we move current root to its right subtree (note that at this poing successor has already been assigned to some ancestor node).
//
// At some point, root->val == p->val, we are right at node p. Now, we also enter the else loop and set
// current root to the right subtree. From this point onward, if (root->val > p->val) will always be true,
// because we are at the right subtree of node p so every thing is bigger than p.
// So we just traverse all the way for the left most node, and assign successor on the way.
// If no such node exist, then because previously we have assigened
// successor to some ancestor node of node p, we just return that node.
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
	TreeNode* successor = nullptr;

	while (root)
	{
		if (root->val > p->val)
		{
			successor = root;
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}

	return successor;
}

// Recursive solution:
//
// When the code runs into the else block, that means the current root is either p's ancestor or the smallest node in p's right subtree.
//
// Explanation of return left ? left : root
// If left exists, then the successor of node p is smallest node in p's right subtree.
// If left doesn't exist, then the successor of node p is p's ancester.
// 
// See also 173. Binary Search Tree Iterator for some intuition.
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
	if (!root)
	{
		return nullptr;
	}

	if (root->val <= p->val)
	{
		return inorderSuccessor(root->right, p);
	}
	else
	{
		TreeNode* left = inorderSuccessor(root->left, p);
		return left ? left : root;
	}
}

// Bonus: in order predecessor
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p)
{
	if (!root)
	{
		return nullptr;
	}

	if (root->val >= p->val)
	{
		return inorderPredecessor(root->left, p);
	}
	else
	{
		TreeNode* right = inorderSuccessor(root->right, p);
		return right ? right : root;
	}
}
