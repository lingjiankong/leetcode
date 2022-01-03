/*
    Given a list of dependencies, find a valid execution order.
    For example:
      - Task "A" depends on Task "B" and "C"
      - Task "B" depends on Task "E"
      - Task "C" depends on Task "D"
      - Task "D" depends on Task "E"
      - Task "E" has no dependency
    There are three valid orders:
      - E -> D -> B -> C -> A
      - E -> D -> C -> B -> A
      - E -> B -> D -> C -> A


    Dependency tree:

         A
        / \
       B   C
        \   \
         \   D
          \ /
           E
*/

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Postorder traverse the grpah.
class DFS {
public:
    vector<string> findOrder(const vector<pair<string, string>>& dependency) {
        unordered_map<string, vector<string>> graph;
        for (const pair<string, string>& p : dependency) {
            graph[p.first].push_back(p.second);  // p.first -> p.second
        }

        vector<string> path;
        unordered_set<string> visited;
        dfs("A", graph, path, visited);

        return path;
    }

private:
    void dfs(const string& curLib, unordered_map<string, vector<string>>& graph, vector<string>& path,
             unordered_set<string>& visited) {
        if (visited.count(curLib)) {
            return;
        }
        visited.insert(curLib);

        for (const string& depLib : graph[curLib]) {
            dfs(depLib, graph, path, visited);
        }

        // You have finished traversing curLib. Push it to path (postorder)
        path.push_back(curLib);
    }
};

int main() {
    vector<pair<string, string>> inputs = {{"A", "B"}, {"A", "C"}, {"C", "D"}, {"D", "E"}, {"B", "E"}};

    DFS dfs;
    vector<string> output = dfs.findOrder(inputs);
    for (const string& lib : output) {
        cout << lib << endl;  // Expect: E B D C A
    }

    return 0;
}

