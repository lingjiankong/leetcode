// ***
//
// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
// 
// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
// 
// Example 1:
// 
// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
// 
// Example 2:
// 
// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
//
// ***
//
// Recursive
class Solution
{

	public:

		int kthSmallest(TreeNode* root, int k)
		{
			mCount = k;

			inOrder(root);

			return mResult;
		}

	private:
		
		int mCount;

		int mResult;

		void inOrder(TreeNode* node)
		{
			if (!node)
			{
				return;
			}

			inOrder(node->left);

			if (mCount-- == 1)
			{
				mResult = node->val;

				return;
			}

			inOrder(node->right);
		}

};

// Iterative
int kthSmallest(TreeNode* root, int k)
{
	stack<TreeNode*> nodeStack;
	TreeNode* currentNode = root;

	while (currentNode || !nodeStack.empty())
	{
		if (currentNode)
		{
			nodeStack.push(currentNode);
			currentNode = currentNode->left;
		}
		else
		{
			TreeNode* node = nodeStack.top(); nodeStack.pop();
			if (k-- == 1)
			{
				return node->val;
			}
			currentNode = node->right;
		}
	}
}
