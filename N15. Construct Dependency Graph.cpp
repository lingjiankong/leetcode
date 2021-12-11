/*
    Given a list of dependencies, find a valid execution order.
    For example:
      - Task "A" depends on Task "B" and "C"
      - Task "B" depends on Task "D"
      - Task "C" depends on Task "D"
      - Task "D" has no dependency
    There are two valid orders:
      - "D" -> "C" -> "B" -> "A"
      - "D" -> "B" -> "C" -> "A"
*/

#include <bits/stdc++.h>

using namespace std;

// TODO: Do this question. This question was just copied over.

void dfs(const string& curLib, unordered_map<string, vector<string>>& graph, vector<string>& cur,
         unordered_set<string>& visited) {
    for (const string& depLib : graph[curLib]) {
        if (visited.count(depLib)) {
            continue;
        }

        dfs(depLib, graph, cur, visited);

        cur.push_back(depLib);
        visited.insert(depLib);
    }
}

vector<string> findOrder(const vector<pair<string, string>>& dependency) {
    unordered_map<string, vector<string>> graph;
    for (const pair<string, string>& p : dependency) {
        graph[p.first].push_back(p.second);
    }

    unordered_set<string> visited;
    vector<string> cur;

    string curLib("A");
    visited.insert("A");

    dfs(curLib, graph, cur, visited);

    cur.push_back("A");

    return cur;
}

int main() {
    vector<pair<string, string>> inputs = {{"A", "B"}, {"A", "C"}, {"C", "D"}, {"B", "D"}};

    vector<string> = findOrder(inputs);
    for (const string& lib : output) {
        cout << lib << endl;
    }

    return 0;
}
