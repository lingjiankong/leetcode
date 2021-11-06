// ***
//
// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then
// right to left for the next level and alternate between).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
//
// ***
//
// Just 102. Binary Tree Level Order Traversal with a leftToRight bool.
// There are methods that you don't need to reverse currentLevel, for example,
// change the order of pushing back to nextLevel depending on current leftToRight flag.
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        vector<int> currentLevel;
        int currentLevelSize = q.size();

        for (int i = 0; i < currentLevelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        if (!leftToRight) {
            reverse(currentLevel.begin(), currentLevel.end());
        }

        res.push_back(currentLevel);

        leftToRight = !leftToRight;
    }

    return res;
}
