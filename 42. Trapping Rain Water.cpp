// Think about the wall and water as individual blocks (width = 1). 
// We only consider the amount of water we can fill at that single position.

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

// Maintain two pointers left and right, we keep track of the maximum height of left wall and right wall. 
// The amount of water we can fill at certain position is controlled by: 
// 1. The height at current position, 
// 2. Minimum of (max height of walls to the left, max height of walls to the right)

// Let say now L = 0 and R = 99, the first time we enter the while loop, think about height[99] (i.e. height[right]) 
// being very high, say, higher than height[left] at position from 0, 1, 2, 3, 4, 5, then we enter if (height[left] < height[right]) every time, 
// and the amount of water we can fill at position 0 to 5 is completely determined by leftMaxHeight - height[left] 
// (since height[right], which will later become rightMaxHeight, is always greater than leftMaxHeight;
// The right side  will never be the constraint (i.e. shorter edge never happens on the right side)).

// Let's say at position 6, height[left] (which is height[6]) becomes super large, larger than current height[right], 
// then the condition height[left] >= height[right] is true and we enter the else loop. 
// Now, height[right] (height[99]) is assigned to rightMaxHeight.
// Also note, leftMaxHeight, which will later become the super large height[6], will be greater than this rightMaxHeight. 
// Thus, the same theory applies here: now the left side is never going to be the constraint, 
// and now the amount of water we can fill is completely determined by rightMaxHeight - height[right].

// The process repeats, L pointer going right, R pointer going left, 
// until they overlap is when we've finished calculating the amount of water we can fill at all positions

// Things to keep in mind: if height[left] < height[right], then also leftMaxHeight < rightMaxHeight, 
// meaning the amount of water we can fill at current height[left] can be determined only using 
// leftMaxHeight - height[left]. Same is true vice versa if height[left] >= height[right].

class Solution
{

	public:
		
		int trap(vector<int>& height)
		{

			int left = 0;
			int right = height.size() - 1;

			// Well, you can think of leftMaxHeight = height[left] and rightMaxHeight = height[right]
			// We assign 0 to them just simply because we don't need to check the size of the vector.
			// Otherwise we would need to make sure height.size() != 0.
			int leftMaxHeight = 0;
			int rightMaxHeight = 0;

			int total = 0;

			while (left < right)
			{
				if (height[left] < height[right])
				{
					leftMaxHeight = max(leftMaxHeight, height[left]);
					total += leftMaxHeight - height[left];
					++left;
				}
				else
				{
					rightMaxHeight = max(rightMaxHeight, height[right]);
					total += rightMaxHeight - height[right];
					--right;
				}
			}

			return total;
		}

};
