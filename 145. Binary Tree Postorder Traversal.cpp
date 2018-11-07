// Recursive
class Solution
{

    public:

        vector<int> postorderTraversal(TreeNode* root)
        {
            dfs(root);
            return result;
        }

        void dfs(TreeNode* node)
        {
            if (node)
            {   
                dfs(node->left);
                dfs(node->right);
                result.push_back(node->val);
            }
        }

    private:

        vector<int> result;

};

// This method below takes extra space so it is not efficient.
// It just means to help you visualize how recursive tree traversal is done
// Postorder traversal = [leftSubtree] + [rightSubtree] + root.
vector<int> postorderTraversal(TreeNode* root)
{	
	if (!root)
	{	
		return {};
	}

	vector<int> result;
	
	vector<int> leftSubtree = postorderTraversal(root->left);
	vector<int> rightSubtree = postorderTraversal(root->right);

	result.insert(result.end(), leftSubtree.begin(), leftSubtree.end());
	result.insert(result.end(), rightSubtree.begin(), rightSubtree.end());
	result.push_back(root->val);

	return result;
}

// Iterative solution.
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
// This looks pretty much like a preorder traversal with
// right and left subtree traversal swapped.
// We could use the iterative method similar to 144. Binary Tree Preorder Traversal
// to calculate the result, then reverse it to get the post order traversal result.
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

