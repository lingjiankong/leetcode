// ***
//
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi,
// toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
//
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If
// there is no such route, return -1.
//
//
// Example 1:
//
// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation: The graph is shown.
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
//
//
// Example 2:
//
// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation: The graph is shown.
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
//
//
// Constraints:
//
// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 10^4
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst
//
// ***

// A version in between vanilla BFS (to ensure number of steps) and Djikstra (to track min cost).
// See also N6. Djikstra.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, unordered_set<int>> neighbors;
        unordered_map<int, unordered_map<int, int>> weights;
        for (vector<int>& e : flights) {
            int from = e[0], to = e[1], price = e[2];
            neighbors[from].insert(to);
            weights[from][to] = price;
        }

        unordered_map<int, int> costTo = bfs(neighbors, weights, src, k);

        if (not costTo.count(dst)) {
            return -1;
        }
        return costTo[dst];
    }

private:
    unordered_map<int, int> bfs(unordered_map<int, unordered_set<int>>& neighbors,
                                unordered_map<int, unordered_map<int, int>>& weights, int start, int maxStops) {
        struct NodeState {
            int id;
            int cost;
        };

        unordered_map<int, int> minCostTo;  // min distance from start to each node
        minCostTo[start] = 0;

        // prioirty queue is not necessary, because we might be interested in larger cost with fewer steps.
        queue<NodeState> q;
        q.push({start, 0});

        int numStops = 0;
        while (not q.empty()) {
            if (numStops > maxStops) {
                break;
            }

            int qSize = q.size();
            while (qSize--) {
                NodeState curState = q.front();
                q.pop();

                int curID = curState.id;
                int costToCur = curState.cost;

                // cannot check if (costToCur > minCostTo[curID]) like in Djikstra,
                // because we might be interested in larger cost with fewer steps.

                for (int neighID : neighbors[curID]) {
                    int distToNeigh = costToCur + weights[curID][neighID];

                    // Keep track of minimum distance here.
                    if (not minCostTo.count(neighID) or distToNeigh < minCostTo[neighID]) {
                        minCostTo[neighID] = distToNeigh;
                        q.push({neighID, distToNeigh});
                    }
                }
            }
            ++numStops;
        }

        return minCostTo;
    }
};

// Bellman-Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n, 1e9));
        dp[0][src] = 0;

        // k stops is the same as saying having k + 1 total edges.
        for (int i = 1; i <= k + 1; ++i) {
            dp[i][src] = 0;
            for (vector<int>& e : flights) {
                int from = e[0], to = e[1], price = e[2];
                dp[i][to] = min(dp[i][to], dp[i - 1][from] + price);
            }
        }

        return dp[k + 1][dst] == 1e9 ? -1 : dp[k + 1][dst];
    }
};

