// ***
//
// Write an algorithm to determine if a number is "happy".
// 
// A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum of the squares of its digits,
// and repeat the process until the number equals 1 (where it will stay),
// or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy numbers.
// 
// Example:
// 
// Input: 19
// Output: true
// Explanation:
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1
//
// ***
//
// Maintain an unordered_set to keep track which number you have seen.
// If you have seen a number then it means you are in an infinite loop.
bool isHappy(int n)
{
	unordered_set<int> seen;

	while (n != 1)
	{
		int currentSum = 0;
		while (n)
		{
			currentSum += pow(n % 10, 2);
			n /= 10;
		}
		n = currentSum;

		if (seen.count(n))
		{
			break;
		}
		else
		{
			seen.insert(n);
		}
	}

	return n == 1;
}
