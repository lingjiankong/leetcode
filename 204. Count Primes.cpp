// ***
//
// Count the number of prime numbers less than a non-negative number, n.
// 
// Example:
// 
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
// ***
//
// See image here: http://www.cnblogs.com/grandyang/p/4462810.html
// The idea is, if num[i] is a prime number, then it multiples are non-prime number.
// i.e. nums[i] is prime, but num[i * i], nums[i * i * i] ... are non-prime.
int countPrimes(int n)
{
	// Stores whether i is a prime number or not.
	vector<bool> num(n, true);

	// Number 0 and 1 is neither prime nor non-prime.
	num[0] = false;
	num[1] = false;

	int numOfPrimes = 0;
	int limit = sqrt(n);

	for (int i = 2; i <= limit; ++i)
	{
		if (num[i])
		{
			for (int j = i * i; j <= n - 1; j += i)
			{
				num[j] = false;
			}
		}
	}

	for (int j = 2; j < n; ++j)
	{
		if (num[j])
		{
			++numOfPrimes;
		}
	}

	return numOfPrimes;
}
