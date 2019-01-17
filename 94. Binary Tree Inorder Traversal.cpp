// ***
//
// Given a binary tree, return the inorder traversal of its nodes' values.
// 
// Example:
// 
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
// 
// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?
//
// ***
//
// A "solution template" for both preorder, inorder, and postorder traversal.
// There's nothing special about this method. Just memorize it.

class Solution
{

	public:

		vector<int> inOrderTraversal(TreeNode* root)
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
					mResult.push_back(node->val);
					currentNode = node->right;
				}
			}

			return mResult;
		}

	private:

		vector<int> mResult;

};
