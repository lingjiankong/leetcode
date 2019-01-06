// ***
//
// Given an integer, write a function to determine if it is a power of two.
// 
// Example 1:
// Input: 1
// Output: true
// Explanation: 20 = 1
//
// Example 2:
// Input: 16
// Output: true
// Explanation: 24 = 16
//
// Example 3:
// Input: 218
// Output: false
//
// ***
//
// In binary representation, all power of two must only has one 1.
//
// 1    2     4     8     16 　　....
// 1    10    100   1000  10000　....
bool isPowerOfTwo(int n)
{
	int numberOfOne = 0;

	while (n > 0)
	{
		numberOfOne += (n & 1);
		n >>= 1;
	}
	
	return numberOfOne == 1;
}
