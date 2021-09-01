// ***
//
// Given an n-ary tree, return the level order traversal of its nodes' values.
//
// Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by
// the null value (See examples).
//
// Example 1:
//
// Input: root = [1,null,3,2,4,null,5,6]
// Output: [[1],[3,2,4],[5,6]]
//
//
// Example 2:
//
// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
//
//
// Constraints:
//
// The height of the n-ary tree is less than or equal to 1000
// The total number of nodes is between [0, 10^4]
//
// ***

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// Recursive
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (not root) {
            return {};
        }

        preorder(root, 0);

        return _ans;
    }

private:
    vector<vector<int>> _ans;

    void preorder(Node* root, int level) {
        while (_ans.size() <= level) {
            _ans.push_back({});
        }

        _ans[level].push_back({root->val});

        for (const auto& child : root->children) {
            preorder(child, level + 1);
        }
    }
};

// Iterative
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (not root) {
            return {};
        }

        queue<Node*> q;
        q.push(root);

        vector<vector<int>> allLevels;
        while (not q.empty()) {
            int qSize = q.size();
            vector<int> curLevel;

            while (qSize--) {
                Node* node = q.front();
                q.pop();
                curLevel.push_back(node->val);

                for (const auto& child : node->children) {
                    q.push(child);
                }
            }

            allLevels.push_back(curLevel);
        }

        return allLevels;
    }
};
