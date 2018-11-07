// Recursive
class Solution
{

	public:

		vector<int> inorderTraversal(TreeNode* root)
		{
			dfs(root);
			return result;
		}
		
		void dfs(TreeNode* node)
		{
			if (node)
			{
				dfs(node->left);
				result.push_back(node->val);
				dfs(node->right);
			}
		}

	private:

		vector<int> result;

};

// Iterative. You have to remember it. Read the code and think about it.
// For in order traversal. The idea is to traverse along the left until the bottom,
// along the way add all nodes seen to the stack, until you've reached the end,
// then you pop the node (i.e. the left most element) from stack and add it to result.
// Now you do the same for the right subtree of that node you just popped.
class Solution
{

	public:

		vector<int> inorderTraversal(TreeNode* root)
		{
			TreeNode* currentNode = root;

			while (currentNode || !nodeStack.empty())
			{
				if (currentNode)
				{
					nodeStack.push(currentNode);
					currentNode = currentNode -> left;
				}
				else
				{
					TreeNode* node = nodeStack.top();
					nodeStack.pop();
					result.push_back(node->val);
					currentNode = node -> right;
				}
			}

			return result;
		}

	private:

		vector<int> result;

		stack<TreeNode*> nodeStack;

};

// Iterative. Same idea as above, slightly modify the code to help you 
// better visualize the concept.
class Solution
{

	public:

		vector<int> inorderTraversal(TreeNode* root)
		{
			TreeNode* currentNode = root;

			while (currentNode || !nodeStack.empty())
			{
				while (currentNode)
				{
					nodeStack.push(currentNode);
					currentNode = currentNode -> left;
				}

				TreeNode* node = nodeStack.top();
				nodeStack.pop();
				result.push_back(node->val);
				currentNode = node -> right;
			}

			return result;
		}

	private:

		vector<int> result;

		stack<TreeNode*> nodeStack;

};
