// ***
//
// Find the total area covered by two rectilinear rectangles in a 2D plane.
//
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure, i.e.
// (A, B): bottom left corner of rectangle 1
// (C, D): top right corner of rectangle 1
// (E, F): bottom left corner of rectangle 2
// (G, H): top right corner of rectangle 2
//
// Rectangle Area
//
// Example:
//
// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
// Output: 45
//
// ***
//
// Just draw the rectangle and visualize difference cases.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum1 = (C - A) * (D - B), sum2 = (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) {
            return sum1 + sum2;
        }
        return sum1 - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))) + sum2;
    }
};
