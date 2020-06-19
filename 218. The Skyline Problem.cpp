// ***
//
// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a
// distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo
// (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
//
// See leetcode website for figures.
//
// Buildings Skyline Contour
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are
// the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is
// guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect
// rectangles grounded on an absolutely flat surface at height 0.
//
// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20
// 10], [19 24 8] ] .
//
// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ]
// that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last
// key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has
// zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
//
// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8],
// [24, 0] ].
//
// Notes:
//
// The number of buildings in any input list is guaranteed to be in the range [0, 10000].
// The input list is already sorted in ascending order by the left x position Li.
// The output list must be sorted by the x position.
// There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5],
// [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final
// output as such: [...[2 3], [4 5], [12 7], ...]
//
// ***
//
// This is an interesting problem and it is not hard to understand.
//
// Interest point occurs only on the edge (either left edge or right edge). Everytime you see an edge of a building, you
// would like to know whether an interst point lay somewhere along that edge.
//
// When you see a left edge (represented using a negative height so you can tell that you are seeing a left edge rather
// than a right edge), you add the height of that left edge to current_left_edges. When you see a right edge, you pop
// the corresponding left edge from current_left_edges because that building is now done and you will no longer see it
// as you continue going right.
//
// If you sweep from left to right, everytime when current_max_left_edge is different from previous_max_left_edge, an
// interst point exist (you can look at the graph and walk through the algorithm, it is very staightforward).

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        // Stores (x, y) of all building edges in ascending order
        // (y is positive for right edge; y is negative for left edge).
        vector<vector<int>> heights;
        for (auto building : buildings) {
            heights.push_back({building[0], -building[2]});
            heights.push_back({building[1], building[2]});
        }
        sort(heights.begin(), heights.end());

        // Height of the left edges of buildings you are currently on.
        // Insert 0 as the only left edge you see in the beginning
        // (this is needed so you could plot the last red dot, walk through the code on the graph to understand why)
        multiset<int> current_left_edges;
        current_left_edges.insert(0);

        // Interest points (the red dots) to be returned.
        vector<vector<int>> interest_points_xy;

        int previous_max_left_edge = 0, current_max_left_edge = 0;
        for (auto height : heights) {
            if (height[1] < 0) {
                // If we are seeing a left edge, insert that into our current left edge.
                current_left_edges.insert(-height[1]);
            } else {
                // Otherwise if we are seeing a right edge, that means the building is over,
                // erase the corresponding left edge.
                current_left_edges.erase(current_left_edges.find(height[1]));
            }

            current_max_left_edge = *current_left_edges.rbegin();

            // Whenever current max is different from previous max, an interest point exists.
            // This is always true. Walk through the code on the graph to understand.
            if (current_max_left_edge != previous_max_left_edge) {
                interest_points_xy.push_back({height[0], current_max_left_edge});
                previous_max_left_edge = current_max_left_edge;
            }
        }

        return interest_points_xy;
    }
};
