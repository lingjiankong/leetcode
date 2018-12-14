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
// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//
// Example:
// Given the following binary tree,
// 
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
//
// After calling your function, the tree should look like:
// 
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL
//
// ***
//
// This solution uses the idea in 102. Binary Tree Level Order Traversal
// Took be quite long to understand the solution, but once you get it this is still a good question.
//
// We traverse current level (the level of currentNode), and we connect the current level's all children nodes accordingly,
// until there's no more node (currentNode) in current level. Now we go to next level.
//
// Well, how do we know where to start in next level? This is where dummyNode->next comes into play
// dummyNode->next is the first child node we see when we are traversing current level,
// so dummyNode->next is the node we should start we traversing the next level.
void connect(TreeLinkNode* root)
{
	while (root)
	{
		TreeLinkNode dummyNode = TreeLinkNode(0);

		// currentNode is a node on current level we are traversing.
		TreeLinkNode* currentNode = root;

		// currentChild is a node on next level.
		// Initially we have no idea when we will see the first child of current level.
		TreeLinkNode* currentChild = &dummyNode;

		while (currentNode)
		{
			if (currentNode->left)
			{
				currentChild->next = currentNode->left;
				currentChild = currentChild->next;
			}

			if (currentNode->right)
			{
				currentChild->next = currentNode->right;
				currentChild = currentChild->next;
			}

			currentNode = currentNode->next;
		}

		root = dummyNode.next;
		dummyNode.next = nullptr;
	}
}
