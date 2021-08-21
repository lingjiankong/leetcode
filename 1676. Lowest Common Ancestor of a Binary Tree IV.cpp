// Given the root of a binary tree and an array of TreeNode objects nodes, return the lowest common ancestor (LCA) of
// all the nodes in nodes. All the nodes will exist in the tree, and all values of the tree's nodes are unique.
//
// Extending the definition of LCA on Wikipedia: "The lowest common ancestor of n nodes p1, p2, ..., pn in a binary tree
// T is the lowest node that has every pi as a descendant (where we allow a node to be a descendant of itself) for every
// valid i". A descendant of a node x is a node y that is on the path from node x to some leaf node.

// Generalization of 236. Lowest Common Ancester of a Binary Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if (not root) {
            return nullptr;
        }

        for (auto node : nodes) {
            if (root == node) {
                return root;
            }
        }

        TreeNode* l = lowestCommonAncestor(root->left, nodes);
        TreeNode* r = lowestCommonAncestor(root->right, nodes);
 
        if (l and r) {
            return root;
        } else if (l) {
            return l;
        } else if (r) {
            return r;
        } else {
            return nullptr;
        }
    }
};
