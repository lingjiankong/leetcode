// ***
//
// Given the root of a binary tree, return the sum of values of its deepest leaves.
//
//
// Example 1:
//
// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// Output: 15
//
//
// Example 2:
//
// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 19
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [1, 10^4].
// 1 <= Node.val <= 100
//
// ***

// Iterative
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (not root) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<int> curLevel;
        while (not q.empty()) {
            curLevel.clear();
            int qSize = q.size();

            while (qSize--) {
                TreeNode* node = q.front();
                q.pop();

                curLevel.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        // Last curLevel are the deepest leaves.
        int sum = 0;
        for (int val : curLevel) {
            sum += val;
        }
        return sum;
    }
};

// Recursive
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        _preorder(root, 0);
        return _sum;
    }

private:
    int _maxDepth = 0;
    int _sum = 0;

    void _preorder(TreeNode* root, int depth) {
        if (not root) {
            return;
        }

        if (depth > _maxDepth) {
            _maxDepth = depth;
            _sum = 0;
        }

        if (depth == _maxDepth) {
            _sum += root->val;
        }

        _preorder(root->left, depth + 1);
        _preorder(root->right, depth + 1);
    }
};

