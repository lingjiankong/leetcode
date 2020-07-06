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
        return _listOfLevels;
    }

private:
    vector<vector<int>> _listOfLevels;

    void _dfs(TreeNode* root, int level) {
        if (!root) {
            return;
        }

        while (_listOfLevels.size() <= level) {
            _listOfLevels.push_back({});
        }

        _listOfLevels[level].push_back(root->val);

        _dfs(root->left, level + 1);
        _dfs(root->right, level + 1);
    }
};

// BFS solution.
// Similar question that uses the idea: 116. Populating Next Right Pointers in Each Node.
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<vector<int>> listOfLevels;

    vector<TreeNode*> currentLevel = {root};
    vector<TreeNode*> nextLevel = {};

    while (!currentLevel.empty()) {
        listOfLevels.push_back({});

        for (auto node : currentLevel) {
            listOfLevels.back().push_back(node->val);

            if (node->left) {
                nextLevel.push_back(node->left);
            }
            if (node->right) {
                nextLevel.push_back(node->right);
            }
        }

        currentLevel.swap(nextLevel);
        nextLevel.clear();
    }

    return listOfLevels;
}

// BFS solution, only one queue.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> listOfLevels;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            vector<int> currentLevel;
            int currentLevelSize = nodeQueue.size();

            for (int i = 0; i < currentLevelSize; ++i) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();

                currentLevel.push_back(node->val);

                if (node->left) {
                    nodeQueue.push(node->left);
                }

                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }

            listOfLevels.push_back(currentLevel);
        }

        return listOfLevels;
    }
};

