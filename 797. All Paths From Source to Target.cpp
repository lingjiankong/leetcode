// ***
//
// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node
// n - 1 and return them in any order. The graph is given as follows: graph[i] is a list of all nodes you can visit from
// node i (i.e., there is a directed edge from node i to node graph[i][j]).
//
// Example 1:
//
// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
//
// ***

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curPath;
        vector<vector<int>> allPaths;

        // Since we are given a DAG (no cycle), there is no need to maintain "visited".

        int start = 0;
        int target = graph.size() - 1;
        dfs(graph, start, target, curPath, allPaths);
        return allPaths;
    }

private:
    void dfs(vector<vector<int>>& graph, int curNode, int target, vector<int> curPath, vector<vector<int>>& allPaths) {
        curPath.push_back(curNode);

        if (curNode == target) {
            allPaths.push_back(curPath);
            return;
        }

        for (int neighNode : graph[curNode]) {
            dfs(graph, neighNode, target, curPath, allPaths);
        }

        // Since we are given a DAG (no cycle), there is no need pop curNode from curPath.
    }
};
