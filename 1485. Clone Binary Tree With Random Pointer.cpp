// ***
//
// A binary tree is given such that each node contains an additional random pointer which could point to any node in the
// tree or null.
//
// Return a deep copy of the tree.
//
// The tree is represented in the same input/output way as normal binary trees where each node is represented as a pair
// of [val, random_index] where:
//
// val: an integer representing Node.val
// random_index: the index of the node (in the input) where the random pointer points to, or null if it does not point
// to any node. You will be given the tree in class Node and you should return the cloned tree in class NodeCopy.
// NodeCopy class is just a clone of Node class with the same attributes and constructors.
//
// ***

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> m;
        return dfs(root, m);
    }

private:
    NodeCopy* dfs(Node* root, unordered_map<Node*, NodeCopy*>& m) {
        if (not root) {
            return nullptr;
        }

        if (m.count(root)) {
            return m[root];
        }

        NodeCopy* clone = new NodeCopy(root->val);
        m[root] = clone;

        clone->left = dfs(root->left, m);
        clone->right = dfs(root->right, m);
        clone->random = dfs(root->random, m);

        return clone;
    }
};

