// ***
//
// Given a binary tree, return the preorder traversal of its nodes' values.
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
// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?
//
// ***
//
// A "solution template" for both preorder, inorder, and postorder traversal. You have to remember it.
// See also 94. Binary Tree Inorder Traversal and 145. Binary Tree Postorder Traversal.
class Solution
{

	public:

		vector<int> preorderTraversal(TreeNode* root)
		{
			TreeNode* currentNode = root;

			while (currentNode || !mNodeStack.empty())
			{
				if (currentNode)
				{
					mNodeStack.push(currentNode);
					mResult.push_back(currentNode->val);
					currentNode = currentNode->left;
				}
				else
				{
					TreeNode* node = mNodeStack.top(); mNodeStack.pop();
					currentNode = node->right;
				}
			}

			return mResult;
		}

	private:

		vector<int> mResult;
		stack<TreeNode*> mNodeStack;

};

// Another iterative solution.
// Pay attention to the sequence which you push the left and right nodes to the stack.
// When pushing node to stack you could have check if node->left and node->right is nullptr,
// but this doesn't make a big difference since you could push nullptr to stack and when
// it is popped, if(node) will return false and we do nothing, just continue popping the next element.
class Solution
{

	public:

		vector<int> preorderTraversal(TreeNode* root)
		{
			mNodeStack.push(root);

			while (!mNodeStack.empty())
			{
				TreeNode* node = mNodeStack.top();
				mNodeStack.pop();

				if (node)
				{
					mResult.push_back(node->val);
					mNodeStack.push(node->right);
					mNodeStack.push(node->left);
				}
			}

			return mResult;
		}

	private:

		vector<int> mResult;
		stack<TreeNode*> mNodeStack;

};

