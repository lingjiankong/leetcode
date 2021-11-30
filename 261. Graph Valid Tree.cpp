// ***
//
// You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] =
// [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.
//
// Return true if the edges of the given graph make up a valid tree, and false otherwise.
//
// ***

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind<int> uf;

        for (int i = 0; i < n; ++i) {
            uf.add(i);
        }

        for (vector<int>& edge : edges) {
            int p = edge[0], q = edge[1];

            // You cannot constraint p and q with another edge if they are already connected (i.e. share the same root).
            // In this case, this is not a valid graph.
            if (uf.isConnected(p, q)) {
                return false;
            }

            uf.connect(p, q);
        }

        return uf.numClusters() == 1;
    }
};
