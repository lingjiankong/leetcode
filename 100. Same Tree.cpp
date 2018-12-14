// ***
//
// Given two binary trees, write a function to check if they are the same or not.
// 
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
// 
// Example 1:
// 
// Input:     1         1
//           / \       / \
//          2   3     2   3
// 
//         [1,2,3],   [1,2,3]
// 
// Output: true
// Example 2:
// 
// Input:     1         1
//           /           \
//          2             2
// 
//         [1,2],     [1,null,2]
// 
// Output: false
// Example 3:
// 
// Input:     1         1
//           / \       / \
//          2   1     1   2
// 
//         [1,2,1],   [1,1,2]
// 
// Output: false
//
// ***
//
bool isSameTree(TreeNode* p, TreeNode* q)
{
	// Both are empty: same.
	if (!p && !q)
	{
		return true;
	}

	// Only one of the node is empty: not the same.
	else if (!p || !q)
	{
		return false;
	}

	// Both nodes are non-empty,
	// Nodes have different values, not the same.
	else if (p->val != q->val)
	{
		return false;
	}

	// Both nodes are non-empty
	// Nodes have the same values, then recursively check if left subtrees
	// and right subtrees are equal to each other.
	else
	{
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}
