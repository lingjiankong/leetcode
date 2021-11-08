// ***
//
// The thief has found himself a new place for his thievery again.
// There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent
// house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will
// automatically contact the police if two directly-linked houses were broken into on the same night.
//
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
// Example 1:
//
// Input: [3,2,3,null,3,null,1]
//
//      3
//     / \
//    2   3
//     \   \
//      3   1
//
// Output: 7
//
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
// ***

class Solution {
public:
    // Max amount of money you can get from a tree rooted at root
    // (you can either rob root, or not rob root)
    int rob(TreeNode* root) {
        if (not root) {
            return 0;
        }

        if (_hash.count(root)) {
            return _hash[root];
        }

        // Amount of money we can have if we rob current node.
        int robCur = root->val;
        if (root->left) {
            robCur += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            robCur += rob(root->right->left) + rob(root->right->right);
        }

        // Amount of money we can have if we do NOT rob current node.
        int notRobCur = rob(root->left) + rob(root->right);

        // Return max amount of money we can have in this node.
        int maxMoney = max(robCur, notRobCur);
        return _hash[root] = maxMoney;
    }

private:
    // Cache max amount of money each node can have.
    // a cache is needed because we might be visiting the same node multiple times (rob is called six times above)
    unordered_map<TreeNode*, int> _hash;
};

class Solution {
public:
    int rob(TreeNode* root) {
        // Frist element in array: Amount of money we could get from the tree if we rob this root.
        // Second element in array: Amount of money we could get from the tree if we do not rob this root.
        array<int, 2> robOrNot = _dfs(root);

        return max(robOrNot[0], robOrNot[1]);
    }

private:
    array<int, 2> _dfs(TreeNode* root) {
        if (not root) {
            return {0, 0};
        }

        array<int, 2> l = _dfs(root->left);
        array<int, 2> r = _dfs(root->right);

        // If you rob current root, you cannot rob the left and right child.
        int robCur = root->val + l[1] + r[1];

        // If you do not rob current root, you can either rob, or not rob your left and right child.
        int notRobCur = max(l[0], l[1]) + max(r[0], r[1]);

        return {robCur, notRobCur};
    }
};
