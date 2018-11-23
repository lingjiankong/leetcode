// See also 105. Construct Binary Tree from Preorder and Inorder Traversal.
// These two are basically the same question.
//
// Inorder   [(left subtree)  root  (right subtree)]
// Postorder [(left subtree)  (right subtree)  root]
//
// Postorder traversing implies that the last element in post order is the root node.
// Then we can find this root in inorder, say it's inorder[5].
// Now we know that inorder[5] is root, so we know that inorder[0] - inorder[4] is on the left side, inorder[6] to the end is on the right side.
// Recursively doing this on subarrays, we can build a tree out of it.
class Solution
{

    public:

        TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder)
        {
            int postorderLeft = 0, postorderRight = postorder.size();  
            int inorderLeft = 0, inorderRight =  inorder.size();    

            return buildTree(postorder, postorderLeft, postorderRight, inorder, inorderLeft, inorderRight);
        }

    private:
        
        TreeNode* buildTree(const vector<int>& postorder, int postorderLeft, int postorderRight, const vector<int>& inorder, int inorderLeft, int inorderRight)
        {
            if (postorderLeft >= postorderRight || inorderLeft >= inorderRight)
            {
                return nullptr;
            }

            int rootValue = postorder[postorderRight - 1];

            auto itr = find(inorder.begin() + inorderLeft, inorder.begin() + inorderRight, rootValue);
            int leftSubtreeSize = itr - inorder.begin() - inorderLeft;

            TreeNode* root = new TreeNode(rootValue);
            root->left = buildTree(postorder, postorderLeft, postorderLeft + leftSubtreeSize, inorder, inorderLeft, inorderLeft + leftSubtreeSize);
            root->right = buildTree(postorder, postorderLeft + leftSubtreeSize, postorderRight - 1, inorder, inorderLeft + leftSubtreeSize + 1, inorderRight);

            return root;
        }

};

