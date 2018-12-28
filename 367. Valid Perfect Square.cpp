// ***
//
// Given a positive integer num, write a function which returns True if num is a perfect square else False.
// Note: Do not use any built-in library function such as sqrt.
// 
// Example 1:
// 
// Input: 16
// Output: true
// 
// Example 2:
// 
// Input: 14
// Output: false
//
// ***
bool isPerfectSquare(int num)
{
	for (int i = 1; i <= num / i; ++i)
	{
		if (i * i == num)
		{
			return true;
		}
	}

	return false;
}

// Another method, find the first x such that x * x is less than num, this defines the upper bound of our serach.
// Our range of search for square root of num must between x (since x * x < num) and 2x (since (2x) * (2x) > num).
bool isPerfectSquare(int num)
{
	if (num == 1)
	{
		return true;
	}

	long x = num / 2;

	while (x * x > num)
	{
		x /= 2;
	}

	for (int i = x; i <= 2 * x; ++i)
	{
		if (i * i == num)
		{
			return true;
		}
	}

	return false;
}
