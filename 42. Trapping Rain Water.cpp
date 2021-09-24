// ***
//
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
//
// ***
//
// Think about the wall and water as individual blocks (width = 1).
// We only consider the amount of water we can fill at that single position.
//
//             *
//             *
//             *                  *
//             *                  *
//         *   *                  *
// *     * *   * *                *
// * *   * *   * * *        *  *  *
// 0 1 2 3 4 5 6 7 8 10 ... 97 98 99
// ^                              ^
// L                              R

// DP solution, very intuitive.
// For current position i, keep track of its left max height and right max height.
int trap(vector<int>& height) {
    if (height.empty()) {
        return 0;
    }

    vector<int> leftMaxHeight(height.size(), 0);
    vector<int> rightMaxHeight(height.size(), 0);

    for (int i = 1; i < height.size(); ++i) {
        leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i - 1]);
    }

    for (int j = height.size() - 2; j >= 0; --j) {
        rightMaxHeight[j] = max(rightMaxHeight[j + 1], height[j + 1]);
    }

    int totalWater = 0;
    for (int i = 1; i < height.size() - 1; ++i) {
        int minHeight = min(leftMaxHeight[i], rightMaxHeight[i]);
        totalWater += min(0, minHeight - height[i]);
    }

    return totalWater;
}

// Maintain two pointers left and right, we keep track of the maximum height of left wall and right wall.
// The amount of water we can fill at certain position is controlled by:
// 1. The height at current position,
// 2. Minimum of (max height of walls to the left, max height of walls to the right)
int trap(vector<int>& height) {
    int totalWater = 0;

    int left = 0, right = height.size() - 1;
    int leftMaxHeight = height[left], rightMaxHeight = height[right];

    while (left < right) {
        leftMaxHeight = max(leftMaxHeight, height[left]);
        rightMaxHeight = max(rightMaxHeight, height[right]);

        if (leftMaxHeight < rightMaxHeight) {
            totalWater += leftMaxHeight - height[left];
            ++left;
        } else {
            totalWater += rightMaxHeight - height[right];
            --right;
        }
    }

    return totalWater;
}

// See also 84. Largest Rectangle In Histogram. Very similar.
// Maintain a monotonic decreasing stack (which stores the *index*) of bars.
// Whenever we see a higher bar we might be able to form a valley to store water.
// In the process of popping elements which are smaller than current height[i], we do our calculation.
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int totalWater = 0;

        for (int i = 0; i < height.size(); ++i) {
            while (not s.empty() and height[s.top()] <= height[i]) {
                int curValleyIdx = s.top();
                s.pop();

                // No left bar, can't hold any water.
                if (s.empty()) {
                    break;
                }

                // i is the index of right bar.
                // The valley has already been popped.
                // Current top of the stack is the index of left bar.
                int rectangleWidth = i - s.top() - 1;
                int rectangleHeight = min(height[s.top()], height[i]) - height[curValleyIdx];
                totalWater += rectangleHeight * rectangleWidth;
            }

            // Nothing in the stack is higher than height[i]. Push i to stack.
            s.push(i);
        }

        return totalWater;
    }
};
