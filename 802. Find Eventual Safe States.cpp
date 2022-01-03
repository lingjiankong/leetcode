// ***
//
// We start at some node in a directed graph, and every turn, we walk along a directed edge of the graph. If we reach a
// terminal node (that is, it has no outgoing directed edges), we stop.
//
// We define a starting node to be safe if we must eventually walk to a terminal node. More specifically, there is a
// natural number k, so that we must have stopped at a terminal node in less than k steps *for any choice of where to
// walk*.
//
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
//
// The directed graph has n nodes with labels from 0 to n - 1, where n is the length of graph. The graph is given in the
// following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph, going from node i to
// node j.
//
// ***

// This question is essentially asking us to return all nodes, starting from where has no cycles.
// You can do this question similar to how you did 207. Course Schedule using vanilla topological sort.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<State> states(graph.size(), UNVISITED);
        for (int i = 0; i < graph.size(); ++i) {
            if (dfs(i, states, graph) == NO_CYCLE) {
                ans.push_back(i);
            }
        }

        return ans;
    }

private:
    // VISITED is split into HAS_CYCLE and NO_CYCLE.
    enum State { UNVISITED, VISITING, HAS_CYCLE, NO_CYCLE };

    State dfs(int curNode, vector<State>& states, const vector<vector<int>>& graph) {
        if (states[curNode] == VISITING) {  // has cycle
            return states[curNode] = HAS_CYCLE;
        }

        if (states[curNode] == NO_CYCLE or states[curNode] == HAS_CYCLE) {
            return states[curNode];
        }

        states[curNode] = VISITING;
        for (int neighNode : graph[curNode]) {
            // if any of the neighNode is HAS_CYCLE, then curNode is HAS_CYCLE.
            if (dfs(neighNode, states, graph) == HAS_CYCLE) {
                return states[curNode] = HAS_CYCLE;
            }
        }
        return states[curNode] = NO_CYCLE;
    }
};

