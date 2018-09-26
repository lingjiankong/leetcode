// Start by evaluating the widest container, using the first and the last line. 
// All other possible containers are less wide, so to hold more water, the short edge of the container needs to be higher than current short edge. 
// Note we don't change the current high edge, since the container size is determined only by the short edge. 
// We try to find new containers whose width is shorter but short edge is higher than previous short edge 
// and compare that container size with our maxVal, repeat until there are no more possible containers left

class Solution 
{

	public:

		int maxArea(vector<int>& height) 
		{

			int maxVal = 0;
			int curVal = 0;

			int left = 0;
			int right = height.size() - 1;

			while (left < right) 
			{

				if (height[left] < height[right])
				{
					curVal = (right-left) * height[left];
					++left;
				}
				else
				{
					curVal = (right-left) * height[right];
					--right;
				}

				maxVal = max(maxVal, curVal);
			}

			return maxVal;
		}

};
