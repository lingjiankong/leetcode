// ***
//
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where
// heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you
// hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or
// right, and you wish to find a route that requires the minimum effort.
//
// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
//
// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
//
//
// Example 1:
//
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
//
//
// Example 2:
//
// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better
// than route [1,3,5,3,5].
//
//
// Example 3:
//
// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.
//
//
// Constraints:
//
// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106
//
// ***

// Slight modification based on N6. Djikstra. See comments.
template <typename T>
unordered_map<T, int> dijkstra(unordered_map<T, unordered_set<T>>& neighbors,
                               unordered_map<T, unordered_map<T, int>>& weights, T start) {
    struct NodeState {
        T id;
        int effort;
    };

    unordered_map<T, int> minEffortTo;
    minEffortTo[start] = 0;

    auto compare = [](const NodeState& a, const NodeState& b) { return a.effort > b.effort; };
    priority_queue<NodeState, vector<NodeState>, decltype(compare)> pq(compare);
    pq.push({start, 0});

    while (not pq.empty()) {
        NodeState curState = pq.top();
        pq.pop();

        T curID = curState.id;
        int effortToCur = curState.effort;

        if (minEffortTo.count(curID) and effortToCur > minEffortTo[curID]) {
            continue;
        }

        for (T neighID : neighbors[curID]) {
            // Here is the only difference to vanilla Djikstra:
            // Notice we are taking the max of efforts instead of accumulating them.
            int effortToNeigh = max(effortToCur, weights[curID][neighID]);

            if (not minEffortTo.count(neighID) or effortToNeigh < minEffortTo[neighID]) {
                minEffortTo[neighID] = effortToNeigh;
                pq.push({neighID, effortToNeigh});
            }
        }
    }

    return minEffortTo;
}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        unordered_map<string, unordered_set<string>> neighbors;
        unordered_map<string, unordered_map<string, int>> weights;
        _construct(heights, neighbors, weights);

        string start = "0,0";
        string goal = to_string(heights.size() - 1) + "," + to_string(heights[0].size() - 1);
        unordered_map<string, int> effortTo = dijkstra<string>(neighbors, weights, "0,0");
        return effortTo[goal];
    }

private:
    // Construct a graph to use Djikstra.
    void _construct(vector<vector<int>>& heights, unordered_map<string, unordered_set<string>>& neighbors,
                    unordered_map<string, unordered_map<string, int>>& weights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                string curPos = to_string(i) + "," + to_string(j);
                for (auto& dir : dirs) {
                    int neighX = i + dir[0], neighY = j + dir[1];
                    string neighPos = to_string(neighX) + "," + to_string(neighY);
                    if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n) {
                        neighbors[curPos].insert(neighPos);
                        weights[curPos][neighPos] = abs(heights[i][j] - heights[neighX][neighY]);
                    }
                }
            }
        }
    }
};
