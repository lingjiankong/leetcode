// ***
//
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of
// water (blue section) the container can contain is 49. Example 2:
//
// Example 2:
// Input: height = [1,1]
// Output: 1
//
//
// Example 3:
// Input: height = [4,3,2,1,4]
// Output: 16
//
//
// Example 4:
// Input: height = [1,2,1]
// Output: 2
//
//
// Constraints:
//
// n == height.length
// 2 <= n <= 10^5
// 0 <= height[i] <= 10^4
//
// ***
//
// Start by evaluating the widest container, using the first and the last vertical lines. All other possible containers
// are less wide, so in order to hold more water, the short edge of the container needs to be higher than current short
// edge. Note we don't change the current high edge, since the container size is determined only by the short edge. We
// try to find new containers whose width is shorter but short edge is higher than previous short edge, and compare that
// container size with our maxArea, repeat until there are no more possible containers left.

int maxArea(vector<int>& height) {
    int maxArea = 0;
    int curArea = 0;

    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        curArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, curArea);
        height[left] < height[right] ? ++left : --right;
    }

    return maxArea;
}
