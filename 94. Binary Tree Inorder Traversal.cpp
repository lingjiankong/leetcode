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
// Iterative. You have to remember it. Read the code and think about it.
// For in order traversal. The idea is to traverse along the left until the bottom,
// along the way add all nodes seen to the stack, until you've reached the end,
// then you pop the node (i.e. the left most element) from stack and add it to mResult.
// Now you do the same for the right subtree of that node you just popped.
class Solution
{

	public:

		vector<int> inorderTraversal(TreeNode* root)
		{
			TreeNode* currentNode = root;

			while (currentNode || !mNodeStack.empty())
			{
				if (currentNode)
				{
					mNodeStack.push(currentNode);
					currentNode = currentNode -> left;
				}
				else
				{
					TreeNode* node = mNodeStack.top(); mNodeStack.pop();
					mResult.push_back(node->val);
					currentNode = node -> right;
				}
			}

			return mResult;
		}

	private:

		vector<int> mResult;
		stack<TreeNode*> mNodeStack;

};

// Iterative. Same idea as above, slightly modify the code to help you 
// better visualize the concept.
class Solution
{

	public:

		vector<int> inorderTraversal(TreeNode* root)
		{
			TreeNode* currentNode = root;

			while (currentNode || !mNodeStack.empty())
			{
				while (currentNode)
				{
					mNodeStack.push(currentNode);
					currentNode = currentNode -> left;
				}

				TreeNode* node = mNodeStack.top(); mNodeStack.pop();
				mResult.push_back(node->val);
				currentNode = node -> right;
			}

			return mResult;
		}

	private:

		vector<int> mResult;
		stack<TreeNode*> mNodeStack;

};
