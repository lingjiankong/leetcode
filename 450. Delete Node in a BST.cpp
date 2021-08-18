// ***
//
// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node
// reference (possibly updated) of the BST.
//
// Basically, the deletion can be divided into two stages:
//
// Search for a node to remove.
// If the node is found, delete the node.
//
// Follow up: Can you solve it with time complexity O(height of tree)?
//
// ***

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (not root) {
            return nullptr;
        }

        if (root->val == key) {
            // root is leaf node, just delete it.
            if (not root->left and not root->right) {
                delete root;
                return nullptr;
            }
            // no left subtree, new root becomes root->right.
            else if (not root->left) {
                TreeNode* toReturn = root->right;
                delete root;
                return toReturn;
            }
            // no right subtree, new root becomes root->left.
            else if (not root->right) {
                TreeNode* toReturn = root->left;
                delete root;
                return toReturn;
            }
            // Has both subtrees. In this case, to preserve the property of BST, root needs to find the min value in the
            // right subtree OR the max value in the left subtree to replace itself. We choose to find the min node in
            // the right subtree.
            else {
                TreeNode* minNode = getMinNode(root->right);
                root->val = minNode->val;
                // Note you have to do this here instead of naively "delete minNode"
                // Think about the case that all nodes in right subtree only have right children (like a linked list)
                root->right = deleteNode(root->right, minNode->val);
                return root;
            }
        }

        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }

private:
    // Leftmost node is the min node in a BST
    TreeNode* getMinNode(TreeNode* root) {
        if (not root->left) {
            return root;
        }

        return getMinNode(root->left);
    }
};
