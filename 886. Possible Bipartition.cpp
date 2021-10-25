// ***
//
// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some
// other people, and they should not go into the same group.
//
// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not
// like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
//
//
// Example 1:
//
// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4] and group2 [2,3].
//
//
// Example 2:
//
// Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
//
//
// Example 3:
//
// Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false
//
//
// Constraints:
//
// 1 <= n <= 2000
// 0 <= dislikes.length <= 10^4
// dislikes[i].length == 2
// 1 <= dislikes[i][j] <= n
// ai < bi
// All the pairs of dislikes are unique.
//
// ***

// See 785. Is Graph Bipartite for explanation.
// Solution is exactly the same.
// DFS
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);

        for (int i = 0; i < dislikes.size(); ++i) {
            // Minus 1 is needed since dislikes are 1-based, graph is 0-based.
            graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }

        vector<int> colors(n);
        for (int i = 0; i < n; ++i) {
            if (not colors[i]) {
                if (not coloring(i, 1, graph, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool coloring(int curNode, int curColor, const vector<vector<int>>& graph, vector<int>& colors) {
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

// BFS
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < dislikes.size(); ++i) {
            graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }

        queue<int> q;
        vector<int> colors(n, 0);

        // Traverse all nodes in the graph in case there are nodes that are not connected. 
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] != 0) {
                continue; 
            }

            q.push(i); 
            colors[i] = 1; 

            while (not q.empty()) {
                int cur = q.front();
                q.pop(); 
                for (int neigh : graph[cur]) {
                    if (colors[neigh] == colors[cur]) {
                        return false;
                    }
                    
                    if (colors[neigh] == 0) {
                        colors[neigh] = -colors[cur];
                        q.push(neigh);
                    }
                }
            }
        }
     
        return true; 
    }
};

