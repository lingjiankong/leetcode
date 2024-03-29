// ***
//
// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.
//
// ***
//
// Compare this question with 104. Maximum Depth of Binary Tree,

// Postorder
// Note: A leaf is a node with no children (no left chidren and no right children).
// The extra if conditions in this problem checks if a node has only one subtree.
int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftMinDepth = minDepth(root->left);
    int rightMinDepth = minDepth(root->right);

    // If only one subtree exist (either left or right subtree), then we must look into that subtree that exists,
    // otherwise, the null subtree (the subtree that doesn't exist) will return 0, and you will falsely conclude that a
    // node which only has one subtree has minimum depth of 0.
    if (!root->left && !root->right) {
        return 1;
    }
    if (!root->left && root->right) {
        return 1 + rightMinDepth;
    }
    if (root->left && !root->right) {
        return 1 + leftMinDepth;
    }

    // Both subtrees exist
    return 1 + min(leftMinDepth, rightMinDepth);
}

// DFS, maintain global variable
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (not root) {
            return 0;
        }

        dfs(root, 1);
        return _minDepth;
    }

private:
    void dfs(TreeNode* root, int depth) {
        // Find a leaf node, update _minDepth.
        if (not root->left and not root->right) {
            _minDepth = min(_minDepth, depth);
        }

        if (root->left) {
            dfs(root->left, depth + 1);
        }

        if (root->right) {
            dfs(root->right, depth + 1);
        }
    }

    int _minDepth = INT_MAX;
};

// BFS
// start: the root node
// goal: the first node with no children
int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);

    int depth = 1;
    while (!q.empty()) {
        int qSize = q.size();
        while (qSize--) {
            TreeNode* node = q.front();
            q.pop();

            // Goal found.
            if (!node->left && !node->right) {
                return depth;
            }

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }
        ++depth;
    }

    return depth;
}
