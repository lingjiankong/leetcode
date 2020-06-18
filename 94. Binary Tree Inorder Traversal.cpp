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
    vector<int> preorderTraversal(TreeNode* root) {
        _preorder(root);
        return _result;
    }

private:
    vector<int> _result;
    void _preorder(TreeNode* root) {
        if (root) {
            _preorder(root->left);
            _result.push_back(root->val);
            _preorder(root->right);
        }
    }
}

// A "solution template" for both preorder, inorder, and postorder traversal.
// There's nothing special about this method. Just memorize it.
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
