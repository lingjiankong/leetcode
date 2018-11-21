// Preorder [root  (left subtree)  (right subtree)]
// Inorder  [(left subtree)  root  (right subtree)]
//
// Preorder traversing implies that preorder[0] is the root node.
// Then we can find this preorder[0] in inorder, say it's inorder[5].
// Now we know that inorder[5] is root, so we know that inorder[0] - inorder[4] is on the left side, inorder[6] to the end is on the right side.
// Recursively doing this on subarrays, we can build a tree out of it.
class Solution
{

	public:

		TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder)
		{
			int preorderLeft = 0, preorderRight = preorder.size();	
			int inorderLeft = 0, inorderRight =  inorder.size();	

			return buildTree(preorder, preorderLeft, preorderRight, inorder, inorderLeft, inorderRight);
		}

	private:
		
		TreeNode* buildTree(const vector<int>& preorder, int preorderLeft, int preorderRight, const vector<int>& inorder, int inorderLeft, int inorderRight)
		{
			if (preorderLeft >= preorderRight || inorderLeft >= inorderRight)
			{
				return nullptr;
			}

			int rootValue = preorder[preorderLeft];

			auto itr = find(inorder.begin() + inorderLeft, inorder.begin() + inorderRight, rootValue);
			int leftSubtreeSize = itr - inorder.begin() - inorderLeft;

			TreeNode* root = new TreeNode(rootValue);
			root->left = buildTree(preorder, preorderLeft + 1, preorderLeft + 1 + leftSubtreeSize, inorder, inorderLeft, inorderLeft + leftSubtreeSize);
			root->right = buildTree(preorder, preorderLeft + 1 + leftSubtreeSize, preorderRight, inorder, inorderLeft + leftSubtreeSize + 1, inorderRight);

			return root;
		}

};
