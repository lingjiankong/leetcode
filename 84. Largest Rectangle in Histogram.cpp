// ***
//
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
// find the area of largest rectangle in the histogram.
//
// ***
//
// Maintain a monotonic increasing stack (which stores the index) of histogram.
// In the process of popping elements which are greater than current heights[i], we do our calculation of maxArea.
// See also 42. Trapping Rain Water. Sister question.
int largestRectangleArea(vector<int>& heights)
{
	// push_back 0 so in the case of [1 2 3 4 5] we can also go to the else loop to calculate.
	heights.push_back(0);

	stack<int> heightStack;

	int maxArea = 0;

	int i = 0;
	while (i < heights.size())
	{
		// > and >= all work here.
		if (heightStack.empty() || heights[i] > heights[heightStack.top()])
		{
			heightStack.push(i++);
		}
		// Popping all elements which are bigger than current height[i],
		// in the mean time do our calculation.
		else
		{
			// Index of current highest histogram.
			int currentHeightestIndex = heightStack.top(); heightStack.pop();	
		
			// Why i - heightStack.top() - 1?
			// Say now i = 18 and heights[18] is very small, you entered the else loop
			// you've just popped the currentHeightestIndex (currentHeightestIndex = 17)
			// Here you top the remaining height stack (heightStack.top() = 16)
			// Obviously, the width of the rectangle represented by heights[currentHeightestIndex] is 18 - 16 - 1 = 1.
			int rectangleWidth = heightStack.empty() ? i : i - heightStack.top() - 1;

			int rectangleHeight = heights[currentHeightestIndex];

			int currentArea = rectangleHeight * rectangleWidth;
			maxArea = max(maxArea, currentArea);
		}
	}

	return maxArea;
}
