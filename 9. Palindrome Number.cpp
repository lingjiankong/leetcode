// The idea is to reverse the integer and compare the reversed with the original.
// To visualize the while loop:
//
// Example:
// 36425
//
// reversed = 0 (initialize);
//
// reversed = reversed * 10 + x % 10;
// reversed = 0 * 10 + 36425 % 10
// reversed = 5
//
// x /= 10
// x = 36425 / 10 = 3642
//
// reversed = reversed * 10 + x % 10;
// reversed = 5 * 10 + 3642 % 10
// reversed = 52
//
// x /= 10
// x = 3642 / 10 = 364
// 
// reversed = reversed * 10 + x % 10;
// reversed = 52 * 10 + 364 % 10
// reversed = 524
//
// x /= 10
// x = 364 / 10 = 36
// ...
//
// reversed will eventually be 52463
//
bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}

	int original = x;
	int reversed = 0;

	while (x != 0)
	{
		reversed = reversed * 10 + x % 10;
		x /= 10;
	}

	return reversed == original;
}
