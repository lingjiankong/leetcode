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

// Recursive solution. Trivial.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        _preorder(root);
        return _result;
    }

private:
    vector<int> _result;
    void _preorder(TreeNode* root) {
        if (root) {
            _preorder(root->left);
            _preorder(root->right);
            _result.push_back(root->val);
        }
    }
}

// A "solution template" for both preorder, inorder, and postorder traversal.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        TreeNode* currentNode = root;

        while (currentNode || !nodeStack.empty()) {
            if (currentNode) {
                nodeStack.push(currentNode);
                _result.push_back(currentNode->val);
                currentNode = currentNode->right;
            } else {
                TreeNode* node = nodeStack.top();
                nodeStack.pop();
                currentNode = node->left;
            }
        }

        reverse(_result.begin(), _result.end());
        return _result;
    }

private:
    vector<int> _result;
};

// Another iterative solution, see corresponding version for 144. Binary Tree Preorder Traversal.
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        _nodeStack.push(root);

        while (!_nodeStack.empty()) {
            TreeNode* node = _nodeStack.top();
            _nodeStack.pop();

            if (node) {
                _result.push_back(node->val);
                _nodeStack.push(node->left);
                _nodeStack.push(node->right);
            }
        }

        reverse(_result.begin(), _result.end());
        return _result;
    }

private:
    vector<int> _result;
    stack<TreeNode*> _nodeStack;
};
