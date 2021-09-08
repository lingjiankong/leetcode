// Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q. If either node
// p or q does not exist in the tree, return null. All values of the nodes in the tree are unique.
//
// According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a binary tree T
// is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)". A
// descendant of a node x is a node y that is on the path from node x to some leaf node.

// Compare this question with 236. Lowest Common Ancester of a Binary Tree.
// This question does not guarantee that both p and q exist in the tree,
// therefore you need to also return a counter during the recursive call.
// Lowest common ancester only exists if count == 2.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<TreeNode*, int> res = dfs(root, p, q);
        return res.second < 2 ? nullptr : res.first;
    }

private:
    pair<TreeNode*, int> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (not root) {
            return {nullptr, 0};
        }

        pair<TreeNode*, int> l = dfs(root->left, p, q);
        pair<TreeNode*, int> r = dfs(root->right, p, q);

        // You must check it here (postorder) because you need to know the count
        // returned by root's left and right subtrees.
        if (root == p or root == q) {
            return {root, 1 + l.second + r.second};
        }

        if (l.first and r.first) {
            return {root, l.second + r.second};
        } else if (l.first) {
            return l;
        } else if (r.first) {
            return r;
        } else {
            return {nullptr, 0};
        }
    }
};

// Same idea.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = dfs(root, p, q);
        return _count < 2 ? nullptr : res;
    }
private:
    int _count = 0;

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (not root) {
            return nullptr;
        }

        TreeNode* l = dfs(root->left, p, q);
        TreeNode* r = dfs(root->right, p, q);

        if (root == p or root == q) {
            ++_count;
            return root;
        }

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

