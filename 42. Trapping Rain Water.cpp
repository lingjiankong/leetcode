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
//
// DP solution, very intuitive.
// For current position i, keep track of its left max height and right max height.
int trap(vector<int>& height)
{
	if (height.empty())		 
	{
		return 0;
	}

	vector<int> leftMaxHeight(height.size(), 0);
	vector<int> rightMaxHeight(height.size(), 0);

	for (int i = 1; i < height.size(); ++i)
	{
		leftMaxHeight[i] = max(leftMaxHeight[i-1], height[i-1]);
	}

	for (int j = height.size() - 2; j >= 0; --j)
	{
		rightMaxHeight[j] = max(rightMaxHeight[j+1], height[j+1]);
	}

	int maxWater = 0;
	for (int i = 1; i < height.size() - 1; ++i)
	{
		int minHeight = min(leftMaxHeight[i], rightMaxHeight[i]);
		maxWater += min(0, minHeight - height[i]);
	}

	return maxWater;
}

// Maintain two pointers left and right, we keep track of the maximum height of left wall and right wall.
// The amount of water we can fill at certain position is controlled by:
// 1. The height at current position,
// 2. Minimum of (max height of walls to the left, max height of walls to the right)
int trap(vector<int>& height)
{

	int total = 0;

	// Well, you can think of leftMaxHeight = height[left] and rightMaxHeight = height[right]
	// We assign 0 to them simply because we don't have to check the size of the vector.
	// leftMaxHeight and rightMaxHeight will be assigned once we enter the while loop.
	// Otherwise we would need to make sure height.size() != 0.
	int leftMaxHeight = 0;
	int rightMaxHeight = 0;

	int left = 0;
	int right = height.size() - 1;

	while (left < right)
	{
		leftMaxHeight = max(leftMaxHeight, height[left]);
		rightMaxHeight = max(rightMaxHeight, height[right]);

		if (leftMaxHeight < rightMaxHeight)
		{
			total += leftMaxHeight - height[left];
			++left;
		}
		else
		{
			total += rightMaxHeight - height[right];
			--right;
		}
	}

	return total;
}

// Using stack
// TODO: Unfinished
int trap(vector<int>& height)
{
	stack<int> heightStack;

	for (int i = 0; i < height.size(); ++i)
	{
		if (heightStack.empty() || height[i] <= height[heightStack.top()])	
		{
			heightStack.push(i);
		}
		else
		{
				
		}
	}

}
