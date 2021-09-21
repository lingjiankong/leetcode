// ***
//
// Given a root of an N-ary tree, return a deep copy (clone) of the tree.
//
// Each node in the n-ary tree contains a val (int) and a list (List[Node]) of its children.
//
// class Node {
//     public int val;
//     public List<Node> children;
// }
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

class Solution {
public:
    Node* cloneTree(Node* root) {
        unordered_map<Node*, Node*> m;
        return dfs(root, m);
    }

private:
    Node* dfs(Node* root, unordered_map<Node*, Node*>& m) {
        if (not root) {
            return nullptr;
        }

        if (m.count(root)) {
            return m[root];
        }

        Node* clone = new Node(root->val);
        m[root] = clone;

        for (Node* child : root->children) {
            clone->children.push_back(dfs(child, m));
        }

        return clone;
    }
};
