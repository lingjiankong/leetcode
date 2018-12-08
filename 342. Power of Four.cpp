// ***
//
// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
// ***
bool isPowerOfFour(int num)
{
	while (num && (num % 4 == 0))
	{
		num /= 4;
	}

	return num == 1;
}
