// ***
//
// Given a binary tree, return the postorder traversal of its nodes' values.
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
// Output: [3,2,1]
// Follow up: Recursive solution is trivial, could you do it iteratively?
//
// ***
//
// A "solution template" for both preorder, inorder, and postorder traversal.
//
// A post order traversal is
//
// postOrder(node->left)
// postOrder(node->right)
// print(node->val)
//
// The reverse of a post order traversal is
//
// print(node->val)
// postOrder(node->right)
// postOrder(node->left)
//
// This looks pretty much like a preorder traversal with right and left subtree traversal swapped.
// We could use the iterative method similar to 144. Binary Tree Preorder Traversal
// to calculate the result, then reverse it to get the post order traversal result.
class Solution
{

	public:

		vector<int> postorderTraversal(TreeNode* root)
		{
			TreeNode* currentNode = root;

			while (currentNode || !mNodeStack.empty())
			{
				if (currentNode)
				{
					mNodeStack.push(currentNode);
					mResult.push_back(currentNode->val);
					currentNode = currentNode -> right;
				}
				else
				{
					TreeNode* node = mNodeStack.top(); mNodeStack.pop();
					currentNode = node -> left;
				}
			}

			reverse(mResult.begin(), mResult.end());
			return mResult;
		}

	private:

		vector<int> mResult;
		stack<TreeNode*> mNodeStack;

};

// Another iterative solution, see corresponding version for 144. Binary Tree Preorder Traversal.
class Solution
{

    public:

        vector<int> postorderTraversal(TreeNode* root)
        {
            nodeStack.push(root);

            while (!nodeStack.empty())
            {
                TreeNode* node = nodeStack.top();
                nodeStack.pop();

                if (node)
                {
                    result.push_back(node->val);
                    nodeStack.push(node->left);
                    nodeStack.push(node->right);
                }
            }

            reverse(result.begin(), result.end());
			return result;
        }

    private:

        vector<int> result;
        stack<TreeNode*> nodeStack;

};
