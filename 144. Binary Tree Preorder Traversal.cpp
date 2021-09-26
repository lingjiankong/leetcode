// ***
//
// Given a binary tree, return the preorder traversal of its nodes' values.
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
// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?
//
// ***

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
        if (not root) {
            return;
        }

        _result.push_back(root->val);
        _preorder(root->left);
        _preorder(root->right);
    }
}

// Iterative using stack
// Pay attention to the sequence which you push the left and right nodes to the stack.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (not root) {
            return {};
        }

        vector<int> res;

        stack<TreeNode*> s;
        s.push(root);
        while (not s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            _result.push_back(node->val);

            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }

        return res;
    }
};

// A "solution template" for both preorder, inorder, and postorder traversal. No need to remember it.
// See also 94. Binary Tree Inorder Traversal and 145. Binary Tree Postorder Traversal.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        TreeNode* currentNode = root;

        while (currentNode || !nodeStack.empty()) {
            if (currentNode) {
                nodeStack.push(currentNode);
                _result.push_back(currentNode->val);
                currentNode = currentNode->left;
            } else {
                TreeNode* node = nodeStack.top();
                nodeStack.pop();
                currentNode = node->right;
            }
        }

        return _result;
    }

private:
    vector<int> _result;
};
