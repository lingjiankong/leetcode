// ***
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
// Find the minimum element.
// 
// The array may contain duplicates.
// 
// Example 1:
// 
// Input: [1,3,5]
// Output: 1
// 
// Example 2:
// 
// Input: [2,2,2,0,1]
// Output: 0
//
// ***
//
// For these kinds of binary search problems, where there's a sorted array rotated at some unknown pivot, AND
// there exists duplicate element in the array, the method is the same.
// Look at the if, else if, and else loop to get the intuition.
int findMin(vector<int> &num)
{
    int left = 0, right = num.size() - 1;
    
    while (left < right)
    {    
        int mid = left + (right - left) / 2;

        // In this case, the pivot is on the right half of the array.
        if (num[mid] > num[right])
        {
            left = mid + 1;
        }
		// In this case, the pivot is on the left half of the array.
        else if (num[mid] < num[right])
        {
            right = mid;
        }
		else
		{
			--right;
		}
    }

    return num[right];
};
