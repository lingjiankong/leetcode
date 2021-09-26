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

// Recursive solution. Trivial.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        _inorder(root);
        return _result;
    }

private:
    vector<int> _result;
    void _inorder(TreeNode* root) {
        if (not root) {
            return;
        }

        _inorder(root->left);
        _result.push_back(root->val);
        _inorder(root->right);
    }
}

// A "solution template" for both preorder, inorder, and postorder traversal.
// No need to remember it.
class Solution {
public:
    vector<int> inOrderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        TreeNode* currentNode = root;

        while (currentNode || !nodeStack.empty()) {
            if (currentNode) {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            } else {
                TreeNode* node = nodeStack.top();
                nodeStack.pop();
                _result.push_back(node->val);
                currentNode = node->right;
            }
        }

        return _result;
    }

private:
    vector<int> _result;
};
