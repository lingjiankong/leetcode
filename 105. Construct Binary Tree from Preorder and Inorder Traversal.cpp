class Solution
{

	public:

		TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder)
		{
			int iPre = 0, jPre = preorder.size();	
			int iIn = 0, jIn =  inorder.size();	

			return buildTree(preorder, iPre, jPre, inorder, iIn, jIn);
		}

	private:
		
		TreeNode* buildTree(const vector<int>& preorder, int iPre, int jPre, const vector<int>& inorder, int iIn, int jIn)
		{
			if (iPre >= jPre || iIn >= jIn)
			{
				return nullptr;
			}

			int rootValue = preorder[iPre];

			auto itr = find(inorder.begin() + iIn, inorder.begin() + jIn, rootValue);
			int index = itr - (inorder.begin() + iIn);

			TreeNode* root = new TreeNode(rootValue);
			root->left = buildTree(preorder, iPre + 1, iPre + 1 + index, inorder, iIn, iIn + index);
			root->right = buildTree(preorder, iPre + 1 + index, jPre, inorder, iIn + index, jIn);

			return root;
		}

};
