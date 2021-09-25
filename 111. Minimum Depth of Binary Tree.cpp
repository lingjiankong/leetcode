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

// DFS
// Note: A leaf is a node with no children (no left chidren and no right children).
// The extra if conditions in this problem checks if a node has only one subtree.
int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    // If only one subtree exist (either left or right subtree), then we must look into that subtree that exists,
    // otherwise, the null subtree (the subtree that doesn't exist) will return 0, and you will falsely conclude that a
    // node which only has one subtree has minimum depth of 0.
    if (!root->left && !root->right) {
        return 1;
    }
    if (!root->left && root->right) {
        return 1 + minDepth(root->right);
    }
    if (root->left && !root->right) {
        return 1 + minDepth(root->left);
    }

    // Both subtrees exist
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

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
        for (int i = 0; i < qSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

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
