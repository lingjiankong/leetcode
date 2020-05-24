// ***
//
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
// find the area of largest rectangle in the histogram.
//
// ***

// Maintain a monotonic increasing stack (which stores the index) of bar height.
// In the process of popping elements which are greater than current heights[i], we do our calculation of maxArea.
// See also 42. Trapping Rain Water. Sister question.
int largestRectangleArea(vector<int>& heights) {
    // push_back 0 so in the case of [1 2 3 4 5] we have a chance in the end to trigger stack popping and do our
    // calculation, otherwise we will end up just keep pushing element into the stack without returning any result.
    heights.push_back(0);

    stack<int> heightIndexStack;

    int maxArea = 0;

    int i = 0;
    while (i < heights.size()) {
        // < and <= all work here.
        // Whenever we see higher height, simply push the height to the stack.
        if (heightIndexStack.empty() || heights[heightIndexStack.top()] < heights[i]) {
            heightIndexStack.push(i++);
        }
        // Whenever we see lower height, this triggers our calculation of max areas.
        // Pop all elements which are higher than current height[i], in the mean time calculate rectangle area whose
        // height is the highest height that just been popped from the stack (see comments for what the width is).
        else {
            // Index of current highest bar.
            int currentHighestIndex = heightIndexStack.top();
            heightIndexStack.pop();

            // Why i - heightIndexStack.top() - 1?
            // We are interested in the area of the rectangle whose height is heights[currentHighestIndex].
            // The rectangle's left bound is heights[heightIndexStack.top()] (which is smaller than
            // heights[currentHighestIndex] since we have a monotonically increasing stack). The rectangle's right bound
            // is heights[i] (which is also smaller than heights[currentHightestIndex], otherwise you wouldn't enter the
            // else loop at all). The width of the rectangle is therefore i (right bound) - heightIndexStack.top() (left
            // bound) - 1. For exmaple, Consider i = 18, currentHighestIndex = 17, and heightIndexStack.top() = 16.
            // The width of the rectangle whose height is heights[currentHighestIndex], is 18 - 16 - 1 = 1, which is
            // just the width of the bar heights[currentHighestIndex] itself.
            //
            // Why rectangleWidth = i when heightIndexStack.empty()?
            // When the stack is empty, it means we have never seen any bar that is lower than heights[i], as a result,
            // there is no left bound (same as saying its left bound has index of 0) on the rectangle formed whose
            // height is heights[currentHighestIndex]. Its width is bounded only by its right bound, which is
            // heights[i]. Therefore, the width is i - 0 = i
            int rectangleWidth = heightIndexStack.empty() ? i : i - heightIndexStack.top() - 1;

            int rectangleHeight = heights[currentHighestIndex];

            int currentArea = rectangleHeight * rectangleWidth;
            maxArea = max(maxArea, currentArea);
        }
    }

    return maxArea;
}

// Same method. Cleaner code.
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> heightIndexStack;
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i) {
        while (!heightIndexStack.empty() && heights[heightIndexStack.top()] >= heights[i]) {
            int currentHighestIndex = heightIndexStack.top();
            heightIndexStack.pop();

            int rectangleWidth = heightIndexStack.empty() ? i : i - heightIndexStack.top() - 1;
            int rectangleHeight = heights[currentHighestIndex];
            int currentArea = rectangleHeight * rectangleWidth;
            maxArea = max(maxArea, currentArea);
        }

        heightIndexStack.push(i);
    }

    return maxArea;
}
