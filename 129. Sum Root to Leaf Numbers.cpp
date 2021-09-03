// ***
//
// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
//
// Note: A leaf is a node with no children.
//
// Example:
// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
//
// Example 2:
// Input: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.
//
// ***
//
// See also a very similar question: 257. Binary Tree Paths.

class Solution {
public:
    int sumNumbers(TreeNode* root) { return _dfs(root, 0); }

private:
    // Returns the sum from root to leaf whenever we see a leaf node.
    int _dfs(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }

        sum = sum * 10 + root->val;

        if (!root->left && !root->right) {
            return sum;
        }

        return _dfs(root->left, sum) + _dfs(root->right, sum);
    }
};

// Same thing.
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int totalSum = 0;
        int currentSum = 0;

        _dfs(root, currentSum, totalSum);

        return totalSum;
    }

private:
    void _dfs(TreeNode* root, int currentSum, int& totalSum) {
        if (!root) {
            return;
        }

        currentSum = currentSum * 10 + root->val;

        if (!root->left && !root->right) {
            totalSum += currentSum;
        }

        _dfs(root->left, currentSum, totalSum);
        _dfs(root->right, currentSum, totalSum);
    }
};
