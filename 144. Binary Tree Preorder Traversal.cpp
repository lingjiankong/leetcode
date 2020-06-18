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
        if (root) {
            _result.push_back(root->val);
            _preorder(root->left);
            _preorder(root->right);
        }
    }
}

// A "solution template" for both preorder, inorder, and postorder traversal. You have to remember it.
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

// Another iterative solution.
// Pay attention to the sequence which you push the left and right nodes to the stack.
// When pushing node to stack you could have check if node->left and node->right is nullptr,
// but this doesn't make a big difference since you could push nullptr to stack and when
// it is popped, if(node) will return false and we do nothing, just continue popping the next element.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        _nodeStack.push(root);

        while (!_nodeStack.empty()) {
            TreeNode* node = _nodeStack.top();
            _nodeStack.pop();

            if (node) {
                _result.push_back(node->val);
                _nodeStack.push(node->right);
                _nodeStack.push(node->left);
            }
        }

        return _result;
    }

private:
    vector<int> _result;
    stack<TreeNode*> _nodeStack;
};

