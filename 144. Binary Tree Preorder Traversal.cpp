// Recursive
class Solution
{

	public:

		vector<int> preorderTraversal(TreeNode* root)
		{
			dfs(root);
			return result;
		}
		
		void dfs(TreeNode* node)
		{
			if (node)
			{
				result.push_back(node->val);
				dfs(node->left);
				dfs(node->right);
			}
		}

	private:

		vector<int> result;

};

// Iterative. You need to remember it.
// Pay attention to the sequence which you push the left and right nodes to the stack.
// When pushing node to stack you could have check if node->left and node->right is nullptr,
// but this doesn't make a big difference since you could push nullptr to stack and when
// it is popped, if(node) will return false and we do nothing, just continue popping the next element.
class Solution
{

	public:

		vector<int> preorderTraversal(TreeNode* root)
		{
			nodeStack.push(root);

			while (!nodeStack.empty())
			{
				TreeNode* node = nodeStack.top();
				nodeStack.pop();

				if (node)
				{
					result.push_back(node->val);
					nodeStack.push(node->right);
					nodeStack.push(node->left);
				}
			}

			return result;
		}

	private:

		vector<int> result;

		stack<TreeNode*> nodeStack;

};
