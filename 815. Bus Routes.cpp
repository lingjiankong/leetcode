// ***
//
// You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats
// forever.
//
// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7
// -> 1 -> ... forever. You will start at the bus stop source (You are not on any bus initially), and you want to go to
// the bus stop target. You can travel between bus stops by buses only.
//
// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
//
//
//
// Example 1:
//
// Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
// Output: 2
// Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
// Example 2:
//
// Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
// Output: -1
//
//
// Constraints:
//
// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 105
// All the values of routes[i] are unique.
// sum(routes[i].length) <= 105
// 0 <= routes[i][j] < 106
// 0 <= source, target < 106
//
// ***

// Treat bus stops as a graph and BFS on it.
// The difference between this problem and vanilla BFS is that:
// in this problem, when you are expanding a bus stop, you not only expand neighbor of a bus stop. Instead, you look at
// all buses (buses you haven't rided yet) you can ride from that bus stop and add to the queue *all* stops you can
// reach by riding those buses.
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> stop2buses;
        for (int bus = 0; bus < routes.size(); ++bus) {
            for (int stop : routes[bus]) {
                stop2buses[stop].push_back(bus);
            }
        }

        queue<int> q;
        q.push(source);

        unordered_set<int> visited;  // bus stop which you have visited;
        visited.insert(source);

        unordered_set<int> rided;  // bus which you have rided.

        int numBuses = 0;  // number of buses you have rided so far.
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                int stop = q.front();
                q.pop();

                if (stop == target) {
                    return numBuses;
                }

                for (int bus : stop2buses[stop]) {
                    if (not rided.count(bus)) {
                        rided.insert(bus);
                        for (int stop : routes[bus]) {
                            if (not visited.count(stop)) {
                                q.push(stop);
                                visited.insert(stop);
                            }
                        }
                    }
                }
            }
            ++numBuses;
        }

        return -1;
    }
};

