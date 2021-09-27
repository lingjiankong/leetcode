// ***
//
// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array
// graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there
// is an undirected edge between node u and node v. The graph has the following properties:
//
// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the
// graph connects a node in set A and a node in set B.
//
// Return true if and only if it is bipartite.
//
//
// Example 1:
//
// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in
// one and a node in the other.
//
//
// Example 2:
//
// Input: graph = [[1,3],[0,2],[1,3],[0,2]]
// Output: true
// Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
//
//
// Constraints:
//
// graph.length == n
// 1 <= n <= 100
// 0 <= graph[u].length < n
// 0 <= graph[u][i] <= n - 1
// graph[u] does not contain u.
// All the values of graph[u] are unique.
// If graph[u] contains v, then graph[v] contains u.
//
// ***

// For bipartile types of questions:
// Traverse all nodes, recursively color the node itself blue (1) and all its neighbor nodes red (-1).
// If you are able to successfully do it for all nodes in the graph, then the graph is bipartite.
// Otherwise, if you see a conflict, then the graph is not bipartite.
// See https://youtu.be/VlZiMD7Iby4
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());

        for (int i = 0; i < graph.size(); ++i) {
            if (not colors[i]) {  // only traverse nodes which have not been colored.
                if (not coloring(i, 1, graph, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool coloring(int curNode, int curColor, const vector<vector<int>>& graph, vector<int>& colors) {
        // if colors[curNode] == curColor, you have already visited curNode and it is colored as expected, return true
        // if colors[curNode] != curColor, you have already visited curNode and it is NOT colored as expected,
        // which means there is a conflict. Return false.
        if (colors[curNode]) {
            return colors[curNode] == curColor;
        }

        colors[curNode] = curColor;

        for (int neighNode : graph[curNode]) {
            if (not coloring(neighNode, -curColor, graph, colors)) {
                return false;
            }
        }

        return true;
    }
};
