// ***
//
// Given two binary trees, write a function to check if they are the same or not.
//
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
// Example 1:
//
// Input:     1         1
//           / \       / \
//          2   3     2   3
//
//         [1,2,3],   [1,2,3]
//
// Output: true
// Example 2:
//
// Input:     1         1
//           /           \
//          2             2
//
//         [1,2],     [1,null,2]
//
// Output: false
// Example 3:
//
// Input:     1         1
//           / \       / \
//          2   1     1   2
//
//         [1,2,1],   [1,1,2]
//
// Output: false
//
// ***

bool isSameTree(TreeNode* p, TreeNode* q) {
    // Both nodes are empty: same.
    if (!p and !q) {
        return true;
    }

    // Only one of the node is empty: not the same.
    if (!p or !q) {
        return false;
    }

    // Both nodes are non-empty but have different values: not the same.
    if (p->val != q->val) {
        return false;
    }

    // Otherwise, both nodes are non-empty and nodes have the same values,
    // then recursively check if left subtrees and right subtrees are equal to each other.
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
