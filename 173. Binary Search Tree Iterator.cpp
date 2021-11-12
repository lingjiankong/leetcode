// ***
//
// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
//
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
// ***

// Given root of a binary search tree, the smallest element is the left most node.
// Given root of a binary search tree, the next element that is bigger than current root is
// the left most node of right subtree of current root.
//
// See also 450. Delete Node in a BST, which applies this property.

class BSTIterator {
public:
    BSTIterator(TreeNode* root) { pushAllLeftNodes(root); }

    bool hasNext() { return !_s.empty(); }

    int next() {
        TreeNode* currentSmallest = _s.top();
        _s.pop();

        pushAllLeftNodes(currentSmallest->right);

        return currentSmallest->val;
    }

private:
    stack<TreeNode*> _s;

    void pushAllLeftNodes(TreeNode* node) {
        while (node) {
            _s.push(node);
            node = node->left;
        }
    }
};
