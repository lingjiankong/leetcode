// ***
//
// You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where
// graph[i] is a list of all the nodes connected with node i by an edge. Return the length of the shortest path that
// visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
//
//
// Example 1:
//
// Input: graph = [[1,2,3],[0],[0],[0]]
// Output: 4
// Explanation: One possible path is [1,0,2,0,3]
//
//
// Example 2:
//
// Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
// Output: 4
// Explanation: One possible path is [0,1,4,2,3]
//
//
// Constraints:
//
// n == graph.length
// 1 <= n <= 12
// 0 <= graph[i].length < n
// graph[i] does not contain i.
// If graph[a] contains b, then graph[b] contains a.
// The input graph is always connected.
//
// ***

// Because we are told 1 <= n <= 12, we can use bits to represent the state of
// which nodes have been visited. For example, if n = 4, then 0x1111 represented that we've visited all nodes.
// Think of this problem like converting 1D BFS (id,) to 2D BFS (id, visited)
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        struct nodeState {
            int id;
            int visited;  // nodes you have visited so far
        };

        int n = graph.size();  // number of nodes

        // Goal of the BFS: all nodes have been visited, e.g. if n = 4, allVisited = 0x10000 - 1 = 0x1111
        int allVisited = (1 << n) - 1;

        queue<nodeState> q;
        // 2D BFS, therefore 2 different states.
        unordered_map<int, unordered_set<int>> visited;

        for (int i = 0; i < n; ++i) {   // every node can be a start node.
            int initialState = 1 << i;  // only the starting node has been visited.
            q.push({i, initialState});
            visited[i].insert(initialState);
        }

        int steps = 0;
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                nodeState cur = q.front();
                q.pop();

                int curID = cur.id;
                int curVisited = cur.visited;

                if (curVisited == allVisited) {  // the first time you reach 0x1111 is when you've visited all nodes.
                    return steps;
                }

                for (int neighID : graph[curID]) {
                    int newState = curVisited | 1 << neighID;  // e.g. 0x1101 = 0x1001 | 1 << 2
                    if (not visited[neighID].count(newState)) {
                        q.push({neighID, newState});
                        visited[neighID].insert(newState);
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};

