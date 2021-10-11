// ***
//
// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival
// airports of one flight. Reconstruct the itinerary in order and return it.
//
// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are
// multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single
// string.
//
// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
//
//
//
// Example 1:
//
//
// Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
// Output: ["JFK","MUC","LHR","SFO","SJC"]
// Example 2:
//
//
// Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical
// order.
//
//
// Constraints:
//
// 1 <= tickets.length <= 300
// tickets[i].length == 2
// fromi.length == 3
// toi.length == 3
// fromi and toi consist of uppercase English letters.
// fromi != toi
//
// ***

// Not an intuitive question.
// Convert the graph to a tree and do post-order traversal.
// Note that the problem states that a solution is guaranteed to exist.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> tickets) {
        // Construct graph, use multiset so children is sorted in lexical order.
        unordered_map<string, multiset<string>> children;
        for (auto ticket : tickets) {
            children[ticket[0]].insert(ticket[1]);
        }

        vector<string> route;
        dfs(children, "JFK", route);

        // Postorder traversal returns the leaf node (destination) as the first element,
        // therefore we need to reverse it.
        return vector<string>(route.rbegin(), route.rend());
    }

private:
    void dfs(unordered_map<string, multiset<string>>& children, string root, vector<string>& route) {
        while (children[root].size()) {
            string child = *children[root].begin(); // left most element is the lexical first one.
            children[root].erase(children[root].begin());
            dfs(children, child, route);
        }

        route.push_back(root);
    }
};

