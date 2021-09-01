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
    vector<int> postorderTraversal(TreeNode* root) {
        _postorder(root);
        return _result;
    }

private:
    vector<int> _result;
    void _postorder(TreeNode* root) {
        if (not root) {
            return;
        }

        _postorder(root->left);
        _postorder(root->right);
        _result.push_back(root->val);
    }
}

// Iterative solution using stack, see corresponding version for 144. Binary Tree Preorder Traversal.
//
// A post order traversal is
//
// postOrder(node->left)
// postOrder(node->right)
// print(node->val)
//
// The *reverse* of a post order traversal is
//
// print(node->val)
// postOrder(node->right)
// postOrder(node->left)
//
// This looks pretty much like a *preorder* traversal with right and left subtree traversal swapped.
// We could use the iterative method similar to 144. Binary Tree Preorder Traversal
// to calculate the result, then reverse it to get the post order traversal result.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (not root) {
            return {};
        }

        vector<int> res;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            res.push_back(node->val);
            if (node->left) {
                s.push(node->left);
            }

            if (node->right) {
                s.push(node->right);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

private:
};

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

