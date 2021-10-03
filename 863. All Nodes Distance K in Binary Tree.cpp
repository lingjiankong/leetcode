// ***
//
// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values
// of all nodes that have a distance k from the target node. You can return the answer in any order.
//
//
// Example 1:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//
//
// Example 2:
//
// Input: root = [1], target = 1, k = 3
// Output: []
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000
//
// ***

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        buildGraph(root, graph);

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        vector<int> ans;

        int steps = 0;
        while (not q.empty() and steps <= k) {
            int qSize = q.size();
            while (qSize--) {
                TreeNode* cur = q.front();
                q.pop();

                if (steps == k) {
                    ans.push_back(cur->val);
                }

                for (TreeNode* node : graph[cur]) {
                    if (not visited.count(node)) {
                        q.push(node);
                        visited.insert(node);
                    }
                }
            }
            ++steps;
        }

        return ans;
    }

private:
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (not root) {
            return;
        }

        if (root->left) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
        }

        if (root->right) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
        }

        buildGraph(root->left, graph);
        buildGraph(root->right, graph);
    }
};

