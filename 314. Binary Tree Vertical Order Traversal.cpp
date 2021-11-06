// ***
//
// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by
// column).
//
// If two nodes are in the same row and column, the order should be from left to right.
//
// Examples 1:
//
// Input: [3,9,20,null,null,15,7]
//
//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7
//
// Output:
//
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
//
// Examples 2:
//
// Input: [3,9,8,4,0,1,7]
//
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//
// Output:
//
// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]
//
// Examples 3:
//
// Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)
//
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2
//
// Output:
//
// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]
//
// ***
//
// See also 102. Binary Tree Level Order Traversal.
//
// Level order (horizontally) traverse the tree,
// in the queue for level order traversal, also store the current vertical level for each node:
// For a left node, vertical level -= 1,
// for a right node, vertical level += 1.
// Maintain a map<int, vector<int>> verticalLevelToNodes, which stores each vertical level and all nodes at that level.
//
// Why do we need to maintain an tree map verticalLevelToNodes?
// Because unlike horizontal level order, initially you don't know what the "0th" vertial level is,
// so you can't use index to push to vector. We have to traverse through verticalLevelToNodes in the end
// and push each vector at different vertical level to res in the end.

vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) {
        return {};
    }

    map<int, vector<int>> verticalLevelToNodes;

    // Stores node as well as that node's vertical level.
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto nodeToLevel = q.front();
        q.pop();

        TreeNode* node = nodeToLevel.first;
        int verticalLevel = nodeToLevel.second;

        verticalLevelToNodes[verticalLevel].push_back(node->val);

        if (node->left) {
            q.push({node->left, verticalLevel - 1});
        }

        if (node->right) {
            q.push({node->right, verticalLevel + 1});
        }
    }

    vector<vector<int>> res;
    for (vector<int>& element : verticalLevelToNodes) {
        vector<int> sameLevelNodes = element.second;
        res.push_back(sameLevelNodes);
    }

    return res;
}

// DFS
class Solution {
private:
    map<int, map<int, vector<int>>> _table;

    void dfs(TreeNode* root, int i, int j) {
        if (root == nullptr) {
            return;
        }

        _table[j][i].push_back(root->val);
        dfs(root->left, i + 1, j - 1);
        dfs(root->right, i + 1, j + 1);
    }

public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> res;
        for (auto& col : _table) {
            res.emplace_back();
            for (auto& elem : col.second) {
                auto& vec = elem.second;
                res.back().insert(res.back().end(), vec.begin(), vec.end());
            }
        }
        return res;
    }
};
