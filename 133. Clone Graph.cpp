// ***
//
// Given a reference of a node in a connected undirected graph.
//
// Return a deep copy (clone) of the graph.
//
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
//
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
//
//
// Test case format:
//
// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val
// == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
//
// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of
// neighbors of a node in the graph.
//
// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference
// to the cloned graph.
//
// ***

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// DFS
// See "deep-copy" type questions. All of these questions use the same method.
class Solution {
public:
    Node* cloneGraph(Node* node) {
        // original node : cloned node
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& m) {
        if (not node) {
            return nullptr;
        }

        if (m.count(node)) {
            return m[node];
        }

        Node* clone = new Node(node->val);
        m[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, m));
        }

        return clone;
    }
};


// BFS. Making sense of BFS solution is sufficient.
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (not node) {
            return nullptr;
        }

        // original node : cloned node
        unordered_map<Node*, Node*> m;

        queue<Node*> q;
        q.push(node);

        Node* clone = new Node(node->val);
        m[node] = clone;

        while (not q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (Node* neighbor : cur->neighbors) {
                if (not m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[cur]->neighbors.push_back(m[neighbor]);
            }

        }

        return clone;
    }
};

