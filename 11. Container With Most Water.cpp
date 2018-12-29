// ***
//
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// ***
//
// Start by evaluating the widest container, using the first and the last line.
// All other possible containers are less wide, so to hold more water,
// the short edge of the container needs to be higher than current short edge.
// Note we don't change the current high edge, since the container size is determined only by the short edge.
// We try to find new containers whose width is shorter but short edge is higher than previous short edge.
// and compare that container size with our maxVal, repeat until there are no more possible containers left.
//
int maxArea(vector<int>& height)
{

	int maxVal = 0;
	int curVal = 0;

	int left = 0;
	int right = height.size() - 1;

	while (left < right)
	{
		curVal = min(height[left], height[right]) * (right - left);

		maxVal = max(curVal, maxVal);

		height[left] < height[right] ? ++left : --right;
	}

	return maxVal;
}
