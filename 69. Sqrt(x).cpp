// ***
//
// Implement int sqrt(int x).
// 
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// 
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
// 
// Example 1:
// 
// Input: 4
// Output: 2
//
// Example 2:
// 
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
//
// ***
//
// Binary search to find the last element that is not greater than the target element.
// In this case, the target element is x / mid, and we want to find the last element that isn't greater than it
// Hence we return right - 1. If we return right, it is the first element that is greater than target.
// See a summary of binary search here: http://www.cnblogs.com/grandyang/p/6854825.html
int mySqrt(int x)
{
	if (x <= 1)
	{
		return x;
	}

	int left = 0, right = x;

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (mid <= x / mid)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	// right is the first element that is greater than target;
	// right - 1 is the last element that is not greater than target;
	return right - 1;
}
