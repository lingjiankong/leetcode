// ***
//
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
//
// ***
//
// Similar questions:
// 314. Binary Tree Vertical Order Traversal
// 366. Find Leaves of Binary Tree

// DFS solution.
// Uses preorder traversal to take care of current node first then its subtrees.
// Using preorder might be a bit more intuitive, but actually in the DFS solution for this question,
// it doesn't matter if you use preorder, inorder, or postorder traversal.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        _dfs(root, level);
        return _levels;
    }

private:
    // Store nodes of the same value.
    vector<vector<int>> _levels;

    void _dfs(TreeNode* root, int level) {
        if (!root) {
            return;
        }

        while (_levels.size() <= level) {
            _levels.push_back({});
        }

        _levels[level].push_back(root->val);

        _dfs(root->left, level + 1);
        _dfs(root->right, level + 1);
    }
};

// BFS solution, only one queue.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> levels;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> curLevel;
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

            levels.push_back(curLevel);
        }

        return levels;
    }
};

// BFS solution, two queues.
// Similar question that uses the idea: 116. Populating Next Right Pointers in Each Node.
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<vector<int>> levels;

    vector<TreeNode*> curLevel = {root};
    vector<TreeNode*> nextLevel = {};

    while (!curLevel.empty()) {
        levels.push_back({});

        for (auto& node : curLevel) {
            levels.back().push_back(node->val);

            if (node->left) {
                nextLevel.push_back(node->left);
            }
            if (node->right) {
                nextLevel.push_back(node->right);
            }
        }

        curLevel.swap(nextLevel);
        nextLevel.clear();
    }

    return levels;
}

