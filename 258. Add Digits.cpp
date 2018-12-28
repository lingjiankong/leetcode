// ***
//
// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
// 
// Example:
// 
// Input: 38
// Output: 2
//
// Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
//
// ***
int addDigits(int num)
{
	// Perform the operation as long as num is not a single digit
	while (num / 10 > 0)
	{
		int sum = 0;

		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}

		num = sum;
	}

	return num;
}
