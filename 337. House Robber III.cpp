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
    int rob(TreeNode* root) { return _dfs(root); }

private:
    // Cache max amount of money each node can have.
    unordered_map<TreeNode*, int> _hash;

    int _dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (_hash.count(root)) {
            return _hash[root];
        }

        // Amount of money we can have if we rob current node.
        int moneyRobCurrent = root->val;
        if (root->left) {
            moneyRobCurrent += _dfs(root->left->left) + _dfs(root->left->right);
        }
        if (root->right) {
            moneyRobCurrent += _dfs(root->right->left) + _dfs(root->right->right);
        }

        // Amount of money we can have if we do not rob current node.
        int moneyDoNotRobCurrent = _dfs(root->left) + _dfs(root->right);

        // Return max amount of money we can have in this node.
        int maxMoney = max(moneyRobCurrent, moneyDoNotRobCurrent);
        return _hash[root] = maxMoney;
    }
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
        if (!root) {
            return {0, 0};
        }

        array<int, 2> leftChild = _dfs(root->left);
        array<int, 2> rightChild = _dfs(root->right);

        // If you rob current root, you cannot rob the left and right child.
        int robCurrentRoot = root->money + leftChild[1] + rightChild[1];

        // If you do not rob current root, you can either rob or don't rob your left and right child.
        int notRobCurrentRoot = max(leftChild[0], leftChild[1]) + max(rightChild[0], rightChild[1]);

        return {robCurrentRoot, notRobCurrentRoot};
    }
};
