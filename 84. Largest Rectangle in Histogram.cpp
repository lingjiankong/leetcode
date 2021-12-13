// ***
//
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
// find the area of largest rectangle in the histogram.
//
// ***

// Maintain a monotonic increasing stack (which stores the index) of bar height.
// In the process of popping elements which are greater than current heights[i], we do our calculation of maxArea.
//               .
//             . .
//           . . .
//         | . . .
//       | | . . .
//     | | | . . . I
//   | | | | . . . I
// | | | | | . . . I
//           <--->
//           width
//                 ^
//                 i
//
//           ^
//           curHeighestIdx
//
//         ^
//         s.top() after curHeighestIdx is popped()
//
// Dotted bar are those that have been popped.
//
// See also 42. Trapping Rain Water. Sister question.
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            int curHeighestIdx = s.top();
            s.pop();

            int width = s.empty() ? i : i - s.top() - 1;
            int height = heights[curHeighestIdx];
            int area = height * width;
            maxArea = max(maxArea, area);
        }

        s.push(i);
    }

    return maxArea;
}

// Detailed explanation:
int largestRectangleArea(vector<int>& heights) {
    // push_back 0 so in the case of [1 2 3 4 5] we have a chance in the end to trigger stack popping and do our
    // calculation, otherwise we will end up just keep pushing element into the stack without returning any result.
    heights.push_back(0);

    stack<int> s;

    int maxArea = 0;

    int i = 0;
    while (i < heights.size()) {
        // < and <= all work here.
        // Whenever we see higher height, simply push the height to the stack.
        if (s.empty() || heights[s.top()] < heights[i]) {
            s.push(i++);
        }
        // Whenever we see lower height, this triggers our calculation of max areas.
        // Pop all elements which are higher than current height[i], in the mean time calculate rectangle area whose
        // height is the highest height that just been popped from the stack (see comments for what the width is).
        else {
            // Index of current highest bar.
            int curHeighestIdx = s.top();
            s.pop();

            // Why i - s.top() - 1?
            // We are interested in the area of the rectangle whose height is heights[curHeighestIdx].
            // The rectangle's left bound is heights[s.top()] (which is smaller than
            // heights[curHeighestIdx] since we have a monotonically increasing stack). The rectangle's right bound
            // is heights[i] (which is also smaller than heights[currentHightestIndex], otherwise you wouldn't enter the
            // else loop at all). The width of the rectangle is therefore i (right bound) - s.top() (left
            // bound) - 1. For exmaple, Consider i = 18, curHeighestIdx = 17, and s.top() = 16.
            // The width of the rectangle whose height is heights[curHeighestIdx], is 18 - 16 - 1 = 1, which is
            // just the width of the bar heights[curHeighestIdx] itself.
            //
            // Why width = i when s.empty()?
            // When the stack is empty, it means we have never seen any bar that is lower than heights[i], as a result,
            // there is no left bound (same as saying its left bound has index of 0) on the rectangle formed whose
            // height is heights[curHeighestIdx]. Its width is bounded only by its right bound, which is
            // heights[i]. Therefore, the width is i - 0 = i
            int width = s.empty() ? i : i - s.top() - 1;

            int height = heights[curHeighestIdx];

            int area = height * width;
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}
