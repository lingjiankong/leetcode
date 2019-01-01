// ***
//
// Given a binary tree
// 
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// 
// Initially, all next pointers are set to NULL.
// 
// Note:
// 
// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//
// Example:
// 
// Given the following perfect binary tree,
// 
//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// After calling your function, the tree should look like:
// 
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL
//
// ***
//
// BFS solution:
// This solution uses the idea in 102. Binary Tree Level Order Traversal
void connect(TreeLinkNode* root)
{
	if (!root)
	{
		return;
	}
		
	TreeLinkNode* currentLevelStart = root;

	while (currentLevelStart)
	{
		TreeLinkNode* current = currentLevelStart;

		while (current)
		{
			if (current->left)
			{
				current->left->next = current->right;
			}

			if (current->right && current->next)
			{
				current->right->next = current->next->left;
			}

			current = current->next;
		}

		// The start position of next level.
		currentLevelStart = currentLevelStart->left;
	}
}

// DFS (preorder) solution:
void connect(TreeLinkNode* root)
{
	if (!root)
	{
		return;
	}

	if (root->left)
	{
		root->left->next = root->right;
	}

	if (root->right && root->next)
	{
		root->right->next = root->next->left;
	}

	connect(root->left);
	connect(root->right);
}
