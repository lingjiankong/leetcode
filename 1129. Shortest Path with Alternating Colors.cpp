// ***
//
// Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge is either red or blue, and
// there could be self-edges or parallel edges.
//
// Each [i, j] in red_edges denotes a red directed edge from node i to node j. Similarly, each [i, j] in blue_edges
// denotes a blue directed edge from node i to node j.
//
// Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X
// such that the edge colors alternate along the path (or -1 if such a path doesn't exist).
//
//
// Example 1:
// Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
// Output: [0,1,-1]
//
//
// Example 2:
// Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
// Output: [0,1,-1]
//
//
// Example 3:
// Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
// Output: [0,-1,-1]
//
//
// Example 4:
// Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
// Output: [0,1,2]
//
//
// Example 5:
// Input: n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
// Output: [0,1,1]
//
//
// Constraints:
//
// 1 <= n <= 100
// red_edges.length <= 400
// blue_edges.length <= 400
// red_edges[i].length == blue_edges[i].length == 2
// 0 <= red_edges[i][j], blue_edges[i][j] < n
//
// ***

// A special form of BFS, just remember the solution to these types of problems.
// The idea is to construct two graphs for red and blue edges but maintain a single queue. See comments.
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> red_graph(n);  // graph formed by red edges
        for (vector<int>& edge : red_edges) {
            red_graph[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> blue_graph(n);  // graph formed by blue edges
        for (vector<int>& edge : blue_edges) {
            blue_graph[edge[0]].push_back(edge[1]);
        }

        // first element: node; second element: how you traversed to this node, where 1 indicates you've traversed to
        // this node via a red edge, and 0 indicates you've traversed to this node via a blue edge.
        queue<vector<int>> q;
        q.push({0, 1});  // traversed to 0 via a red edge
        q.push({0, 0});  // traversed to 0 via a blue edge

        unordered_set<int> red_visited;  // visited in red graph
        red_visited.insert(0);

        unordered_set<int> blue_visited;  // visited in blue graph
        blue_visited.insert(0);

        vector<int> ans(n, -1);  // return -1 if a path does not exist.

        int steps = 0;
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                vector<int> cur = q.front();
                q.pop();

                int node = cur[0];
                bool from_red = cur[1];  // if we traversed to this node from a red node

                ans[node] = ans[node] == -1 ? steps : min(steps, ans[node]);

                // if we traversed here via a red edge, then we should traverse the blue graph, and vice versa.
                vector<vector<int>>& graph = from_red ? blue_graph : red_graph;
                unordered_set<int>& visited = from_red ? blue_visited : red_visited;
                for (int neighNode : graph[node]) {
                    if (not visited.count(neighNode)) {
                        q.push({neighNode, 1 - from_red});  // edge is flipped
                        visited.insert(neighNode);
                    }
                }
            }
            ++steps;
        }

        return ans;
    }
};
